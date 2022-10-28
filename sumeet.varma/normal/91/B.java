import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;


public class R75qBQueue {

	static int segtree[];
	
	public static void main(String args[] ) throws Exception {
		   
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	    
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int n = ip(st1.nextToken());
		
	    Pair3 p[] = new Pair3[n];
	    StringTokenizer st2 = new StringTokenizer(br.readLine());
	    for(int i=0;i<n;i++)
	    	p[i] = new Pair3(i,ip(st2.nextToken()));
	    
	    Arrays.sort(p);
	    //System.out.println(Arrays.deepToString(p));
	    
	    segtree = new int[4*n];
	    Arrays.fill(segtree, -1);
	    
	    int ans[] = new int[n];
	    for(int i=0;i<n;i++){
	    	if(p[i].idx == n-1)
	    		ans[n-1] = -1;
	    	else{
	    		int o = find(0,n-1,0,p[i].idx + 1,n-1);
	    		ans[p[i].idx] = o == -1 ? o : o - p[i].idx - 1;
	    	}
	    	update(0,n-1,0,p[i].idx);
	    }
	    
	    for(int i=0;i<n;i++)
	    	w.print(ans[i] + " ");
	    w.close(); 
	}
	
	public static void update(int s,int e,int c,int idx){
		segtree[c] = Math.max(segtree[c], idx);
		if(s == e)	return;
		int m = (s + e) / 2;
		if(idx <= m)	update(s,m,2*c+1,idx);
		else	update(m+1,e,2*c+2,idx);
	}
	
	public static int find(int s,int e,int c,int l,int r){
		if(s == l && e == r)
			return segtree[c];
		int m = (s + e) / 2;
		if(l <= m && r <= m) return find(s,m,2*c+1,l,r);
		else if(l > m && r > m)   return find(m+1,e,2*c+2,l,r);
		else  return Math.max(find(s,m,2*c+1,l,m), find(m+1,e,2*c+2,m+1,r));
	}
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}

class Pair3 implements Comparable<Pair3>{
	int idx,val;
	Pair3(int idx,int val){
		this.idx = idx;
		this.val = val;
	}
	public int compareTo(Pair3 b){
		if(val != b.val)	return val - b.val;
		return idx - b.idx;
	}
	public String toString(){
		return idx + " ";
	}
}