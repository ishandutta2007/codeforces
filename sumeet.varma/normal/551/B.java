import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;

public class R307qB {

	public static void main(String args[] ) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	        
	    char a[] = br.readLine().toCharArray();
	    char b[] = br.readLine().toCharArray();
	    char c[] = br.readLine().toCharArray();
	    
	    int xa[] = new int[26];
	    for(char x : a)	xa[x - 'a']++;
	    
	    int xb[] = new int[26];
	    for(char x : b)	xb[x - 'a']++;
	    
	    int xc[] = new int[26];
	    for(char x : c)	xc[x - 'a']++;
	    
	    int a1 = 0,a2 = 0;
	    int n = a.length;
	    
	    for(int i=0;i<=n;i++){
	    	boolean can = true;
	    	int t[] = new int[26];
	    	System.arraycopy(xa, 0, t, 0, 26);
	    	for(int j=0;j<26;j++){
	    		if(xb[j] * 1L * i >= Integer.MAX_VALUE)
	    			can = false;
	    		t[j] -= xb[j] * 1L * i;
	    		if(t[j] < 0)	can = false;
	    	}
	    	if(!can)	break;
	    	int min = a.length;
	    	for(int j=0;j<26;j++)
	    		min = xc[j] == 0 ? min : Math.min(min, t[j] / xc[j]);
	    	if(i + min > a1 + a2){
	    		a1 = i;
	    		a2 = min;
	    	}
	    }
	    
	    for(int i=0;i<a1;i++)
	   		w.print(new String(b));
	   	for(int i=0;i<a2;i++)
	   		w.print(new String(c));
	   	for(int i=0;i<26;i++)
    		xa[i] -= xb[i] * a1;
	   	for(int i=0;i<26;i++)
	   		xa[i] -= xc[i] * a2;
	   	for(int i=0;i<26;i++)
	   		for(int j=0;j<xa[i];j++)
	   			w.print((char)('a' + i));
	   	
    	w.println();

	    w.close();
	        
	}
	
}