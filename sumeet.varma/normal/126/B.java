import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;

public class R93qBPassword {

	public static void main(String args[] ) throws Exception {
		   
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	    
	    char s[] = br.readLine().toCharArray();
	    int z[] = zFunction(s);    
	    int n = s.length;
	    
	    int ans = 0;
	    
	    int max[] = new int[n];
	    for(int i=1;i<n;i++)
	    	max[i] = Math.max(max[i-1], z[i]);
	    
	    for(int i=1;i<n;i++)
	    	if(z[i] + i == n && max[i-1] >= z[i])
	    		ans = Math.max(ans, z[i]);
	    
	    w.println(ans == 0 ? "Just a legend" : new String(s).substring(0, ans));
	    w.close(); 
	}
	
	public static int[] zFunction(char pat[]){
		int n = pat.length;
		int z[] = new int[n];
		
		int l = 0,r = 0;
		for(int i=1;i<n;i++){
			if(i > r){
				l = r = i;
				while(r < n && pat[r-l] == pat[r]) r++;
				z[i] = r - l;
				r--;
			}
			else{
				int k = i - l;
				if(z[k] < r - i + 1)	z[i] = z[k];
				else{
					l = i;
					while(r < n && pat[r-l] == pat[r]) r++;
					z[i] = r - l;
					r--;
				}
			}
		}
		
		z[0] = 0;
		return z;
	}
	
}