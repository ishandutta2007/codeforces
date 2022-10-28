import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;


public class Treasure {

	public static void main(String args[] ) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	    
	    char a[] = br.readLine().toCharArray();
	    int tl = 0 , tr = 0 ,th = 0 , lastOcc = 0;
	    for(int i=0;i<a.length;i++){
	    	if(a[i] == '#')	{
	    		th++;
	    		lastOcc = i;
	    	}
	    	if(a[i] == '(')	tl++;
	    }
	    tr = a.length - th - tl;
	    if(tr + th > tl){
	    	System.out.println("-1");
	    	return;
	    }
	    
	    
	    int diff = tl - tr;
	    int lastV = diff - (th-1);
	    int lC = 0,rC = 0;
	    
	    for(int i=0;i<lastOcc;i++){
	    	if(a[i] == '(')	lC++;
	    	if(a[i] == ')' || a[i] == '#'){
	    		rC++;
	    		if(rC > lC){
	    			System.out.println("-1");
	    			return;
	    		}
	    	}
	    }
	    
	    rC += lastV;
	    if(rC > lC){
			System.out.println("-1");
			return;
		}
	    
	    for(int i = lastOcc + 1;i<a.length;i++){
	    	if(a[i] == '(')	lC++;
	    	if(a[i] == ')' || a[i] == '#'){
	    		rC++;
	    		if(rC > lC){
	    			System.out.println("-1");
	    			return;
	    		}
	    	}
	    }
	    	
	    for(int i=0;i<th-1;i++)
	    	w.println("1");
	    w.println(lastV);
	    w.close();
	}
	
}