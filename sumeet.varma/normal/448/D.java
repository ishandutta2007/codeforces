import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class R256QDMultiplicationTable {

	static long n,m,k;
	
	public static void main(String args[] ) throws Exception {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	        
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    n = ip(st1.nextToken());
	    m = ip(st1.nextToken());
		k = Long.parseLong(st1.nextToken());
	          
	    w.println(bS(1,n*m,k));
	    w.close(); 
	}
	
	public static long bS(long start,long end,long k) {
	
		while(true){
			
			//System.out.println(start + " " + end);
		
			long mid = (start + end) / 2;
			
			long count = 0;
			long smaller = 0;
			
			for(int i=1;i<=n;i++){
				if(mid % i == 0)
					smaller += Math.min(m,mid/i-1);
				else
					smaller += Math.min(m,mid/i);
				if(mid % i == 0 && mid/i <= m)
					count++;
			}
			
			if(count == 0){
				if(smaller < k)
					start = mid+1;
				else
					end = mid-1;
			}
			else{
				if(k >= smaller + 1 && k<=smaller +count)
					return mid;
				if(k > smaller)
					start = mid+1;
				else
					end = mid-1;
			}
		}

	}
	
	public static int bSAdvanced(int start,int end,long i,long key){
		int ret = 0;
		while(true){
			if(start == end)	return ret;
			int mid = (start + end)/2;
			if(i*mid < key)	ret = mid;
			if(end - start == 1)	return ret;
			if(i*mid < key)	start = mid + 1;
			else	end = mid;
		}
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}