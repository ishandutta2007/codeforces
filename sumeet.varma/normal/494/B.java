import java.io.*;
import java.util.*;

public class R282ObsessiveString {

	static long mod = (long)(1e9 + 7);
	
	public static void main(String args[] ) throws Exception {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	        
	    char s[] = br.readLine().toCharArray();
	    char t[] = br.readLine().toCharArray();
	    
	    boolean good[] = new boolean[s.length];
	    ArrayList<Integer> goodPos = search(s,t);
	    int siz = goodPos.size();
	    for(int i=0;i<siz;i++)
	    	good[goodPos.get(i)+t.length-1] = true;
	    
	    long a[] = new long[s.length];
	    long q1[] = new long[s.length];
	    long q2[] = new long[s.length];
	    
	    if(good[0])
	    	a[0] = q1[0] = q2[0] = 1;
	    
	    for(int i=1;i<s.length;i++){
	    	if(good[i]){
	    		if(i - t.length >= 0)
	    			a[i] = (q2[i-t.length] + i - t.length + 2) % mod;
	    		else
	    			a[i] = i - t.length + 2;
	    	}else
	    		a[i] = a[i-1];
	    	q1[i] = (q1[i-1] + a[i]) % mod;
	    	q2[i] = (q2[i-1] + q1[i]) % mod;
	    }
	    
	    long ans = 0;
	    for(int i=0;i<s.length;i++)
	    	ans = (ans + a[i]) % mod;
	    
	    w.println(ans);
	    w.close(); 
	}
	
	public static int[] preprocess(char[] ptrn) { // O(M)
			int i = 0, j = -1;
			int[] b = new int[ptrn.length + 1];
			b[i] = j;
			while (i < ptrn.length) {
			    while (j >= 0 && ptrn[i] != ptrn[j]) 
			    	j = b[j];
			    i++;
			    j++;
			    b[i] = j;
			}
		return b;
    }
	
	public static ArrayList<Integer> search(char[] text, char[] ptrn) { // O(N)
	    ArrayList<Integer> pos = new ArrayList<Integer>();
		int i = 0, j = 0;
		int[] b = preprocess(ptrn);
		while (i < text.length) {
		    while (j >= 0 && text[i] != ptrn[j]) 
		    	j = b[j];
		    i++;
		    j++;
		    if (j == ptrn.length) {
		    	pos.add(i - ptrn.length);
				j = b[j];
			}
		}
        return pos;
   }
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}