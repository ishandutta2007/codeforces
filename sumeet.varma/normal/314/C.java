import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class R187qCSerejaAndSubsequences {

	static final int MAX = (int)(1e6 + 1);
	static int a[];
	static long hash[],segtree[];
	static int n;
	static final long MOD = (long)(1e9 + 7);
	
	public static void main(String args[] ) throws Exception {
		   
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	    
	    n = ip(br.readLine());
	          
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    a = new int[n];
	    for(int i=0;i<n;i++)
	    	a[i] = ip(st1.nextToken());
	    
	    hash = new long[MAX];
	    segtree = new long[4*MAX];
	    	    
	    for(int i=0;i<n;i++){
	    	long prev = find(0,MAX-1,0,0,a[i]-1);
	    	long curr = hash[a[i]];
	    	long thisAns = prev*a[i] + 1000*MOD;
	    	thisAns %= MOD;
	    	thisAns += curr * a[i] + a[i];
	    	thisAns %= MOD;
	    	long upd = thisAns - curr + 1000*MOD;
	    	upd %= MOD;
	    	update(0,MAX-1,0,a[i],upd);
	    }
	 
	    long ans = find(0,MAX-1,0,0,MAX-1);
	    w.println(ans);
	    w.close(); 
	}
	
	public static void update(int s,int e,int c,int x,long upd){
		//System.out.println(s + " " + e + " " + c);
		segtree[c] += upd;
		segtree[c] %= MOD;
		if(s == e){
			hash[x] += upd;
			hash[x] %= MOD;
			return;
		}
		int m = (s + e) >> 1;
	    if(x <= m)	
	    	update(s,m,2*c+1,x,upd);
	    else
	    	update(m+1,e,2*c+2,x,upd);
	}
	
	public static long find(int s,int e,int c,int l,int r){
		//System.out.println(s + " " +e + " " + c + " " + l + " " + r);
		if(s == l && e == r)
			return segtree[c] % MOD;
		int m = (s + e) >> 1;
	    if(l <= m && r <= m)
	    	return find(s,m,2*c+1,l,r);
	    else if(l > m && r > m)
	    	return find(m+1,e,2*c+2,l,r);
	    else
	    	return ((find(s,m,2*c+1,l,m) + find(m+1,e,2*c+2,m+1,r)) % MOD);
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}