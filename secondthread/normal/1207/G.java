import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class AhoOnTrie {
	
	static BIT treeState;

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int nSongs=fs.nextInt();
		TrieNode[] songs=new TrieNode[nSongs+1];
		songs[0]=new TrieNode();
		for (int i=1; i<=nSongs; i++) {
			int type=fs.nextInt();
			int parent=type==1?0:fs.nextInt();
			char added=fs.next().charAt(0);
			TrieNode newNode=songs[parent].add(added);
			songs[i]=newNode;
		}
		int nQueries=fs.nextInt();
		String[] queryStrings=new String[nQueries];
		Query[] queries=new Query[nQueries];
		for (int qq=0; qq<nQueries; qq++) {
			int node=fs.nextInt();
			String queryString=fs.next();
			queryStrings[qq]=queryString;
			songs[node].queriesAtNode.add(queries[qq]=new Query(qq, queryString));
		}
		AhoCorasick.createAhoCorasick(queryStrings);
		
		//make sLink tree
		Node[] sLinkTree=new Node[AhoCorasick.nodeCount];
		for (int i=0; i<sLinkTree.length; i++) sLinkTree[i]=new Node();
		for (int i=1; i<sLinkTree.length; i++) {
			int par=AhoCorasick.suffixLink[i];
			sLinkTree[par].children.add(sLinkTree[i]);
		}
		sLinkTree[0].dfs(-1);
		treeState=new BIT(sLinkTree[0].postorderNumber+1);
		
		songs[0].answerDFS(0, sLinkTree);
		
		PrintWriter out=new PrintWriter(System.out);
		for (int i=0; i<nQueries; i++)
			out.println(queries[i].ans);
		out.close();
	}
	
	static class Query {
		int queryNumber;
		String queryWord;
		int ans;
		public Query(int queryNumber, String queryWord) {
			this.queryNumber=queryNumber;
			this.queryWord=queryWord;
		}
	}
	
	//trie given as input
	static class TrieNode {
		TrieNode[] adj=new TrieNode[26];
		ArrayList<Query> queriesAtNode=new ArrayList<>();
		
		TrieNode add(char c) {
			int ind=c-'a';
			if (adj[ind]==null) adj[ind]=new TrieNode();
			return adj[ind];
		}
		
		void answerDFS(int ahoIndex, Node[] sLinkTree) {
			//increment the number of times this node has been visited 
			Node sLinkNode=sLinkTree[ahoIndex];
			treeState.rangeUpdate(0, sLinkNode.preorderNumber, 1);
			
			//answer all queries at this node
			for (Query q:queriesAtNode) {
				//TODO: answer
				int curAhoNode=0;
				for (char c:q.queryWord.toCharArray())
					curAhoNode=AhoCorasick.transition[c-'a'][curAhoNode];
				Node querySLinkNode=sLinkTree[curAhoNode];
				int ans=treeState.pointQuery(querySLinkNode.preorderNumber)-treeState.pointQuery(querySLinkNode.postorderNumber);
				q.ans=ans;
			}
			
			//go to all children, changing the aho index
			for (int kid=0; kid<26; kid++) {
				if (adj[kid]==null) continue;
				adj[kid].answerDFS(AhoCorasick.transition[kid][ahoIndex], sLinkTree);
			}
			
			//decrement the number of times this node has been visited
			treeState.rangeUpdate(0, sLinkNode.preorderNumber, -1);
		}
	}
	
	//tree node for aho s-links
	static class Node {
		ArrayList<Node> children=new ArrayList<>();
		int preorderNumber, postorderNumber;
		public int dfs(int preNumber) {
			this.preorderNumber=++preNumber;
			for (Node n:children) {
				preNumber=n.dfs(preNumber);
			}
			this.postorderNumber=++preNumber;
			return preNumber;
		}
	}
	
	//builds aho for query strings
	static class AhoCorasick {
		static final int ALPHA = 26;
		static int nodeCount, transition[][];
		static int[] suffixLink;
		static boolean[] term;
		static void createAhoCorasick(String[] strs) {
			int maxNodes = 1;
			for(String s : strs) maxNodes += s.length();

			int[][] children = new int[ALPHA][maxNodes];
			boolean[] leaf = new boolean[maxNodes];
			nodeCount = 1;
			for(String s : strs) {
				int node = 0;
				for(char ch : s.toCharArray()) {
					int c = ch - 'a';
					if(children[c][node] == 0) children[c][node] = nodeCount++;
					node = children[c][node];
				}
				leaf[node] = true;
			}

			transition = new int[ALPHA][nodeCount];
			term = new boolean[nodeCount];
			suffixLink=new int[nodeCount];

			ArrayDeque<Integer> queue = new ArrayDeque<>();
			queue.add(0);  queue.add(0);

			while(queue.size() > 0) {
				int node = queue.remove(), suffLink = queue.remove();
				suffixLink[node]=suffLink;

				term[node] = leaf[node] || term[suffLink];

				for(int ch = 0; ch < ALPHA; ch++) {
					if(children[ch][node] != 0){
						transition[ch][node] = children[ch][node];
						queue.add(children[ch][node]);
						queue.add(node == 0 ? 0 : transition[ch][suffLink]);
					} else  transition[ch][node] = transition[ch][suffLink];
				}
			}
		}
	}
	
	//for tree updates
	static class BIT {
		int n;
		int[] tree;
		
		public BIT(int n) {
			this.n = n;
			tree = new int[n + 5];
		}
		
		int read(int i) {
			i++;
			int sum = 0;
			while (i > 0) {
				sum += tree[i];
				i -= i & -i;
			}
			return sum;
		}
		
		void update(int i, int val) {
			i++;
			while (i <= n) {
				tree[i] += val;
				i += i & -i;
			}
		}
		
		void rangeUpdate(int from, int to, int delta) {
			update(from, delta);
			update(to+1, -delta);
		}
		
		int pointQuery(int i) {
			return read(i);
		}

		// if the BIT is a freq array, returns the
		// index of the kth item, or n if there are fewer
		// than k items.
		int getKth(int k) {
			int e=Integer.highestOneBit(n), o=0;
			for (; e!=0; e>>=1) {
				if (e+o<=n && tree[e+o]<=k) {
					k-=tree[e+o];
					o+=e;
				}
			}
			return o;
		}
		
	}


	
	static class FastScanner {
		StringTokenizer st=new StringTokenizer("");
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		String next() {
			while (!st.hasMoreElements())
				try {
					st=new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			return st.nextToken();
		}
		
		public int nextInt() {
			return Integer.parseInt(next());
		}
	}
}