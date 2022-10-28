import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;


public class R57qEEnemyIsWeak {

	static int n;
	static Node a[],b[];
	static long segtree[];
	
	
	public static void main(String args[] ) throws Exception {
		   
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	    
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    n = ip(st1.nextToken());
		
	    StringTokenizer st2 = new StringTokenizer(br.readLine());
	    a = new Node[n];
	    for(int i=0;i<n;i++)
	    	a[i] = new Node(i,ip(st2.nextToken()));
	        
	    Arrays.sort(a);
	    
	    segtree = new long[4*n];
	    b = new Node[n];
	    
	    for(int i=0;i<n;i++){
	    	b[i] = new Node(a[i].idx,(int)find(0,n-1,0,a[i].idx,n-1));
	    	update(0,n-1,0,a[i].idx,1);
	    }
	
	    long ans = 0;
	    segtree = new long[4*n];
	    
	    for(int i=0;i<n;i++){
	    	ans += find(0,n-1,0,b[i].idx,n-1);
	    	update(0,n-1,0,b[i].idx,b[i].val);
	    }
	    
	    w.println(ans);
	    w.close(); 
	}
	
	public static long find(int s,int e,int c,int l,int r){
		if(s == l && e == r)	return segtree[c];
		int m = (s + e) >> 1;
	    if(l <= m && r <= m)	return find(s,m,2*c+1,l,r);
	    if(l > m && r > m)		return find(m+1,e,2*c+2,l,r);
	    return find(s,m,2*c+1,l,m) + find(m+1,e,2*c+2,m+1,r);
	}
	
	public static void update(int s,int e,int c,int x,long v){
		segtree[c] += v;
		if(s == e)	return;
		int m = (s + e) >> 1;
		if(x <= m)	update(s,m,2*c+1,x,v);
		else		update(m+1,e,2*c+2,x,v);
	}
	
	static public class Node implements Comparable<Node>{
		int idx,val;
		Node(int i,int v){
			idx = i;
			val = v;
		}
		public int compareTo(Node o){
			return Integer.compare(val, o.val);
		}
		public String toString(){
			return idx + " " + val +  " ";
		}
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}