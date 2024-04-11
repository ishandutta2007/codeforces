import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class R132qDHotDays {

	public static void main(String args[] ) throws Exception {
		   
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	    
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int n = ip(st1.nextToken());
		int m = ip(st1.nextToken());
	    
		long ans = 0;
		
		for(int i=0;i<n;i++){
			StringTokenizer st2 = new StringTokenizer(br.readLine());
			int t = ip(st2.nextToken());
			int T = ip(st2.nextToken());
			int x = ip(st2.nextToken());
			int cost = ip(st2.nextToken());
			
			int k = T - t;
			
			long res1 = Long.MAX_VALUE;
			long res2 = res1;
			
			res1 = (long)m * x;
            if(m <= k)
                res1 = 0;
            res1 += cost;

            if(k > 0) {
                // min buses
                int minB = (m + k - 1) / k;
                if(minB > 1)
                    res2 = (long)minB * cost;
            }

            ans += Math.min(res1, res2);
		}
	    
		w.println(ans);
		w.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
	
}