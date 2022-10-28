import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class CrocChampqDConnectedComponents {

	public static void main(String args[] ) throws Exception {
		   
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	    
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int n = ip(st1.nextToken());
		int m = ip(st1.nextToken());
	          
	    int x[] = new int[m];
	    int y[] = new int[m];
	    for(int i=0;i<m;i++){
	    	StringTokenizer st2 = new StringTokenizer(br.readLine());
	    	x[i] = ip(st2.nextToken()) - 1;
	    	y[i] = ip(st2.nextToken()) - 1;
	    }
	    
	    DS pre[] = new DS[m];
	    pre[0] = new DS(n);
	    pre[0].merge(x[0], y[0]);
	    for(int i=1;i<m;i++){
	    	pre[i] = new DS(n,pre[i-1].comp,pre[i-1].rank,pre[i-1].parent);
	    	pre[i].merge(x[i],y[i]);
	    }
	    
	    DS post[] = new DS[m];
	    post[m-1] = new DS(n);
	    post[m-1].merge(x[m-1], y[m-1]);
	    for(int i=m-2;i>=0;i--){
	    	post[i] = new DS(n,post[i+1].comp,post[i+1].rank,post[i+1].parent);
	    	post[i].merge(x[i],y[i]);
	    }
	    
	    int k = ip(br.readLine());
	    for(int i=0;i<k;i++){
	    	StringTokenizer st = new StringTokenizer(br.readLine());
	    	int l = ip(st.nextToken()) - 1;
	    	int r = ip(st.nextToken()) - 1;
	    	if(l == 0 && r == m - 1)
	    		w.println(n);
	    	else if(l == 0)
	    		w.println(post[r+1].comp);
	    	else if(r == m - 1)
	    		w.println(pre[l-1].comp);
	    	else
	    		w.println(merge(pre[l-1],post[r+1],n));
	    }
	    
	    w.close(); 
	}
	
	public static int merge(DS a,DS b,int n){
		DS temp = new DS(a.n,a.comp,a.rank,a.parent);
		for(int i=0;i<n;i++)
			temp.merge(i, b.parent[i]);
		return temp.comp;
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
	
}


class DS {

	public int rank[],parent[];
	public int n,comp;
	
	public DS(int n){
	    this.n = n;
		makeSet();
	}
	
	public DS(int n,int comp,int r[],int p[]){
		this.n = n;
		this.comp = comp;
		rank = new int[n];
		parent = new int[n];
		for(int i=0;i<n;i++){
			rank[i] = r[i];
			parent[i] = p[i];
		}
	}
	
	public void makeSet(){
		comp = n;
		rank = new int[n];
		parent = new int[n];
		for(int i=0;i<n;i++)
			parent[i] = i;
	}
	
	public int find(int x){
		if(parent[x] != x)
			parent[x] = find(parent[x]);
		return parent[x];
	}
	
	public void merge(int x,int y){
		int xRoot = find(x);
		int yRoot = find(y);
		
		if(xRoot == yRoot)
			return;
		
		comp--;
		if(rank[xRoot] < rank[yRoot])
			parent[xRoot] = yRoot;
		else{
			parent[yRoot] = xRoot;
			if(rank[xRoot] == rank[yRoot]){
				parent[yRoot] = xRoot;
				rank[xRoot]++;
			}
		}
	}
	
	public void print(){
		for(int i=0;i<n;i++)
			System.out.println(i + " " + parent[i]);
		System.out.println();
	}
	
}