import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class TaskCRound291Div2 {

	public static void main(String args[] ) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	        
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int n = ip(st1.nextToken());
	    
	    long count[] = new long[10];
	    char a[] = br.readLine().toCharArray();
	    for(int i=0;i<n;i++){
	    	count[a[i]-'0']++;
	    }
	    
	    count[2] += 2*count[4];
	    count[3] += count[4];
	    count[4] = 0;
	    
	    count[5] += count[6];
	    count[3] += count[6];
	    count[6] = 0;
	    
	    count[2] += 3*count[8];
	    count[7] += count[8];
	    count[8] = 0;
	    
	    count[2] += count[9];
	    count[3] += 2*count[9];
	    count[7] += count[9];
	    count[9] = 0;
	    
	    StringBuilder ans = new StringBuilder("");
	    for(int i=9;i>=2;i--){
	    	for(int j=0;j<count[i];j++)
	    		ans.append(i);
	    }
	    
	    w.println(ans);
	    w.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}