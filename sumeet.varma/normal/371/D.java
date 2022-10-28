import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class R218qDVessels {

	static long oo = (long)(1e17);
	static long a[],p[];
	static int next[];
	
	public static void main(String args[] ) throws Exception {
		   
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	    
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int n = ip(st1.nextToken());
	    
	    StringTokenizer st2 = new StringTokenizer(br.readLine());
	    a = new long[n+1];
	    for(int i=0;i<n;i++)
	    	a[i] = ip(st2.nextToken());
	    a[n] = oo;
	    
	    next= new int[n+1];
	    for(int i=0;i<=n;i++)
	    	next[i] = i;
	    
	    p = new long[n+1];
	    	
	    int m = ip(br.readLine());
	    for(int i=0;i<m;i++){
	    	StringTokenizer st3 = new StringTokenizer(br.readLine());
	    	int type = ip(st3.nextToken());
	    	int idx = ip(st3.nextToken()) - 1;
	    	if(type == 1)
	    		update(next[idx],ip(st3.nextToken()));
	    	else
	    		w.println(p[idx]);
	    }
	    w.close(); 
	}
	
	public static int update(int idx,long val){
		if(p[idx] + val <= a[idx]){
			p[idx] += val;
			return idx;
		}
		else{
			next[idx] = update(next[idx+1],val - (a[idx] - p[idx]));
			p[idx] = a[idx];
			return next[idx];
		}
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}