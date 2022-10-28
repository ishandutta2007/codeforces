import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;


public class Round293TaskA {

	public static void main(String args[] ) throws Exception {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	    
	    char s[] = br.readLine().toCharArray();
	    char t[] = br.readLine().toCharArray();
	    
	    boolean found = false;
	    
	    for(int i=s.length-1;i>=0;i--){
	    	if(s[i]=='z')
	    		s[i] = 'a';
	    	else{
	    		s[i]++;
	    		break;
	    	}
	    }
	   
	    for(int i=0;i<s.length;i++){
	    	if(s[i]!=t[i]){
	    		found = true;
	    		break;
	    	}
	    }
	    if(found){
	    	for(int i=0;i<s.length;i++)
	    		w.print(s[i]);
	    	w.println();
	    }
	    else
	    	w.println("No such string");
	    
	    w.close(); 
	}
	
	public static int compare(char s[],char t[]){
		for(int i=0;i<s.length;i++){
			if(s[i] < t[i])
				return -1;
			if(s[i] > t[i])
				return 1;
		}
		return 0;
	}
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}