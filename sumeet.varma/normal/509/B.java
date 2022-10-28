import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;


public class PaintingPebbles {

	public static void main(String args[] ) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	        
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int n = ip(st1.nextToken());
	    int k = ip(st1.nextToken());
	          
	    StringTokenizer st2 = new StringTokenizer(br.readLine());
	    int a[] = new int[n];
	    for(int i=0;i<n;i++)
	    	a[i] = ip(st2.nextToken());
	         
	    int used[][] = new int[n][k];
	    for(int i=0;i<n;i++){
	    	int all = a[i] / k;
	    	Arrays.fill(used[i], all);
	    	for(int j=0;j<a[i]%k;j++)
	    		used[i][j]++;
	    }
	    
	    for(int i=0;i<n;i++){
	    	for(int j=i+1;j<n;j++){
	    		for(int l=0;l<k;l++){
	    			if(Math.abs(used[i][l] - used[j][l]) > 1){
	    				System.out.println("NO");
	    				return;
	    			}
	    		}
	    	}
	    }
	    
	    w.println("YES");
	    for(int i=0;i<n;i++){
	    	for(int j=0;j<k;j++){
	    		for(int t = 0;t<used[i][j];t++)
	    			w.printf("%d ",j+1);
	    	}
	    	w.println();
	    }
	    w.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}

}