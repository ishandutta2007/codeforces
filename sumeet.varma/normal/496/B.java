import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class SecretCombination {

	public static void main(String args[] ) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	        
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int n = ip(st1.nextToken());
	          
	    char in[] = br.readLine().toCharArray();
	    int a[] = new int[n];
	    for(int i=0;i<n;i++)
	    	a[i] = Character.getNumericValue(in[i]);
	         
	    int min[] = new int[n];
	    for(int i=0;i<n;i++)
	    	min[i] = a[i];
	    
	    for(int i=0;i<10;i++){
	    	add(a);
	    	for(int j=0;j<=n;j++){
	    		rotate(a);
	    		compare(a,min);
	    	}
	    }
	    
	    for(int i=0;i<n;i++)
	    	w.print(min[i]);
	    w.println();
	    w.close(); 
	}
	
	public static void add(int[] a){
		int n = a.length;
		for(int i=0;i<n;i++)
			a[i] = (a[i] + 1)%10;
	}
	
	public static void rotate(int[] a){
		int n = a.length;
		int temp = a[0];
		for(int i=1;i<n;i++)
			a[i-1] = a[i];
		a[n-1] = temp;
	}
	
	public static void compare(int[]a ,int[] min){
		boolean change = false;
		int n = a.length;
		
		for(int i=0;i<n;i++){
			if(a[i] > min[i])	break;
			if(a[i] < min[i]){
				change = true;
				break;
			}
		}
		if(change){
			for(int i=0;i<n;i++)
				min[i] = a[i];
		}
	}
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}