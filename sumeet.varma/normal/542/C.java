import java.io.*;
import java.util.*;

public class VKr3qA {

	static int n;
	static int f[],distToCycle[];
	static boolean vis[],inCycle[],inStack[];
	static ArrayList<Integer> cycleLengths;
	
	public static void main(String args[] ) throws Exception {
		   
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	    
	    n = ip(br.readLine());
	  
	    StringTokenizer st2 = new StringTokenizer(br.readLine());
	    f = new int[n];
	    for(int i=0;i<n;i++)
	    	f[i] = ip(st2.nextToken()) - 1;
	    
	    vis = new boolean[n];
	    inCycle = new boolean[n];
	    inStack = new boolean[n];
	    cycleLengths = new ArrayList<Integer>();
	    
	    for(int i=0;i<n;i++){
	    	if(!vis[i]){
	    		vis[i] = true;
	    		dfs1(i);
	    	}
	    }
	    
	    distToCycle = new int[n];
	    Arrays.fill(distToCycle, -1);
	    for(int i=0;i<n;i++)
	    	if(distToCycle[i] == -1)	dfs2(i);
	    
	    long lcm = 1;
	    for(int x : cycleLengths)
	    	lcm = lcm(lcm,x);
	    
	    long ans = lcm;
	    for(int i=0;i<n;i++)
	    	while(ans < distToCycle[i])
	    		ans += lcm;
	    
	    w.println(ans);
	    w.close();
	}
	
	public static void dfs1(int curr){
		inStack[curr] = true;
		if(!vis[f[curr]]){
			vis[f[curr]] = true;
			dfs1(f[curr]);
		}
		else{
			if(!inCycle[f[curr]] && inStack[f[curr]]){
				int root = f[curr],cycleLength=1;
				inCycle[curr] = true;
				while(root != curr){
					inCycle[root] = true;
					cycleLength++;
					root = f[root];
				}
				cycleLengths.add(cycleLength);
			}
		}
		inStack[curr] = false;
	}
	
	public static int dfs2(int curr){
		if(distToCycle[curr] == -1){
			if(inCycle[curr])
				distToCycle[curr] = 0;
			else
				distToCycle[curr] = 1 + dfs2(f[curr]);
		}
		return distToCycle[curr];
	}
	
	public static long lcm(long a,long b){
		return a*b / gcd(a,b);
	}
	
	public static long gcd(long a,long b){
		long t;
		while(b != 0){
			t = b;
			b = a % b;
			a = t;
		}
		return a;
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
	
}