import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;


public class R172qDMaxXorSecondary {

	static int oo = 1000000000;
	static int segmin[],segmax[];
	
	public static void main(String args[] ) throws Exception {
		   
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	    
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int n = ip(st1.nextToken());
		      
	    StringTokenizer st2 = new StringTokenizer(br.readLine());
	    Pair2 p[] = new Pair2[n];
	    for(int i=0;i<n;i++)
	    	p[i] = new Pair2(i,ip(st2.nextToken()));
	    
	    int a[] = new int[n];
	    for(int i=0;i<n;i++)
	    	a[i] = p[i].val;
	    
	    segmin = new int[4*n];
	    segmax = new int[4*n];
	    Arrays.fill(segmin, oo);
	    Arrays.fill(segmax, -1);
	    
	    Arrays.sort(p);
	    int	ans = 0;
	    
	    for(int i=0;i<n;i++){
	    	//System.out.print(p[i].idx + " ");
	    	if(p[i].idx != 0){
	    		int i1 = findMax(0,n-1,0,0,p[i].idx - 1);
	    		if(i1 != -1)	ans = Math.max(p[i].val^a[i1],ans);
	    		//System.out.print(i1 + " t1 ");
	    	}
	    	if(p[i].idx != n-1){
	    		int i2 = findMin(0,n-1,0,p[i].idx + 1,n-1);
	    		if(i2 != oo) 	ans = Math.max(ans, p[i].val ^ a[i2]);
	    		//System.out.print(i2 + " t2 ");
	    	}
	    	update(0,n-1,0,p[i].idx);	
	    	//System.out.println();
	    }
	    
	    w.println(ans);
	    w.close(); 
	}
	
	public static void update(int s,int e,int c,int x){
		if(s == e)
			segmin[c] = segmax[c] = s;
		else{
			int m = (s + e) / 2;
			if(x <= m)	update(s,m,2*c+1,x);
			else	update(m+1,e,2*c+2,x);
			segmin[c] = Math.min(segmin[c], x);
			segmax[c] = Math.max(segmax[c], x);
		}
	}
	
	public static int findMin(int s,int e,int c,int l,int r){
		if(s == l && e == r)
			return segmin[c];
		int m = (s + e) / 2;
		if(l <= m && r <= m)
			return findMin(s,m,2*c+1,l,r);
		else if(l > m && r > m)
			return findMin(m+1,e,2*c+2,l,r);
		else //if(l <= m && r > m)
			return Math.min(findMin(s,m,2*c+1,l,m) , findMin(m+1,e,2*c+2,m+1,r));
	}
	
	public static int findMax(int s,int e,int c,int l,int r){
		if(s == l && e == r)
			return segmax[c];
		int m = (s + e) / 2;
		if(l <= m && r <= m)
			return findMax(s,m,2*c+1,l,r);
		else if(l > m && r > m)
			return findMax(m+1,e,2*c+2,l,r);
		else //if(l <= m && r > m)
			return Math.max(findMax(s,m,2*c+1,l,m) , findMax(m+1,e,2*c+2,m+1,r));
	}
	public static int ip(String s){
		return Integer.parseInt(s);
	}
	
}

class Pair2 implements Comparable<Pair2>{
	int idx,val;
	Pair2(int i,int v){
		idx = i;
		val = v;
	}
	public int compareTo(Pair2 o){
		return -1*Integer.compare(val, o.val);
	}
}