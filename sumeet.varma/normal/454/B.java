import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class R259QBLittlePonyAndSortByShift {

	@SuppressWarnings("unused")
	public static void main(String args[] ) throws Exception {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	        
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int n = ip(st1.nextToken());
	          
	    StringTokenizer st2 = new StringTokenizer(br.readLine());
	    int a[] = new int[n];
	    for(int i=0;i<n;i++)
	    	a[i] = ip(st2.nextToken());
	        
	    int used = 0;
	    int index = -1;
	    for(int i=0;i<n;i++){
	    	if(i != n-1){
	    		if(a[i] > a[i+1]){
	    			used++;
	    			index = i;
	    		}
	    	}
	    }
	    
	    if(used == 0)
	    	w.println("0");
	    if(used >= 2)
	    	w.println("-1");
	    if(used == 1){
	    	if(a[n-1] <= a[0])
	    		w.println(n - index - 1);
	    	else
	    		w.println("-1");
	    }
	    w.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
	
}