import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.StringTokenizer;


public class NoToPalindromes {

	public static void main(String args[] ) throws Exception {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	        
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int n = ip(st1.nextToken());
		int p = ip(st1.nextToken());
	          
		String b = br.readLine();
	    char a[] = b.toCharArray();
	    
	    int index = -1;
	    
	    for(int i=n-1;i>=0;i--){
	    	boolean not[] = new boolean[p+1];
	    	if(i-1>=0)
	    		not[a[i-1]-'a'] = true;
	    	if(i - 2 >= 0)
	    		not[a[i-2]-'a'] = true;
	    	not[a[i]-'a'] = true;
	    	
	    	boolean found = false;
	    	for(char k = a[i];k<g(p);k++){
	    			if(!not[k-'a']){
	    				a[i] = k;
	    				found = true;
	    				index = i;
	    				break;
	    			}
	    	}
	    	
	    	if(found)
	    		break;
	    }
	    
	    for(int i=index+1;i<n;i++){
	    	boolean not[] = new boolean[p];
	    	if(i-1>=0)
	    		not[a[i-1] - 'a'] = true;
	    	if(i -2 >= 0)
	    		not[a[i-2] - 'a'] = true;
	    	for(int j=p-1;j>=0;j--)
	    		if(!not[j])
	    			a[i] = g(j);
	    }
	    
	    if(new String(a).compareTo(b) > 0)
	    	w.println(new String(a));
	    else
	    	w.println("NO");
	    w.close(); 
	}
	
	public static char g(int i){
		return (char)('a' + i);
	}
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}