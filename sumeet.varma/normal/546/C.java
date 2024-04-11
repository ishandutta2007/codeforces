import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.util.*;

public class R305qC {

	public static void main(String args[] ) throws Exception {
		   
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	    
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int n = ip(st1.nextToken());
		
	    LinkedList<Integer> q1 = new LinkedList<Integer>();
	    
	    StringTokenizer st2 = new StringTokenizer(br.readLine());
	    int k1 = ip(st2.nextToken());
	    for(int i=0;i<k1;i++)
	    	q1.addLast(ip(st2.nextToken()));
	        
	    LinkedList<Integer> q2 = new LinkedList<Integer>();
	    
	    StringTokenizer st3 = new StringTokenizer(br.readLine());
	    int k2 = ip(st3.nextToken());
	    for(int i=0;i<k2;i++)
	    	q2.addLast(ip(st3.nextToken()));
	        
	    for(int i=0;i<=3628801;i++){
	    	if(q1.isEmpty()){
	    		System.out.println(i + " " + 2);
	    		return;
	    	}
	    	if(q2.isEmpty()){
	    		System.out.println(i + " " + 1);
	    		return;
	    	}
	    	int val1 = q1.removeFirst();
	    	int val2 = q2.removeFirst();
	    	if(val1 > val2){
	    		q1.addLast(val2);
	    		q1.addLast(val1);
	    	}
	    	else{
	    		q2.addLast(val1);
	    		q2.addLast(val2);
	    	}
	    }
	    
	    System.out.println(-1);
	    w.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
	
}