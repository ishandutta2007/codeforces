/*
 * Hopefully this is AC :D
 */

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.StringTokenizer;
import java.util.Arrays;

public class TwoSets {

	static ArrayList<Integer> g[];
	static boolean visited[];
	static int ans[],p[],orig[];
	static int n,a,b;
	
	@SuppressWarnings("unchecked")
	public static void main(String args[] ) throws Exception {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	        
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    n = ip(st1.nextToken());
	    a = ip(st1.nextToken());
	    b = ip(st1.nextToken());
	    
	    g = new ArrayList[n];
	    visited = new boolean[n];
	    ans = new int[n];
	    p = new int[n];
	    orig = new int[n];
	    
	    StringTokenizer st2 = new StringTokenizer(br.readLine());
	    for(int i=0;i<n;i++){
	    	p[i] = ip(st2.nextToken());
	    	orig[i] = p[i];
	    	g[i] = new ArrayList<Integer>();
	    }
	    
	    Arrays.sort(p);
	    
	    boolean impossible = false;
	    
	    for(int i=0;i<n;i++){
	    	int i1 = Arrays.binarySearch(p, a-p[i]);
	    	int i2 = Arrays.binarySearch(p, b-p[i]);
	    	if(i1 < 0 || i1 >= n)	i1 = -1;
	    	if(i2 < 0 || i2 >= n)	i2 = -1;
	    	
	    	if(i1 == -1 && i2 != -1) //if only (b-x) present then both must belong to set 1
	    		g[i].add(i2);
	    	
	    	else if(i1 != -1 && i2 == -1) //if only (a-x) present then both must belong to set 0
	    		g[i].add(i1);
	    	
	    	else if(i1 != -1 && i2 != -1){ //both present hence all 3 should be in same set,doesn't matter which
	    		g[i].add(i1);
	    		g[i].add(i2);
	    	}
	    	else{ //if none present then not possible to be in any set
	    		impossible = true;
	    		break;
	    	}
	    }
	   
	    if(impossible){//if any element without both a-x and b-x found
	    	System.out.println("NO");
	    	return;
	    }
	    
	    //Edge between a and b means they must be present in same set
	    //ans[i] =0 or ans[i] =1 means it must be compulsory be present in that set
	    //ans[i] = -1 means no restrictions on it's set number
	    
	    LinkedList<Integer>	q = new LinkedList();//Queue
	    for(int i=0;i<n;i++){
	    	
	    	if(visited[i] == false){
	    		
	    		ArrayList<Integer>	curq = new ArrayList<Integer>();      //contains indices of all nodes in this connected component
	    		
	    		curq.add(i);
	    		q.add(i);
	    		visited[i] = true;
	    
	    		while(!q.isEmpty()){
	    			int curr = q.remove();
	    			int s = g[curr].size();
	    			for(int j=0;j<s;j++){
	    				if(!visited[g[curr].get(j)]){
	    					visited[g[curr].get(j)] = true;
	    					curq.add(g[curr].get(j));
	    					q.add(g[curr].get(j));
	    				}
	    			}
	    		}
	    
	    		boolean  found = true;
	    		
    			int s = curq.size();
	    		int temp[] = new int[s];
    			for(int j=0;j<s;j++)
    				temp[j] = p[curq.get(j)];
    			Arrays.sort(temp);
    			
    			int anss = -1;
    			
	    		for(int j=0;j<s;j++){
	    			int i3 = Arrays.binarySearch(temp, a - temp[j]);
	    			if(i3 < 0 || i3 >= n){
	   					found = false;
	   					break;
	   				}
	   			}
	    			
	    		if(!found){
	    			found = true;
	    				
	    			for(int j=0;j<s;j++){
		    			int i3 = Arrays.binarySearch(temp, b - temp[j]);
		   				if(i3 < 0 || i3 >= n){
		   					found = false;
		   					break;
		   				}
	    			}
	    			
	    			if(found)
	    				anss = 1;
	    			else{
	    				impossible = true;
	    				break;
	    			}
	    				    			
	    		}
	    		else
	    			anss = 0;
	    		
	    		for(int j=0;j<s;j++)
	    			ans[curq.get(j)] = anss;
	    	
	    	}
	    	
	    	
	    }
	    
	    if(!impossible){
	    	w.println("YES");
    		for(int i=0;i<n;i++){
    			int i1 = Arrays.binarySearch(p, orig[i]);
    			if(ans[i1] == -1)	ans[i1] = 1;
    			w.print(ans[i1] + " ");
    		}
    		w.println();
    	}
	    else
	    	w.println("NO");
	    
	    w.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}