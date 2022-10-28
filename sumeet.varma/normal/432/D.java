import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;

public class R246qDPrefixesAndSuffixes {

	public static void main(String args[] ) throws Exception {
		   
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	    
	    char s[] = br.readLine().toCharArray();
	    int n = s.length;
	    
	    int z[] = new int[n];
	    zFunction(s,z,n);    
	    z[0] = n;
	    
	    int count = 0;
	    for(int i=0;i<n;i++)
	    	if(z[i] == (n - i))
	    		count++;
	    
	    int z2[] = new int[n + 1];
	    for(int i=0;i<n;i++)
	    	z2[z[i]]++;
	    for(int i=n-1;i>=0;i--)
	    	z2[i] += z2[i+1];
	    
	    w.println(count);
	    
	    for(int i=n-1;i>=0;i--)
	    	if(z[i] == (n-i))
	    		w.println((n-i) + " " + z2[n-i]);
	    
	    w.close(); 
	}
	
	public static void zFunction(char s[],int z[],int n){
		int L = 0, R = 0;
		for (int i = 1; i < n; i++) {
		  if (i > R) {
		    L = R = i;
		    while (R < n && s[R-L] == s[R]) R++;
		    z[i] = R-L; R--;
		  } else {
		    int k = i-L;
		    if (z[k] < R-i+1) z[i] = z[k];
		    else {
		      L = i;
		      while (R < n && s[R-L] == s[R]) R++;
		      z[i] = R-L; R--;
		    }
		  }
		}
	}
	
}