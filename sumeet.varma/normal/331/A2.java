import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.StringTokenizer;
import java.util.Map;
import java.util.TreeMap;

public class ABBYYqASweetBeverate {

	public static void main(String args[] ) throws Exception {
		   
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	    
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int n = ip(st1.nextToken());
	          
	    StringTokenizer st2 = new StringTokenizer(br.readLine());
	    int a[] = new int[n];
	    for(int i=0;i<n;i++)
	    	a[i] = ip(st2.nextToken());
	    
	    Map<Integer,Integer> map = new TreeMap<Integer,Integer>();
	    long posSum[] = new long[n];
	    posSum[0] = Math.max(a[0],0);
	    map.put(a[0], 0);
	    
	    long ans = Integer.MIN_VALUE;
	    int ansLeft = -1,ansRight = -1;
	    for(int i=1;i<n;i++){
	    	posSum[i] = posSum[i-1] + Math.max(0,a[i]);
	    	if(map.containsKey(a[i])){
	    		int left = map.get(a[i]);
	    		long disAns = 2*a[i] + posSum[i-1] - posSum[left];
	    		if(disAns > ans){
	    			ansLeft = left;
	    			ansRight = i;
	    			ans = disAns;
	    		}
	    	}
	    	else
	    		map.put(a[i], i);
	    }
	    
	    ArrayList<Integer> list = new ArrayList<Integer>();
	    for(int i=0;i<ansLeft;i++)
	    	list.add(i);
	    for(int i=ansLeft+1;i<ansRight;i++)
	    	if(a[i] < 0)
	    		list.add(i);
	    for(int i=ansRight+1;i<n;i++)
	    	list.add(i);
	    int k = list.size();
	    w.println(ans + " " + k);
	    for(int i=0;i<k;i++)
	    	w.print((list.get(i) + 1) + " ");
	    w.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}