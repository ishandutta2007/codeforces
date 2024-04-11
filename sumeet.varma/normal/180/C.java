import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;


public class R116qCLetter {

	public static void main(String args[] ) throws Exception {
		   
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	    
	    char s[] = br.readLine().toCharArray();
	     
	    int count[] = new int[s.length + 1];
	    for(int i=s.length-1;i>=0;i--)
	    	count[i] = count[i+1] + (s[i] < 'a' ? 1 : 0);
	    
	    int ans = count[0];
	    int here = 0;
	    
	    for(int i=0;i<s.length;i++){
	    	if(s[i] >= 'a')	here++;
	    	ans = Math.min(ans, here + count[i+1]);
	    }
	    
	    w.println(ans);
	    w.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
	
}