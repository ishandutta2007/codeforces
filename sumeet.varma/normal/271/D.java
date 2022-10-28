import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;

public class R166qDGoodSubstrings {

	static int ALPHA = 26;
	
	public static void main(String args[] ) throws Exception {
		   
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	    
	    char s[] = br.readLine().toCharArray();
	    char good[] = br.readLine().toCharArray();
	    int k = ip(br.readLine());
	    
	    int n = s.length;
	    
	    Trie trie = new Trie();
	    
	    for(int i=0;i<n;i++){
	    	int bad = 0;
	    	for(int j=i;j<n;j++){
	    		if(good[s[j]-'a'] == '0')	bad++;
	    		if(bad == k+1){
	    			trie.add(trie.root,s,i,j);
	    			break;
	    		}
	    	}
	    	if(bad != k+1)
	    		trie.add(trie.root,s,i,n);
	    }
	    
	    w.println(trie.unique);
	    w.close(); 
	}
	
	static public class Trie{
		
		int unique;
		TrieNode root;
		Trie(){
			unique = 0;
			root = new TrieNode();
			root.isLeaf = true;
		}
		
		public void add(TrieNode curr,char a[],int pos,int len){
			if(!curr.isLeaf)	unique++;
			curr.isLeaf = true;
			if(pos == len)	return;
			if(curr.child[a[pos]-'a'] == null)
				curr.child[a[pos]-'a'] = new TrieNode();
			add(curr.child[a[pos]-'a'],a,pos+1,len);
		}
		
	}
	
	static public class TrieNode{
		boolean isLeaf;
		TrieNode child[];
		TrieNode(){
			isLeaf = false;
			child = new TrieNode[ALPHA];
		}
	}
	
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
	
}