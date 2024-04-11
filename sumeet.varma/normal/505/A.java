import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class KitayuGift {

	public static void main(String args[] ) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	        
	    int t = 1;
	    boolean found = false;
	    StringBuffer ans = new StringBuffer("sdds");
	    Character.toString('a');
	    
	    while(t-- > 0) {
	    	StringBuffer s = new StringBuffer(br.readLine().trim());
	    	
	    	
	    	int len = s.length();
	        for(int i=0;i<26;i++){
	        	for(int j=0;j<=len;j++){
	        		s.insert(j, Character.toString((char)('a'+i)));
	        		//System.out.println(s);
	        		if(isPali(s)){
	        			w.println(s);
	        			found = true;
	        			break;
	        		}
	        		s.deleteCharAt(j);
	        		//System.out.println(s);
	        	}
	        	if(found)	break;
	        }
	    	
	        if(!found)
	        	w.println("NA");
	    }
	        
	    w.close();
	        
	}
	
	public static boolean isPali(StringBuffer ss){
		String s = ss.toString();
		char a[] = s.toCharArray();
		int n = a.length;
		for(int i=0;i<n/2;i++)
			if(a[i] != a[n-1-i])	return false;
		return true;
	}
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}