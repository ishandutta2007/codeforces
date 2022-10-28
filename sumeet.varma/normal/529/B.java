import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;


public class GroupPhoto2 {

	public static void main(String args[] ) throws Exception {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter p = new PrintWriter(System.out);
	        
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int n = ip(st1.nextToken());
	    
		int w[] = new int[n];
		int h[] = new int[n];
		
		for(int i=0;i<n;i++){
		    StringTokenizer st2 = new StringTokenizer(br.readLine());
		    w[i] = ip(st2.nextToken());
		    h[i] = ip(st2.nextToken());
		}
	    
		int ans = Integer.MAX_VALUE;
		for(int mH = 1;mH <= 1000;mH++){
			
			int wid = 0;
			boolean done[] = new boolean[n];
			
			ArrayList<TwoInt> diff = new ArrayList<TwoInt>();
			
			int comp = 0;
			for(int i=0;i<n;i++){
				if(h[i] > mH){
					if(w[i] > mH){
						comp = n+1;
						break;
					}
					wid += h[i];
					comp++;
					done[i] = true;
				}
				else{
					if(h[i] < w[i] && w[i] <= mH)
						diff.add(new TwoInt(i,w[i] - h[i]));
					else{
						wid += w[i];
						done[i] = true;
					}
				}
			}
			
			if(comp <= n/2){
				Collections.sort(diff);
				int s = diff.size();
				int left = (n/2) - comp;
				for(int i=1;i<=Math.min(s,left);i++){
					int index = diff.get(s-i).index;
					done[index] = true;
					wid += h[index];
				}
				
				for(int i=0;i<n;i++){
					if(!done[i])
						wid += w[i];
				}
				
				//if(mH*wid < ans)
					//System.out.println(mH + " " + wid);
				
				ans = Math.min(mH*wid,ans);
			}
		}
		
		p.println(ans);
	    p.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}

class TwoInt implements Comparable<TwoInt>{
	int index,diff;
	
	TwoInt(int i,int d){
		this.index = i;
		this.diff = d;
	}
	
	public int compareTo(TwoInt arg0) {
		return this.diff - arg0.diff;
	}
	
}