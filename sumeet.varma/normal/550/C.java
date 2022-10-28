import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class R306qC {

	public static void main(String args[] ) throws Exception {
		   
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	    
	    char s[] = br.readLine().toCharArray();
	    int n = s.length;
	    
	    
	    for(int i=0;i<n;i++){
	    	if(s[i] == '8' || s[i] == '0'){
	    		System.out.println("YES");
	    		System.out.println(s[i]);
	    		return;
	    	}
	    }
	    
	    
	    int i1 = -1,i2 = -1;
	    
	    for(int i=0;i<n;i++){
	    	for(int j=i+1;j<n;j++){
	    		if(s[i] != '0' && (10 * (s[i] - '0') + (s[j] - '0')) % 8 == 0){
	    			i1 = i;
	    			i2 = j;
	    		}
	    	}
	    }
	    
	    if(i1 != -1){
	    	System.out.println("YES");
	    	System.out.print(s[i1]);
	    	System.out.print(s[i2]);
	    	return;
	    }
	   
	    
	    for(int i=0;i<n;i++){
	    	for(int j=i+1;j<n;j++){
	    		for(int k=j+1;k<n;k++){
	    			int num = 100 * (s[i] - '0') + 10 * (s[j] - '0') + (s[k] - '0');
	    			if(num % 8 == 0 && s[i] != '0'){
	    				System.out.println("YES");
	    				System.out.print((char)s[i]);
	    				System.out.print((char)s[j]);
	    				System.out.print((char)s[k]);
	    				return;
	    			}
	    		}
	    	}
	    }
	    
	    System.out.println("NO");
	    w.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
	
}