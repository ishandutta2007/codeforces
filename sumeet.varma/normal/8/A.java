//package Practise;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;

public class R8qBTrainAndPeter {

	public static void main(String args[] ) throws Exception {
		   
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	    
	    char s1[] = br.readLine().toCharArray();
	    char a[] = br.readLine().toCharArray();    
	    char b[] = br.readLine().toCharArray();
	    
	    int n = s1.length;
	    char s2[] = new char[n];
	    for(int i=0;i<n;i++)
	    	s2[i] = s1[n-1-i];
	    
	    boolean a1[] = match(a,s1);
	    boolean b1[] = match(b,s1);
	    
	    int first = n;
	    for(int i=n-1;i>=0;i--)
	    	if(a1[i])
	    		first = i;
	    
	    boolean forward = false;
	    
	    for(int i=first+a.length;i<n;i++)
	    	if(b1[i])
	    		forward = true;
	    
	    
	    boolean a2[] = match(a,s2);
	    boolean b2[] = match(b,s2);
	    
	    
	    first = n;
	    for(int i=n-1;i>=0;i--)
	    	if(a2[i])
	    		first = i;
	    
	    boolean reverse = false;
	    
	    for(int i=first+a.length;i<n;i++)
	    	if(b2[i])
	    		reverse = true;
	    	
	    if(forward && reverse)
	    	w.println("both");
	    else if(forward)
	    	w.println("forward");
	    else if(reverse)
	    	w.println("backward");
	    else
	    	w.println("fantasy");
	    
	    w.close(); 
	}
	
	public static boolean[] match(char pat[],char text[]){
		char magic[] = new char[pat.length + text.length + 1];
		
		for(int i=0;i<pat.length;i++)
			magic[i] = pat[i];
		
		magic[pat.length] = ' ';
		
		for(int i=0;i<text.length;i++)
			magic[pat.length + i + 1] = text[i];
		
		int z[] = zFunction(magic);
		
		boolean occur[] = new boolean[text.length];
		for(int i=0;i<text.length;i++)
			occur[i] = z[pat.length + i + 1] == pat.length;
		
		return occur;
 	}
	
	public static int[] zFunction(char pat[]){
		int n = pat.length;
		int z[] = new int[n];
		
		int l = 0,r = 0;
		for(int i=1;i<n;i++){
			if(i > r){
				l = r = i;
				while(r < n && pat[r-l] == pat[r]) r++;
				z[i] = r - l;
				r--;
			}
			else{
				int k = i - l;
				if(z[k] < r - i + 1)	z[i] = z[k];
				else{
					l = i;
					while(r < n && pat[r-l] == pat[r]) r++;
					z[i] = r - l;
					r--;
				}
			}
		}
		
		z[0] = n;
		return z;
	}
	
}