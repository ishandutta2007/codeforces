import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class RoadConstruction {

	public static void main(String args[] ) throws Exception {
		   
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	    
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int n = ip(st1.nextToken());
		int m = ip(st1.nextToken());
	         
		boolean no[] = new boolean[n+1];
		for(int i=0;i<m;i++){
			StringTokenizer st2 = new StringTokenizer(br.readLine());
			int u = ip(st2.nextToken());
			int v = ip(st2.nextToken());
			no[u] = true;
			no[v] = true;
		}
		
		int root = -1;
		
		for(int i=1;i<=n;i++)
			if(!no[i])
				root = i;
		
		if(root == -1)
			throw new Exception();
		
		w.println(n-1);
		for(int i=1;i<=n;i++){
			if(i!=root)
				w.println(i + " " + root);
		}
	    
	    w.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}