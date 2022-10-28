import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;

public class CountingSticks {

	public static void main(String args[] ) throws Exception {
		   
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	    
	    String inp = br.readLine().trim();
	    int n[] = new int[3];
	    int curr = 0;
	    
	    for(int i=0;i<inp.length();i++){
	    	if(inp.charAt(i) == '|')
	    		n[curr]++;
	    	else
	    		curr++;
	    }
	    
	    int a = n[0];
	    int b = n[1];
	    int c = n[2];
	    
	    if(a + b == c);
	    else if(a + b + 1 == c - 1){
	    	a++;
	    	c--;
	    }
	    else if(a + b - 1 == c + 1){
	    	if(a != 1)
	    		a--;
	    	else if(b != 1)
	    		b--;
	    	c++;
	    }
	    
	    if(a + b == c){
	    	for(int i=0;i<a;i++)
	    		w.print('|');
	    	w.print('+');
	    	for(int i=0;i<b;i++)
	    		w.print('|');
	    	w.print('=');
	    	for(int i=0;i<c;i++)
	    		w.print('|');
	    	w.println();
	    }
	    else
	    	w.println("Impossible");
	    
	    w.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}