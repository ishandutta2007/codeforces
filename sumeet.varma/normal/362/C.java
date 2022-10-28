import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class R212qCInserstionSort {
	
	public static void main(String args[] ) throws Exception {
		   
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	    
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int n = ip(st1.nextToken());
	          
	    StringTokenizer st2 = new StringTokenizer(br.readLine());
	    int a[] = new int[n];
	    for(int i=0;i<n;i++)
	    	a[i] = ip(st2.nextToken());
	    
	    int orange[][] = new int[n][n];
	    for(int i=0;i<n;i++){
	    	for(int j=i+1;j<n;j++){
	    		orange[i][j] = orange[i][j-1];
	    		if(a[j] > a[i])
	    			orange[i][j]++;
	    	}
	    }
	    
	    for(int i=n-1;i>=0;i--){
	    	for(int j=i-1;j>=0;j--){
	    		orange[i][j] = orange[i][j+1];
	    		if(a[j] < a[i])
	    			orange[i][j]++;
	    	}
	    }
	    int dec = 0,pairs = 0;
	    
	    for(int i=0;i<n;i++){
	    	for(int j=i+1;j<n;j++){
	    		if(a[i] > a[j]){
	    			int between = ( j - i - 1) - (orange[i][j-1] + orange[j][i+1]);
	    			int curr = 1 + 2*between;
	    			if(curr == dec)
	    				pairs++;
	    			if(curr > dec){
	    				dec = curr;
	    				pairs = 1;
	    			} 
	    		}
	    	}
	    	
	    }
	    
	    int swaps = 0;
	    for (int i = 1; i < n; i = i + 1){
	       int j = i; 
	       while (j > 0 && a[j] < a[j - 1])
	       {
	    	  int t = a[j];
	    	  a[j] = a[j-1];
	    	  a[j-1] = t;
	          swaps++; // swap elements a[j] and a[j - 1]
	          j = j - 1;
	       }
	    }
	  
	    w.println((swaps - dec) + " " + pairs);
	    w.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}