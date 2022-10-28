import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class CaisaAndSugar {

	public static void main(String args[] ) throws Exception {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	        
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int n = ip(st1.nextToken());
		int s = ip(st1.nextToken());
	    
		int ans = -1;
		
		for(int i=0;i<n;i++){
			StringTokenizer st2 = new StringTokenizer(br.readLine());
			int x = ip(st2.nextToken());
			int y = ip(st2.nextToken());
			if(y == 0){
				if(s>=x)
					ans =Math.max(ans, 0);
			}
			else{
				if(s > x)
					ans = Math.max(ans, 100 -y);
			}
		}
		
		w.println(ans);
	    
	    w.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}