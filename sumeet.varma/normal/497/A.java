import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class RemovingColumns {

	public static void main(String args[] ) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	        
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int n = ip(st1.nextToken());
	    int m = ip(st1.nextToken());
	          
	    char a[][] = new char[n][m];
	    for(int i=0;i<n;i++)
	    	a[i] = br.readLine().toCharArray();
	    
	    boolean colRem[] = new boolean[m];
	    int ans = 0;
	    for(int j=0;j<m;j++){
	    //	System.out.println(breaks(a,j,colRem,n));
	    	if(breaks(a,j,colRem,n)){
	    		colRem[j] = true;
	    		ans++;
	    	}
	    }
	    
	    w.println(ans);
	    w.close(); 
	}
	
	
	public static boolean breaks(char a[][],int col,boolean colRem[],int n){
		String checks[] = new String[n];
		
		for(int i=0;i<n;i++)
			checks[i] = new String("");
		
		for(int i=0;i<n;i++){
			for(int j=0;j<=col;j++){
				if(colRem[j]!=true)
					checks[i] += a[i][j];
			}
		}
		
		for(int i=0;i<n-1;i++){
			//System.out.println(checks[i] + " " + checks[i+1]);
			if(checks[i].compareTo(checks[i+1]) > 0 )	
				return true;
		}
		
		return false;
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}