import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class R25qCRoadsInBerland {

	public static void main(String args[] ) throws Exception {
		   
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	    
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int n = ip(st1.nextToken());
		
	    long dist[][] = new long[n][n];
	    for(int i=0;i<n;i++){
	    	StringTokenizer st = new StringTokenizer(br.readLine());
	    	for(int j=0;j<n;j++)
	    		dist[i][j] = ip(st.nextToken());
	    }
	    
	    int k = ip(br.readLine());
	          
	    for(int i=0;i<k;i++){
	    	StringTokenizer st2 = new StringTokenizer(br.readLine());
	    	int a = ip(st2.nextToken()) - 1;
	    	int b = ip(st2.nextToken()) - 1;
	    	int c = ip(st2.nextToken());
	    	long sum = 0;
	    	for(int x=0;x<n;x++){
	    		for(int y=0;y<n;y++){
	    			dist[x][y] = Math.min(dist[x][y], dist[x][a] + c + dist[b][y]);
	    			dist[x][y] = Math.min(dist[x][y], dist[x][b] + c + dist[a][y]);
	    			sum += dist[x][y];
	    		}
	    	}
	    	w.print(sum/2);
	    	w.print(" ");
	    }
	    
	    w.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}