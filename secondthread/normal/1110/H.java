import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class _GlobalRound1H {
	
	static int wordLength;
	static PrintWriter out=new PrintWriter(System.out);
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		char[] lLine=fs.next().toCharArray(), rLine=fs.next().toCharArray();
		wordLength=fs.nextInt();
		int lLen=lLine.length, rLen=rLine.length;
		int[] L=new int[lLen], R=new int[rLen];
		for (int i=0; i<lLen; i++) L[i]=lLine[i]-'0';
		for (int i=0; i<rLen; i++) R[i]=rLine[i]-'0';
		
		ArrayList<Word> words=new ArrayList<>();
		if (lLen==rLen) {
			//then there is some LCP which need to be in everything
			ArrayList<Integer> lcpList=new ArrayList<>();
			for (int i=0; lcpList.size()<lLen && L[i]==R[i]; i++)
				lcpList.add(L[i]);
			if (lcpList.size()==lLen) {
				words.add(new Word(lcpList));
			}
			else {
				//after the LCP there is one digit bounded by both
				for (int toPlace=L[lcpList.size()]+1; toPlace<R[lcpList.size()]; toPlace++) {
					int suffLen=lLen-1-lcpList.size();
					words.add(new Word(lcpList, toPlace, suffLen));
				}
			
				//after that one digit, each is only bounded by one
				ArrayList<Integer> leftPref=(ArrayList<Integer>) lcpList.clone(), rightPref=lcpList;
				leftPref.add(L[lcpList.size()]);
				rightPref.add(R[lcpList.size()]);
				for (int i=lcpList.size(); i<lLen; i++) {
					int suffLen=lLen-1-i;
					for (int toPlace=L[i]+1; toPlace<=9; toPlace++)
						words.add(new Word(leftPref, toPlace, suffLen));
					leftPref.add(L[i]);
				}
				words.add(new Word(leftPref));
				for (int i=lcpList.size(); i<rLen; i++) {
					int suffLen=rLen-1-i;
					for (int toPlace=R[i]-1; toPlace>0; toPlace--)
						words.add(new Word(rightPref, toPlace, suffLen));
					rightPref.add(R[i]);
				}
				words.add(new Word(rightPref));
			}
		}
		else {
			ArrayList<Integer> pref=new ArrayList<>();
			for (int i=0; i<lLen; i++) {
				int suffLen=lLen-1-i;
				for (int toPlace=L[i]+1; toPlace<=9; toPlace++)
					words.add(new Word(pref, toPlace, suffLen));
				pref.add(L[i]);
			}
			words.add(new Word(L));
			pref.clear();
			for (int i=0; i<rLen; i++) {
				int suffLen=rLen-1-i;
				for (int toPlace=R[i]-1; toPlace>0; toPlace--)
					words.add(new Word(pref, toPlace, suffLen));
				pref.add(R[i]);
			}
			words.add(new Word(R));
			for (int length=lLen+1; length<rLen; length++) {
				ArrayList<Integer> empty=new ArrayList<>();
				for (int toPlace=1; toPlace<=9; toPlace++)
					words.add(new Word(empty, toPlace, length-1));
			}
			
		}
		
		AhoNode aho=new AhoNode();
		for (Word w:words) aho.addWord(w, 0);
		
		AhoNode.buildAho(aho);
		int answer=aho.go(0);
		
		out.println(answer);
		aho.buildback(0);
		out.println();
		out.close();
	}
	
	static class Word {
		int[] req;
		int suffLen;
		
		public Word(int[] req) {
			this.suffLen=0;
			this.req=req.clone();
		}
		
		public Word(ArrayList<Integer> reqList) {
			this.suffLen=0;
			req=new int[reqList.size()];
			for (int i=0; i<req.length; i++)
				req[i]=reqList.get(i);
		}
		
		public Word(ArrayList<Integer> pref, int nextLetter, int suffLen) {
			this.suffLen=suffLen;
			req=new int[pref.size()+1];
			for (int i=0; i+1<req.length; i++) req[i]=pref.get(i);
			req[pref.size()]=nextLetter;
		}
		
		public String toString() {
			return Arrays.toString(req)+" * "+suffLen;
		}
	}
	
	static class AhoNode {
		AhoNode[] transition=new AhoNode[10];
		AhoNode[] children=new AhoNode[10];
		AhoNode suffixLink=null;
		
		int[] tailLengths=new int[801];
		int[] csTailLengths=new int[802];
		
		int[] dp=new int[2002];
		
		public AhoNode() {
			Arrays.fill(dp, -1);
		}
		
		public void addWord(Word w, int index) {
			if (index==w.req.length) {
				tailLengths[w.suffLen]++;
				return;
			}
			
			if (children[w.req[index]]==null) children[w.req[index]]=new AhoNode();
			children[w.req[index]].addWord(w, index+1);
		}
		
		static void buildAho(AhoNode root) {
			ArrayDeque<AhoNode> bfs=new ArrayDeque<>();
			bfs.add(root);
			root.suffixLink=root;
			Arrays.fill(root.transition, root);
			while (!bfs.isEmpty()) {
				AhoNode node=bfs.remove(), suffLink=node.suffixLink;
				//TODO: update tailLengths
				if (node!=root) {
					for (int i=0; i<node.tailLengths.length; i++)
						node.tailLengths[i]+=suffLink.tailLengths[i];
				}
				for (int i=1; i<node.csTailLengths.length; i++)
					node.csTailLengths[i]=node.csTailLengths[i-1]+node.tailLengths[i-1];
				
				for (int kid=0; kid<10; kid++) {
					if (node.children[kid]!=null) {
						node.transition[kid]=node.children[kid];
						bfs.add(node.children[kid]);
						node.children[kid].suffixLink=(node==root?node:suffLink.transition[kid]);
					}
					else {
						node.transition[kid]=suffLink.transition[kid];
					}
				}
			}
		}
		
		int go(int curLength) {
			if (dp[curLength]!=-1) return dp[curLength];
			if (curLength==wordLength) return dp[curLength]=tailLengths[0];
			//otherwise brute force what to place
			
			int spaceLeft=Math.min(wordLength-curLength, 800);
			int getFree=csTailLengths[spaceLeft+1];
			int best=getFree;
			for (int toPlace=0; toPlace<10; toPlace++) {
				best=Math.max(best, getFree+transition[toPlace].go(curLength+1));
			}
			return dp[curLength]=best;
		}
		
		void buildback(int curLength) {
			if (curLength==wordLength) return;
			//otherwise brute force what to place
			
			int spaceLeft=Math.min(wordLength-curLength, 800);
			int getFree=csTailLengths[spaceLeft+1];
			for (int toPlace=0; toPlace<10; toPlace++) {
				if (getFree+transition[toPlace].go(curLength+1) == go(curLength)) {
					out.print(toPlace);
					transition[toPlace].buildback(curLength+1);
					return;
				}
			}
		}
	}
	
	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");
		
		public String next() {
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
		
		public long nextLong() {
			return Long.parseLong(next());
		}
		
		public int[] readArray(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++) {
				a[i]=nextInt();
			}
			return a;
		}
		
		public double nextDouble() {
			return Double.parseDouble(next());
		}
		
	}

}