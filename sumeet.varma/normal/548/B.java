import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class R305taskC {

	public static void main(String args[] ) throws Exception {
		   
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	    
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int n = ip(st1.nextToken());
		int m = ip(st1.nextToken());
	    int q = ip(st1.nextToken());     
		
	    int a[][] = new int[n][m];
	    
	    for(int i=0;i<n;i++){
	    	StringTokenizer st2 = new StringTokenizer(br.readLine());
	    	for(int j=0;j<m;j++)
	    		a[i][j] = ip(st2.nextToken());
	    }
	    
	    int ans[] = new int[n];
	    int temp[][] = new int[n][m];
	    for(int i=0;i<n;i++){
	    	for(int j=0;j<m;j++){
	    		if(a[i][j] == 1)
	    			temp[i][j] = 1 + ((j == 0) ? 0 : temp[i][j-1]);
	    		ans[i] = Math.max(ans[i], temp[i][j]);
	    	}
	    }
	    
	    for(int x=0;x<q;x++){
	    	StringTokenizer st = new StringTokenizer(br.readLine());
	    	int c = ip(st.nextToken()) - 1;
	    	int d = ip(st.nextToken()) - 1;
	    	a[c][d] = 1 - a[c][d];
	    	ans[c] = 0;
	    	for(int j=0;j<m;j++){
	    		if(a[c][j] == 1)
	    			temp[c][j] = 1 + ((j == 0) ? 0 : temp[c][j-1]);
	    		else
	    			temp[c][j] = 0;
	    		ans[c] = Math.max(ans[c], temp[c][j]);
	    	}
	    	int orange = 0;
	    	for(int i=0;i<n;i++)
	    		orange = Math.max(orange, ans[i]);
	    	w.println(orange);
	    }
	    
	    w.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
	
}