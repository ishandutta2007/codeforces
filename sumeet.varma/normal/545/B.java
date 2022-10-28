import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;

public class R303qB {

	public static void main(String args[] ) throws Exception {
		   
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	    
	    char s[] = br.readLine().toCharArray();
	    char t[] = br.readLine().toCharArray();
	    char ans[] = new char[s.length];
	    int count1 = 0,count2 = 0;
	    
	    for(int i=0;i<s.length;i++){
	    	if(s[i] == t[i])
	    		ans[i] = s[i];
	    	else{
	    		if(count1 <= count2){
	    			ans[i] = s[i];
	    			count1++;
	    		}
	    		else{
	    			ans[i] = t[i];
	    			count2++;
	    		}
	    	}
	    }
	    
	    if(count1 != count2)
	    	w.println("impossible");
	    else
	    	w.println(new String(ans));
	    
	    w.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}