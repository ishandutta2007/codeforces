import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class _600 {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		ArrayList<Node> l=new ArrayList<>(), r=new ArrayList<>();
		for (int i=0; i<n; i++) {
			int type=fs.nextInt();
			int w=fs.nextInt();
			Node nn=new Node(i);
			nn.w=w;
			if (type==0) {
				l.add(nn);
			}
			else {
				r.add(nn);
			}
		}
		
		int lP=0, rP=0;
		while (lP<l.size() && rP<r.size()) {
			Node a=l.get(lP), b=r.get(rP);
			int w=Math.min(a.w, b.w);
			System.out.println(a.id+1+" "+(b.id+1)+" "+w);
			a.w-=w;
			b.w-=w;
			if (a.w<b.w) {
				lP++;
			}
			else {
				rP++;
			}
		}
		while (lP+1<l.size()) {
			lP++;
			Node a=l.get(lP), b=r.get(rP-1);
			int w=Math.min(a.w, b.w);
			System.out.println(a.id+1+" "+(b.id+1)+" "+w);
		}
		while (rP+1<r.size()) {
			rP++;
			Node a=l.get(lP-1), b=r.get(rP);
			int w=Math.min(a.w, b.w);
			System.out.println(a.id+1+" "+(b.id+1)+" "+w);
		}
	}
	
	static class Node {
		int w, id;
		public Node(int id) {
			this.id=id;
		}
	}

	static void sort(int[] a) {
		ArrayList<Integer> l=new ArrayList<>();
		for (int i:a) l.add(i);
		Collections.sort(l);
		for (int i=0; i<a.length; i++) a[i]=l.get(i);
	}
	
	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");
		String next() {
			while (!st.hasMoreTokens())
				try {
					st=new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			return st.nextToken();
		}
		
		int nextInt() {
			return Integer.parseInt(next());
		}
		int[] readArray(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++) a[i]=nextInt();
			return a;
		}
		long nextLong() {
			return Long.parseLong(next());
		}
	}

	
}