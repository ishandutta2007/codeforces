import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class R258D2TaskBSortTheArray {

public static void main(String args[] ) throws Exception {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	        
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int n = ip(st1.nextToken());
		
	    StringTokenizer st2 = new StringTokenizer(br.readLine());
	    int a[] = new int[n+1];
	    for(int i=1;i<=n;i++)
	    	a[i] = ip(st2.nextToken());
	       
	    boolean started = false,finished = false;
	    boolean correct = true;
	    int ansx = 1,ansy = 1;
	    
	    
	    for(int i=1;i<=n;i++){
	    	if(a[i] < a[i-1]){
	    		if(finished){
	    			correct = false;
	    			break;
	    		}
	    		if(!started){
	    			started = true;
	    			ansx = i-1;
	    		}
	    	}
	    	else if(a[i] > a[i-1]){
	    		if(started && !finished){
	    			finished = true;
	    			ansy = i-1;
	    		}
	    	}
	    	if(i == n){
	    		if(started & !finished)
	    			ansy = n;
	    	}
	    }
	    
	    if(a[ansx - 1] > a[ansy])
	    	correct = false;
	    if(ansy < n && a[ansy+1] < a[ansx])
	    	correct = false;
	    
	    
	    if(correct){
	    	w.println("yes");
	    	w.println(ansx + " " + ansy);
	    }
	    else
	    	w.println("no");
	    w.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
	
}