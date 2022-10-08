import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;

public class D {

	static int[] factorOf=new int[1_000_000];
	
	public static void main(String[] args) {
		precomp();
		FastScanner fs=new FastScanner();
		int n=fs.nextInt(), q=fs.nextInt();
		int[] a=fs.readArray(n);
		
		//TODO: build next
		int[] next=new int[n];
		int nextEnd=n;
		int[] nextSeen=new int[1_000_000];
		Arrays.fill(nextSeen, n);
		for (int at=n-1; at>=0; at--) {
			ArrayList<Integer> factors=primeFactsOf(a[at]);
			for (int i:factors) nextEnd=Math.min(nextEnd, nextSeen[i]);
			next[at]=nextEnd;
			for (int i:factors) nextSeen[i]=at;
		}
		
		//TODO: build binary lifting
		int[][] lift=new int[20][n];
		lift[0]=next;
		for (int e=1; e<20; e++)
			for (int i=0; i<n; i++)
				if (lift[e-1][i]!=n)
					lift[e][i]=lift[e-1][lift[e-1][i]];
				else
					lift[e][i]=n;
		
		//TODO: printwriter
		PrintWriter out=new PrintWriter(System.out);
		//TODO: answer queries
		for (int qq=0; qq<q; qq++) {
			int l=fs.nextInt()-1, r=fs.nextInt()-1;
			int totalCuts=0;
			int maxLift=19;
			while (next[l]<=r) {
				while (lift[maxLift][l]>r) maxLift--;
				totalCuts+=1<<maxLift;
				l=lift[maxLift][l];
//				System.out.println(l+" "+r);
			}
			out.println(totalCuts+1);
		}
		out.close();
	}
	
	static ArrayList<Integer> primeFactsOf(int n) {
		ArrayList<Integer> toReturn=new ArrayList<>();
		while (n!=1) {
			toReturn.add(factorOf[n]);
			int added=factorOf[n];
			while (n%added==0) n/=added;
		}
		return toReturn;
	}
	
	static void precomp() {
		for (int i=2; i<factorOf.length; i++) {
			if (factorOf[i]!=0)
				continue;
			for (int j=i; j<factorOf.length; j+=i)
				factorOf[j]=i;
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