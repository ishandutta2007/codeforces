import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class VK12R2qCStringManipulation {

	static int id;
	static int segtree[][];
	static int len[];
	
	public static void main(String args[] ) throws Exception {
		   
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	    
	    int k = Integer.parseInt(br.readLine());
	    char s[] = br.readLine().toCharArray();
	    int m = s.length;
	    int n = k*m;
	    
	    boolean removed[] = new boolean[n];
	   
	    @SuppressWarnings("unchecked")
		ArrayList<Integer> occur[] = new ArrayList[26];
	    for(int i=0;i<26;i++)
	    	occur[i] = new ArrayList<Integer>();
	    for(int i=0;i<n;i++)
	    	occur[s[i%m] - 'a'].add(i);
	    
	    len = new int[26];
	    for(int i=0;i<26;i++)
	    	len[i] = occur[i].size();
	    
	    segtree = new int[26][];
	    for(id=0;id<26;id++){
	    	if(occur[id].isEmpty())	continue;
	    	segtree[id] = new int[4*len[id]];
	    	build(0,len[id]-1,0);
	    }
	    int q = Integer.parseInt(br.readLine());
	    
	    while(q-- > 0){
	    	StringTokenizer st = new StringTokenizer(br.readLine());
	    	int idx = Integer.parseInt(st.nextToken());
	    	id = st.nextToken().charAt(0) - 'a';
	    	int pos = find(0,len[id] - 1,0,idx);
	    	removed[occur[id].get(pos)] = true;
	    	update(0,len[id]-1,0,pos);
	    }
	    
	    for(int i=0;i<n;i++)
	    	if(!removed[i])
	    		w.print(s[i%m]);
	    
	    w.println();
	    w.close(); 
	}
	
	public static void build(int s,int e,int c){
		segtree[id][c] = e - s + 1;
		if(s == e)
			return;
		int m = (s + e) >> 1;
	    build(s,m,2*c+1);
	    build(m+1,e,2*c+2);
	}
	
	public static void update(int s,int e,int c,int x){
		segtree[id][c]--;
		if(s == e)	return;
		int m = (s + e) >> 1;
	    if(x <= m)
	    	update(s,m,2*c+1,x);
	    else
	    	update(m+1,e,2*c+2,x);
	}
	
	public static int find(int s,int e,int c,int k){
		if(s == e)
			return s;
		int m = (s + e) >> 1;
	    int left = count(0,len[id]-1,0,s,m);
	    if(k <= left)
	    	return find(s,m,2*c+1,k);
	    else
	    	return find(m+1,e,2*c+2,k-left);
	}
	
	public static int count(int s,int e,int c,int l,int r){
		if(s == l && e == r)
			return segtree[id][c];
		int m = (s + e) >> 1;
		if(l <= m && r <= m)
			return count(s,m,2*c+1,l,r);
		if(l > m && r > m)
			return count(m+1,e,2*c+2,l,r);
		return count(s,m,2*c+1,l,m) + count(m+1,e,2*c+2,m+1,r);
			
	}
	
}