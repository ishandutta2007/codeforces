import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.util.Arrays;

public class CliqueProblemR296D1 {

	public static void main(String args[] ) throws Exception {
	
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	        
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int n = ip(st1.nextToken());
	          
	    Pair p[] = new Pair[n];
	    for(int i=0;i<n;i++){
	    	StringTokenizer st2 = new StringTokenizer(br.readLine());
	    	p[i] = new Pair(ip(st2.nextToken()),ip(st2.nextToken()));
	    }
	    
	    Arrays.sort(p);
	    
	    int ans = 1;
	    int currFinish = p[0].x + p[0].w;
	    
	    for(int i=1;i<n;i++){
	    	if(p[i].x - p[i].w >= currFinish){
	    		ans++;
	    		currFinish = p[i].x + p[i].w;
	    	}
	    }
	    
	    w.print(ans);
	    
	    w.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}

class Pair implements Comparable<Pair>{
	int x,w;
	Pair(int xx,int ww){
		x = xx;
		w = ww;
	}
	@Override
	public int compareTo(Pair arg0) {
		return x+w - arg0.x - arg0.w;
	}
	
}