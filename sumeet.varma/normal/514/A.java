import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class Round291Div2TaskA {

	public static void main(String args[] ) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	        
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    char a[] = st1.nextToken().toCharArray();
	    StringBuilder ans = new StringBuilder("");     
	    int t1 = Character.getNumericValue(a[0]);
	    if(t1==9)
	    	ans.append('9');
	    else
	    	ans.append(Math.min(t1, 9-t1));
	    for(int i=1;i<a.length;i++){
	    	int t = Character.getNumericValue(a[i]);
	    	ans.append(Math.min(t, 9-t));
	    }
	    
	    w.println(ans);
	    w.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}