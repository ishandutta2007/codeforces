import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class AntonAndCurrency {

	static int currSwapped;
	static int num[];
	
	public static void main(String args[] ) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	        
	    char a[] = br.readLine().toCharArray();
	    num = new int[a.length];
	    for(int i=0;i<a.length;i++)
	    	num[i] = Character.getNumericValue(a[i]);
	    
	    boolean found = false;
	    currSwapped = -1;
	    for(int i=a.length-1;i>=0;i--){
	    	if(num[i] % 2 == 0){
	    		if(!found){
	    			found = true;
	    			currSwapped = i;
	    		}
	    		else{
		    		if(check(currSwapped,i))
		    			currSwapped = i;
		    		}
	    	}
	    }
	    if(!found)
	    	w.println(currSwapped);
	    else{
	    	int t = num[num.length-1];
	    	num[num.length-1] = num[currSwapped];
	    	num[currSwapped] = t;
	    	for(int i=0;i<num.length;i++)
	    		w.print(num[i]);
	    	w.println();
	    }
	    w.close(); 
	}
	
	public static boolean check(int currSwap,int i){
		if(num[num.length - 1] > num[i])
			return true;
		if(num[num.length - 1] < num[i])
			return false;
		if(num[num.length - 1] > num[currSwap])
			return false;
		if(num[num.length - 1] < num[currSwap])
			return true;
		return false;
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}