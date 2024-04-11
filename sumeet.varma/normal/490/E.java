import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class RestoringIncreasingSequence {
	
	public static void main(String args[] ) throws Exception {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	        
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int n = ip(st1.nextToken());
	   
	    char a[][] = new char[n][];
	    for(int i=0;i<n;i++)
	    	a[i] = br.readLine().toCharArray();
	    
	    boolean exists = true;
	    
	    if(a[0][0] == '?')
	    	a[0][0] = '1';
	    
	    for(int j=1;j<a[0].length;j++)
	    	if(a[0][j] == '?')
	    		a[0][j] = '0';
	    
	    for(int i=1;i<n;i++){
	    	if(a[i].length < a[i-1].length){
	    		exists = false;
	    		break;
	    	}
	    	else if(a[i].length > a[i-1].length){
	    		 if(a[i][0] == '?')
	    		    	a[i][0] = '1';
	    		    for(int j=1;j<a[i].length;j++)
	    		    	if(a[i][j] == '?')
	    		    		a[i][j] = '0';
	    	}
	    	else{
	    		if(solve(a[i-1],a[i],0) == false){
	    			exists = false;
	    			break;
	    		}
	    	}
	    }
	    
	    if(exists){
	    	w.println("YES");
	    	for(int i=0;i<n;i++)
	    		w.println(new String(a[i]));
	    }
	    else
	    	w.println("NO");
	    
	    w.close(); 
	}
	
	//we want b > a
	private static boolean solve(char[] a,char b[],int curr) {
		int n = a.length;
		
		if(curr == n){
			for(int i=0;i<n;i++){
				if(b[i] > a[i])
					return true;
				if(b[i] < a[i])
					return false;
			}
			return false;
		}
		
		if(b[curr] == '?'){
			if(a[curr] == '9'){
				b[curr] = '9';
				return solve(a,b,curr+1);
			}
			else{
				char c[] = new char[n];
				System.arraycopy(b, 0, c, 0, n);
				b[curr] = a[curr];
				if(solve(a,b,curr+1) == false){
					System.arraycopy(c, 0, b, 0, n);
					b[curr] = (char)(a[curr] + 1);
					for(int j=curr+1;j<n;j++)
						if(b[j] == '?')
							b[j] = '0';
				}
				return true;
			}
		}
		
		else{
			if(b[curr] < a[curr]) //already a greater
				return false;
			else if(b[curr] == a[curr])//try with next character
				return solve(a,b,curr+1);
			else{
				//already b greater
				for(int i=curr+1;i<n;i++){
					if(b[i] == '?')
						b[i] = '0';
				}
				return true;
			}
		}
		
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}