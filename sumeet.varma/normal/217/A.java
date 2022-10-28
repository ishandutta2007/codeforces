import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class R134qAIceSkating {

	public static void main(String args[] ) throws Exception {
		   
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	    
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int n = ip(st1.nextToken());
		
	    int x[] = new int[n];
	    int y[] = new int[n];
	    DS4 ds = new DS4(n);
	    
	    for(int i=0;i<n;i++){
	    	StringTokenizer st2 = new StringTokenizer(br.readLine());
	    	x[i] = ip(st2.nextToken());
	    	y[i] = ip(st2.nextToken());
	    }
	    
	    for(int i=0;i<n;i++){
	    	for(int j=i+1;j<n;j++){
	    		if(x[i] == x[j] || y[i] == y[j])
	    			ds.merge(i, j);
	    	}
	    }
	    
	    w.println(ds.comp - 1);
	    w.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}

class DS4 {

	public int rank[],parent[];
	public int n,comp;
	
	public DS4(int n){
	    this.n = n;
		makeSet();
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