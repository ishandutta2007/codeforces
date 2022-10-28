//package Practise;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;

public class R162qAEscapeFromStones {

	public static void main(String args[] ) throws Exception {
		   
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	    
	    char s[] = br.readLine().toCharArray();
	    int n = s.length;    
	    
	    int ans[] = new int[n];
	    int head = 0,tail = n - 1;
	    
	    for(int i=0;i<n;i++){
	    	if(s[i] == 'l')
	    		ans[tail--] = i + 1;
	    	else
	    		ans[head++] = i + 1;
	    }
	    
	    for(int i=0;i<n;i++)
	    	w.println(ans[i]);
	    w.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}