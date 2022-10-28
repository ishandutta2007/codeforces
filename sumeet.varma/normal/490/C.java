import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class HackingCypher {

	public static void main(String args[] ) throws Exception {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	       
	    String in = br.readLine();
	    
	    char x[] = in.toCharArray();
	    int n = x.length;
	    
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int a = ip(st1.nextToken());
	    int b = ip(st1.nextToken());
	          
	    int rema[] = new int[n];
	    rema[0] = Character.getNumericValue(x[0]) % a;
	         
	    for(int i=1;i<n;i++)
	    	rema[i] = (10 * rema[i-1] + Character.getNumericValue(x[i])) % a;
	    
	    int remb[] = new int[n];
	    remb[n-1] = Character.getNumericValue(x[n-1]) % b;
	    
	    int p = 10 % b;
	    
	    for(int i=n-2;i>=0;i--){
	    	remb[i] = (p * Character.getNumericValue(x[i]) + remb[i+1]) % b;
	    	p = (p * 10) % b;
	    }
	    
	    int ans = -1;
	    
	    for(int i=0;i<n-1;i++){
	    	//System.out.println(rema[i] + " " + remb[i+1]);
	    	if(rema[i] == 0 && remb[i+1] == 0 && x[i+1]!='0')
	    		ans = i;
	    }
	    
	    if(ans == -1)
	    	w.println("NO");
	    else{
	    	w.println("YES");
	    	for(int j=0;j<=ans;j++)
	    		w.print(x[j]);
	    	w.println();
	    	for(int j=ans+1;j<n;j++)
	    		w.print(x[j]);
	    	w.println();
	    }
	    w.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}