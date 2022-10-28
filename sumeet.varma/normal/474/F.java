import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class AntColony {

	static Node segtreeMin[];
	static int segtreeGCD[];
	static int a[];
	
	public static void main(String args[] ) throws Exception {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	        
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int n = ip(st1.nextToken());
		 
	    StringTokenizer st2 = new StringTokenizer(br.readLine());
	    a = new int[n];
	    for(int i=0;i<n;i++)
	    	a[i] = ip(st2.nextToken());
	    
	    segtreeMin = new Node[4*n];
	    segtreeGCD = new int[4*n];
	    
	    buildMin(0,n-1,0);
	    buildGCD(0,n-1,0);
	    
	    int T = ip(br.readLine());
	    
	    for(int t=1;t<=T;t++){
	    	st1 = new StringTokenizer(br.readLine());
	    	int l = ip(st1.nextToken()) - 1;
	    	int r = ip(st1.nextToken()) - 1;
	    	Node minNode = findMin(0,n-1,0,l,r);
	    	if(findGCD(0,n-1,0,l,r) == minNode.minValue)
	    		w.println(r - l + 1 - minNode.count);
	    	else
	    		w.println(r - l + 1);
	    }
	    
	    
	    w.close(); 
	}
	
	public static void buildMin(int s,int e,int c){
		if(s == e){
			segtreeMin[c] = new Node(a[s],1);
			return;
		}
		int m = (s + e) / 2;
		buildMin(s,m,2*c+1);
		buildMin(m+1,e,2*c+2);
		segtreeMin[c] = merge(segtreeMin[2*c+1],segtreeMin[2*c+2]);
	}
	
	public static Node merge(Node x,Node y){
		if(x.minValue < y.minValue)
			return x.copy();
		if(y.minValue < x.minValue)
			return y.copy();
		return new Node(x.minValue,x.count + y.count);
	}
	
	public static Node findMin(int s,int e,int c,int l,int r){
		if(s == l && e == r)
			return segtreeMin[c];
		int m = (s + e) / 2;
		if(r <= m)
			return findMin(s,m,2*c+1,l,r);
		if(l > m)
			return findMin(m+1,e,2*c+2,l,r);
		return merge( findMin(s,m,2*c+1,l,m) , findMin(m+1,e,2*c+2,m+1,r) );
	}
	
	public static void buildGCD(int s,int e,int c){
		if(s == e){
			segtreeGCD[c] = a[s];
			return;
		}
		int m = (s + e) / 2;
		buildGCD(s,m,2*c+1);
		buildGCD(m+1,e,2*c+2);
		segtreeGCD[c] = gcd(segtreeGCD[2*c+1],segtreeGCD[2*c+2]);
	}
	
	public static int findGCD(int s,int e,int c,int l,int r){
		if(s == l && e == r)
			return segtreeGCD[c];
		int m = (s + e) / 2;
		if(l <=m && r <= m)
			return findGCD(s,m,2*c+1,l,r);
		if(l > m && r > m)
			return findGCD(m+1,e,2*c+2,l,r);
		return gcd( findGCD(s,m,2*c+1,l,m) , findGCD(m+1,e,2*c+2,m+1,r) );
	}
	
	public static int gcd(int a,int b){
		int temp=0;
		while(b!=0){
			temp = b;
			b = a%b;
			a = temp;
		}
		return a;
	}

	
	public static int ip(String s){
		return Integer.parseInt(s);
	}

}

class Node {
	int minValue,count;
	Node(int mv,int c){
		this.minValue = mv;
		this.count = c;
	}
	Node copy(){
		return new Node(minValue,count);
	}
	public String toString(){
		return "count[" + minValue + "] = " + count ;
	}
}