import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class E {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		ArrayList<Integer> a=new ArrayList<>();
		for (int i=0; i<n; i++)
			a.add(fs.nextInt());

		Collections.sort(a);

		ArrayList<Long> distanceToSquare=new ArrayList<>();
		long squareRootBefore=0, squareRootAfter=1;
		for (int i:a) {
			while (squareRootAfter*squareRootAfter<=i) {
				squareRootBefore++;
				squareRootAfter++;
			}
			distanceToSquare.add((long) Math.min(Math.abs(i-squareRootBefore*squareRootBefore),
					Math.abs(i-squareRootAfter*squareRootAfter)));
		}
		Collections.sort(distanceToSquare);
		// System.out.println(distanceToSquare);

		int zeroCount=0;
		for (long i:distanceToSquare)
			if (i==0)
				zeroCount++;
		if (zeroCount<=n/2) {
			long total=0;
			for (int i=0; i<n/2; i++) {
				total+=distanceToSquare.get(i);
			}
			System.out.println(total);
			return;
		}

		int numZeros=0;
		for (int i:a)
			if (i==0)
				numZeros++;
		int numNonZeros=zeroCount-numZeros;
		long total=0;
		int toRemove=zeroCount-n/2;
		while (toRemove>0) {
			if (numNonZeros>0) {
				numNonZeros--;
				total++;
			}
			else {
				numZeros--;
				total+=2;
			}
			toRemove--;
		}
		System.out.println(total);
	}

	public static class FastScanner {
		BufferedReader br;
		StringTokenizer st;
		public FastScanner() {
			try {
				br=new BufferedReader(new InputStreamReader(System.in));
				// br = new BufferedReader(new FileReader("testdata.out"));
				st=new StringTokenizer("");
			} catch (Exception e) {
				e.printStackTrace();
			}
		}
		public String next() {
			if (st.hasMoreTokens())
				return st.nextToken();
			try {
				st=new StringTokenizer(br.readLine());
			} catch (Exception e) {
				e.printStackTrace();
			}
			return st.nextToken();
		}
		public int nextInt() {
			return Integer.parseInt(next());
		}
		public long nextLong() {
			return Long.parseLong(next());
		}
		public double nextDouble() {
			return Double.parseDouble(next());
		}

		public String nextLine() {
			String line="";
			try {
				line=br.readLine();
			} catch (Exception e) {
				e.printStackTrace();
			}
			return line;
		}
	}

}