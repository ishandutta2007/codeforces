import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;


public class R258D2TaskAGameWithSticks {

	public static void main(String args[] ) throws Exception {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	        
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int n = ip(st1.nextToken());
		int m = ip(st1.nextToken());
		
		boolean ans = false;
		if(n == m){
			if(n % 2 == 0)
				ans = false;
			else
				ans = true;
		}
		if(n < m){
			if(n % 2 == 0)
				ans = false;
			else
				ans = true;
		}
		if(m < n){
			if(m % 2 ==0)
				ans = false;
			else
				ans = true;
		}
		
		w.print(ans == true ? "Akshat" : "Malvika");
	    w.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}