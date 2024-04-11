import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;

public class R305qA {

	public static void main(String args[] ) throws Exception {
		   
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	    
	    char s[] = br.readLine().toCharArray();
	    int k = ip(br.readLine());
	    int n = s.length;
	    
	    if(n % k != 0){
	    	System.out.println("NO");
	    	return;
	    }
	        
	    int t = n/k;
	    boolean yes = true;
	    
	    for(int i=0;i<n;i+=t)
	    	yes &= isPali(s,i,i+t-1);
	    
	    w.println(yes ? "YES" : "NO");
	    w.close(); 
	}
	
	public static boolean isPali(char a[],int s,int e){
		while(s <= e){
			if(a[s] != a[e])	return false;
			s++;	e--;
		}
		return true;
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
	
}