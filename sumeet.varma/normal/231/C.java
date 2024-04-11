import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;


public class R143qCToAddOrNotToAdd {

	static int a[];
	static long pre[];
	
	public static void main(String args[] ) throws Exception {
		   
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	    
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int n = ip(st1.nextToken());
		int k = ip(st1.nextToken());
	          
	    StringTokenizer st2 = new StringTokenizer(br.readLine());
	    a = new int[n];
	    for(int i=0;i<n;i++)
	    	a[i] = ip(st2.nextToken());// + (int)(1e9+1);
	        
	    Arrays.sort(a);
	    
	    pre = new long[n];
	    for(int i=0;i<n;i++)	pre[i] = (i == 0) ? a[0] : (pre[i-1] + a[i]);
	    
	    int val = 0,count = 0;
	    
	    for(int i=0;i<n;i++){
	    	int now = i - bSFirst(0,i+1,i,k) + 1;
	    	//System.out.println(a[i] + " " + bSFirst(0,i+1,i,k));
	    	if(now > count){
	    		val = a[i];
	    		count = now;
	    	}
	    }
	    
	    w.println(count + " " + val);
	    w.close(); 
	}
	
	public static int bSFirst(int s,int e,int i,int k){
		int ret = -1,m;
		while(s < e){
			m = (s + e) >> 1;
			long sum = pre[i] - (m == 0 ? 0 : pre[m-1]);
			long need = (i - m + 1) * 1L * a[i];
			if(need - sum <= k)	ret = e = m;
			else				s = m + 1;
		}
		return ret;
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}