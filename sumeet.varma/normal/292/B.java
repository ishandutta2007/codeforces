import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

	
public class NetWorkTopology {

	public static void main(String args[] ) throws Exception {
		   
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	    
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int n = ip(st1.nextToken());
		int m = ip(st1.nextToken());
	         
		int count[] = new int[n+1];
		
		for(int i=0;i<m;i++){
			StringTokenizer st2 = new StringTokenizer(br.readLine());
			int x = ip(st2.nextToken());
			int y = ip(st2.nextToken());
			count[x]++;
			count[y]++;
		}
		
		int single = 0,other = -1;
		
		for(int i=1;i<=n;i++){
			if(count[i] == 0){
				System.out.println("unknown topology");
				return;
			}
			if(count[i] == 1)
				single++;
			else
				other = count[i];
		}
		
		if(single == n-1 && other == n-1){
			System.out.println("star topology");
			return;
		}
		
		int two = 0;
		for(int i=1;i<=n;i++)
			if(count[i] == 2)
				two++;
		
		if(two == n-2 && single == 2){
			System.out.println("bus topology");
			return;
		}
		
		if(two == n && single == 0){
			System.out.println("ring topology");
			return;
		}
			
	    System.out.println("unknown topology");
	    
	    w.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
	
}