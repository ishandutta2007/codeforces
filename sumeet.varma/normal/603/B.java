import java.io.*;
import java.util.*;

public class R334qBMoodularArithmetic {

	public static void main(String args[]) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter w = new PrintWriter(System.out);
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		int p = Integer.parseInt(st.nextToken());
		long k = Integer.parseInt(st.nextToken());
		
		if(k == 0){
			w.println(pow(p , p - 1 , (int)1e9 + 7));
			w.close();
			return;
		}
		
		if(k == 1){
			w.println(pow(p , p , (int)1e9 + 7));
			w.close();
			return;
		}
		
		DisjointSet ds = new DisjointSet(p);
		for(int i=0;i<p;i++)
			ds.merge(i, (int)((k * i) % p));
		
		w.println(pow(p,ds.comp - 1,(int)1e9 + 7));
		w.close();
	}
	
	public static long pow(int a,int b,int mod){
		if(b == 0)
			return 1;
		long t = pow(a , b / 2, mod);
		t = (t * t) % mod;
		if(b % 2 == 1)
			t = (t * a) % mod;
		return t;
	}
	
	static public class DisjointSet {

		public int rank[],parent[];
		public int n,comp;
		
		public DisjointSet(int n){
		    this.n = n;
			makeSet();
		}
		
		public void makeSet(){
			rank = new int[n];
			parent = new int[n];
			for(int i=0;i<n;i++)
				parent[i] = i;
			comp = n;
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
			
			if(rank[xRoot] < rank[yRoot])
				parent[xRoot] = yRoot;
			else{
				parent[yRoot] = xRoot;
				if(rank[xRoot] == rank[yRoot]){
					parent[yRoot] = xRoot;
					rank[xRoot]++;
				}
			}
			
			comp--;
		}
		
	}

}