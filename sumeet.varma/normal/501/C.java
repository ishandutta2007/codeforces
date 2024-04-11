//package Round285Div2;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Stack;
import java.util.StringTokenizer;

public class TaskCMishaAndForest {

	public static void main(String args[] ) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	        
	    int n = ip(br.readLine());
	    int degree[] = new int[n];
	    int xor[] = new int[n];
	    long edge = 0;
	    
	    for(int i=0;i<n;i++) {
	    	StringTokenizer st1 = new StringTokenizer(br.readLine());
	    	degree[i] = ip(st1.nextToken());
	    	xor[i] = ip(st1.nextToken());
	        edge += degree[i];
	    }
	        
	    w.println(edge/2);
	    
	    LinkedList<Integer> queue = new LinkedList();
	    for(int i=0;i<n;i++){
	    	if(degree[i] == 1)
	    		queue.add(i);
	    }
	    
	    while(!queue.isEmpty()){
	    	int curr = queue.remove();
	    	if(degree[curr] == 0)	continue;
	    	
	    	int other = xor[curr];
	    	degree[curr]--;
	    	degree[other]--;
	    	xor[other] ^= curr;
	    	w.println(curr + " " + other);
	    	//	System.out.println(curr + " " + degree[curr] + " " + other + degree[other]);
	    	if(degree[other] == 1)
	    		queue.add(other);
	    }
	    w.close();
	        
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
	
}