import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.StringTokenizer;


public class VasyaAndWrestling {

	public static void main(String args[] ) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	        
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int n = ip(st1.nextToken());
	    
	    ArrayList<Long> w1 =new ArrayList();
	    ArrayList<Long> w2 = new ArrayList();
	    long total1 = 0, total2 = 0;
	    boolean last = true;
	    
	    for(int i=0;i<n;i++){
	    	long j = Long.parseLong(br.readLine());
	    	if(j  > 0){
	    		total1 += j;
	    		w1.add(j);
	    	}
	    	else{
	    		total2 += -j;
	    		w2.add(-j);
	    	}
	    	if(i==n-1){
	    		if(j > 0){
	    			last = true;
	    		}
	    		else
	    			last = false;
	    	}
	    }
	    
	  //  System.out.println(total1 + " " + total2);
	   // System.out.println(w1 + " " + w2);
	    //		System.out.println(last);
	    if(total1 > total2){
	    	System.out.println("first");
	    	return;
	    }
	    else if(total2 > total1){
	    	System.out.println("second");
	    	return;
	    }
	    
	    else{
	    	int ls = w1.size();
	    	int rs = w2.size();
	    	for(int i=0;i<Math.min(ls,rs);i++){
	    		long l = w1.get(i);
	    		long r = w2.get(i);
	    		if(l < r){
	    			System.out.println("second");
	    			return;
	    		}
	    		if(l > r){
	    			System.out.println("first");
	    			return;
	    		}
	    	}
	    	if( ls > rs){
	    		System.out.println("first");
	    		return;
	    	}
	    	if( ls < rs){
	    		System.out.println("second");
	    		return;
	    	}
	    }
	    
	    if(last){
	    	System.out.println("first");
	    }
	    else{
	    	System.out.println("second");
	    }
	    w.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}