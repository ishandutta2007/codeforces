import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class R210qBLevkoAndPermutation {

	public static void main(String args[] ) throws Exception {
		   
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	    
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int n = ip(st1.nextToken());
		int k = ip(st1.nextToken());
	    k = n - k;      
		
		if(k == 0)
			w.println(-1);
		else{
			for(int i=2;i<=k;i++)
				w.print(i + " ");
			w.print("1 ");
			for(int i=k+1;i<=n;i++)
				w.print(i + " ");
		}
	    
	    
	    
	    w.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}