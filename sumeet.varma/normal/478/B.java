import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class RandomTeams {

	public static void main(String args[] ) throws Exception {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	        
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int n = ip(st1.nextToken());
	    int m = ip(st1.nextToken());
	    
	    int team1 = n - (m-1);
	    long kmax = (1L * team1 * (team1 - 1)) / 2;
	    
	    long mod = n % m;
	    long eachteam = n/m;
	    
	    long kmin = (eachteam * (eachteam-1) * m)/ 2;
	    kmin += eachteam * mod;
	    
	    w.print(kmin + " " + kmax);
	    w.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
	
}