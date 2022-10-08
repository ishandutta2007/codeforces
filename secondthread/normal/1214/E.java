import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class E {
	static PrintWriter out;

	public static void main(String[] args) {
		//TODO: fast output
		out=new PrintWriter(System.out);
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		Pair[] pairs=new Pair[n];
		for (int i=0; i<n; i++)
			pairs[i]=new Pair(i, fs.nextInt());
		Arrays.sort(pairs);
		ArrayList<Integer> chains=new ArrayList<>();
		for (int i=0; i<n; i++)
			chains.add(pairs[i].ind1);
		for (int i=0; i+1<n; i++)
			print(chains.get(i), chains.get(i+1));
		for (int i=0; i<n; i++) {
			if (pairs[i].distance==chains.size()-i) {
				chains.add(pairs[i].ind2);
				print(chains.get(chains.size()-1), chains.get(chains.size()-2));
			}
			else {
				print(pairs[i].ind2, chains.get(i+pairs[i].distance-1));
			}
		}
		out.close();
	}	
	
	static void print(int i, int j) {
		out.println(i+1+" "+(j+1));
	}
	
	static class Pair implements Comparable<Pair> {
		int ind1, ind2, distance;
		public Pair(int ind, int distance) {
			this.ind1=ind*2;
			this.ind2=ind*2+1;
			this.distance=distance;
		}
		
		public int compareTo(Pair o) {
			return -Integer.compare(distance, o.distance);
		}
	}

	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");
		public String next() {
			while(!st.hasMoreElements())
				try {
					st=new StringTokenizer(br.readLine());
				} catch (IOException e) {
				}
			return st.nextToken();
		}
		
		public int nextInt() {
			return Integer.parseInt(next());
		}
	}
}