import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class R249QBPashaMzximizes {

	@SuppressWarnings("unused")
	public static void main(String args[] ) throws Exception {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	        
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    long n = Long.parseLong(st1.nextToken());
		int k = ip(st1.nextToken());
	          
		int c = k;
		char a[] = Long.toString(n).toCharArray();
	    for(int i=0;i<a.length-1;i++){
	    	int mi = i + 1;
	    	for(int j=i+1;j<=i+c && j<a.length;j++){
	    		if(v(a[j]) > v(a[mi])){
	    			mi = j;
	    		}
	    	}
	    	if(v(a[mi]) > v(a[i]) && c!=0){
	    		c -= mi - i;
	    		for(int j=mi;j>i;j--){
	    			char t = a[j];
	    			a[j] = a[j-1];
	    			a[j-1] = t;
	    		}
	    	}
	    	
	    }
	    
	    w.println(new String(a));
	    w.close(); 
	}
	
	public static int v(char c){
		return c - '0';
	}
	public static int ip(String s){
		return Integer.parseInt(s);
	}
	
}