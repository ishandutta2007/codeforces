import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.StringTokenizer;


public class R14qDTwoPaths {

	static int u[],v[];
	static ArrayList<Integer> g[];
	static int label[];
	
	@SuppressWarnings("unchecked")
	public static void main(String args[] ) throws Exception {
		   
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	    
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int n = ip(st1.nextToken());
		
		u = new int[n];
		v = new int[n];
		for(int i=1;i<n;i++){
			StringTokenizer st = new StringTokenizer(br.readLine());
			u[i] = ip(st.nextToken()) - 1;
			v[i] = ip(st.nextToken()) - 1;
		}
	    
		int ans = 0;
		
		for(int rem=1;rem<n;rem++){
			 g = new ArrayList[n];
				for(int i=0;i<n;i++)
					g[i] = new ArrayList<Integer>();
			for(int i=1;i<n;i++){
				if(i == rem)	continue;
				g[u[i]].add(v[i]);
				g[v[i]].add(u[i]);
			}
			int max1 = 0,max2 = 0;
			label = new int[n];
			label(u[rem],-1,1);
			label(v[rem],-1,2);
			
			for(int i=0;i<n;i++){
				int dist = dfs(i,-1);
				if(label[i] == 1)
					max1 = Math.max(max1, dist);
				else
					max2 = Math.max(max2, dist);
			}
			ans = Math.max(max1*max2, ans);
		}
	    
		w.println(ans);
	    w.close(); 
	}
	
	public static void label(int curr,int prev,int lab){
		label[curr] = lab;
		int s = g[curr].size();
		for(int i=0;i<s;i++){
			int nxt = g[curr].get(i);
			if(nxt == prev)	continue;
			label(nxt,curr,lab);
		}
	}
	
	public static int dfs(int curr,int prev){
		int max = 0;
		int s = g[curr].size();
		for(int i=0;i<s;i++){
			int nxt = g[curr].get(i);
			if(nxt == prev)	continue;
			max = Math.max(max, 1 + dfs(nxt,curr));
		}
		return max;
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}