import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class R300qB {

	public static void main(String args[] ) throws Exception {
		   
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	    
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int n = ip(st1.nextToken());
		
	    char s[] = Integer.toString(n).toCharArray();
	    int len = s.length;
	    int max = 0;
	    for(int i=0;i<len;i++)
	    	max = Math.max(s[i] - '0', max);
	    
	    char ans[][] = new char[max][len];
	    for(int i=0;i<max;i++)
	    	for(int j=0;j<len;j++)
	    		ans[i][j] = '0';
	    
	    for(int i=0;i<len;i++){
	    	for(int j=0;j<s[i]-'0';j++)
	    		ans[j][i] = '1';
	    }
	    
	    w.println(max);
	    for(int i=0;i<max;i++)
	    	w.print(ip(new String(ans[i])) + " ");
	    
	    w.close(); 
	    
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}