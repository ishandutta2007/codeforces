import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class R260qDALotOfGames {

	public static void main(String args[] ) throws Exception {
		   
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	    
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int n = Integer.parseInt(st1.nextToken());
		int k = Integer.parseInt(st1.nextToken());
	    
		Trie trie = new Trie();
		
		for(int i=0;i<n;i++){
			trie.in = br.readLine().toCharArray();
			trie.add();
		}
		
		boolean canWin = trie.tryWin(trie.root);
	
		if(!canWin){
			System.out.println("Second");
			return;
		}
		
		boolean canLose = trie.tryLose(trie.root);
		
		if(canLose){
			System.out.println("First");
			return;
		}
		
		System.out.println(k % 2 == 1 ? "First" : "Second");
		
	    w.close(); 
	}
	
	static public class Trie{
		
		TrieNode root;
		char in[];
		
		Trie(){	root = new TrieNode(); }
	
		public void add(){
			TrieNode curr = root;
			for(int i=0;i<in.length;i++){
				if(curr.child[in[i]-'a'] == null)
					curr.child[in[i]-'a'] = new TrieNode();
				curr = curr.child[in[i]-'a'];
			}
		}
		
		public boolean tryWin(TrieNode curr){
			boolean canWin = false;
			for(int i=0;i<26 && !canWin;i++)
				if(curr.child[i] != null && tryWin(curr.child[i]) == false)
					canWin = true;
			return canWin;
		}
		
		public boolean tryLose(TrieNode curr){
			boolean canLose = true;
			for(int i=0;i<26 && canLose;i++)
				if(curr.child[i] != null)
					canLose = false;
			for(int i=0;i<26 && !canLose;i++)
				if(curr.child[i] != null && tryLose(curr.child[i]) == false)
					canLose = true;
			return canLose;
		}
	
	}
	
	static public class TrieNode{
		TrieNode child[];
		TrieNode(){	
			child = new TrieNode[26]; }
	}
}