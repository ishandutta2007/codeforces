import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.StringTokenizer;


public class NewYearPermutation {
	
	public static void main(String args[] ) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	        
	    int n = ip(br.readLine());
	    
	    int a[] = new int[n];
	    StringTokenizer st2 = new StringTokenizer(br.readLine());
	    for(int i=0;i<n;i++)
	    	a[i] = ip(st2.nextToken());

	    char check[][] = new char[n][n];
	    for(int i=0;i<n;i++)
	    		check[i] = br.readLine().toCharArray();
	    
	    int ans[] = new int[n];
	    boolean visited[] = new boolean[n];
	   
	    for(int i=0;i<n;i++){
	    	if(visited[i] == false){
	    	
	    		ArrayList<Integer> temp2 = new ArrayList<Integer>();
	    			//bfs(i,temp2);
	    		
	    		LinkedList<Integer> q = new LinkedList();
	    		q.add(i);
	    		visited[i] = true;
	    		
	    		while(!q.isEmpty()){
	    			int curr = q.remove();
	    			temp2.add(curr);
	    			for(int j=0;j<n;j++)
	    				if(check[curr][j] == '1' && !visited[j]){
	    					q.add(j);
	    					visited[j] = true;
	    				}
	    		}
	    		
	    		
	    		int len = temp2.size();
	    		
	    		
	    		int temp[] = new int[len];
	    		for(int j=0;j<len;j++)
	    			temp[j] = a[temp2.get(j)];
	    		
	    		
	    		int temp3[] = new int[len];
	    		for(int j=0;j<len;j++)
	    			temp3[j] = temp2.get(j);
	    		
	    		
	    		Arrays.sort(temp);
	    		Arrays.sort(temp3);
	    		
	    		for(int j=0;j<len;j++)
	    			ans[temp3[j]] = temp[j];
	    	}
	    }
	    
	    for(int i=0;i<n;i++)
	    	w.print(ans[i] + " ");
	    
	    w.println();
	    w.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}