import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class R279TaskB {
	
public static void main(String args[] ) throws Exception {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	        
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int n = ip(st1.nextToken());
		
	    char a[] = br.readLine().toCharArray();
	    
	    int key[] = new int[26];
	    int ans = 0;
	    
	    for(int i=0;i<a.length;i++){
	    	if(a[i] >= 'a')
	    		key[a[i]-'a']++;
	    	else{
	    		if(key[a[i]-'A'] > 0)
	    			key[a[i]-'A']--;
	    		else
	    			ans++;
	    	}
	    }
	    
	    w.println(ans);
	    w.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}