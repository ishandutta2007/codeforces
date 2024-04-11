import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;


public class R136qBLittleElephantAndArray {

	static int a[],hash[];
	static int ans,l,r;
	static boolean in[];
	
	public static void main(String args[] ) throws Exception {
		   
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	    
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int n = ip(st1.nextToken());
		int m = ip(st1.nextToken());
	         
	    StringTokenizer st2 = new StringTokenizer(br.readLine());
	    a = new int[n];
	    for(int i=0;i<n;i++)
	    	a[i] = ip(st2.nextToken());
	        
	    Query q[] = new Query[m];
	    Query.size = (int)(Math.sqrt(n));
	    for(int i=0;i<m;i++){
	    	StringTokenizer st = new StringTokenizer(br.readLine());
	    	q[i] = new Query(i,ip(st.nextToken()) - 1,ip(st.nextToken()) - 1);
	    }
	    Arrays.sort(q);
	    
	    int qans[] = new int[m];
	    in = new boolean[n];
	    hash = new int[100001];
	    l = 0;	r = 0;
	    add(0);
	    
	    for(int i=0;i<m;i++){
	    	while(l < q[i].l){
	    		remove(l);
	    		l++;
	    	}
	    	while(l >= q[i].l){
	    		add(l);
	    		if(l == q[i].l)	break;
	    		l--;
	    	}
	    	while(r <= q[i].r){
	    		if(r > l)	add(r);
	    		if(r == q[i].r)	break;
	    		r++;
	    	}
	    	while(r > q[i].r){
	    		remove(r);
	    		r--;
	    	}
	    	qans[q[i].idx] = ans;
	    }
	    
	    for(int i=0;i<m;i++)
	    	w.println(qans[i]);
	    w.close(); 
	}
	
	public static void add(int x){
		if(in[x] == true)	return;
		if(a[x] > 100000)	return;
		if(hash[a[x]] == a[x])
			ans--;
		hash[a[x]]++;
		if(hash[a[x]] == a[x])
			ans++;
		in[x] = true;
	}
	
	public static void remove(int x){
		if(in[x] == false)	return;
		if(a[x] > 100000)	return;
		if(hash[a[x]] == a[x])
			ans--;
		hash[a[x]]--;
		if(hash[a[x]] == a[x])
			ans++;
		in[x] = false;
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}

class Query implements Comparable<Query>{
	static int size;
	int idx,l,r,block;
	Query(int i,int a,int b){
		idx = i;
		l = a;
		r = b;
		block = (l + 1)/size;
	}
	@Override
	public int compareTo(Query o) {
		if(block != o.block)
			return block - o.block;
		return r - o.r;
	}
	
}