import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.StringTokenizer;
/*
1
10000000000000001
 */
public class C {
	
	static HashSet<Integer> used=new HashSet<>();
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		PrintWriter out=new PrintWriter(System.out);
		for (int tt=0; tt<T; tt++) {
			long target=fs.nextLong();
			target--;
			long layer=target/3;
			if (target%3==0) {
				out.println(solveFirst(layer));
			}
			else if (target%3==1) {
				out.println(solveSecond(layer));
			}
			else {
				out.println(solveThird(layer));
			}
		}
		out.close();
	}
	
	static long solveFirst(long group) {
		int power=0;
		while (true) {
			long min=1l<<power;
			long max=(1l<<(power+1))-1;
			long size=max-min+1;
			if (group<size) {
				return min+group;
			}
			else {
				group-=size;
			}
			power+=2;
		}
	}
	
	static long solveSecond(long group) {
		int power=0;
		while (true) {
			long min=1l<<(power+1);
			long max=min+(1l<<power)-1;
			long size=max-min+1;
			if (group<size) {
				long converted=convert(group);
//				System.out.println("Converted "+group+" into "+converted);
				return min+converted;
			}
			else {
				group-=size;
			}
			power+=2;
		}
	}
	
	static long solveThird(long group) {
		long first=solveFirst(group), second=solveSecond(group);
		return first^second;
	}
	
	static long convert(long orig) {
		long[] base4=new long[31];
		int index=0;
		while (orig!=0) {
			base4[index++]=orig%4;
			orig/=4;
		}
		long ans=0;
		final int[] conv= {0, 2, 3, 1};
		for (int i=base4.length-1; i>=0; i--) {
			ans*=4;
			ans+=conv[(int)base4[i]];
		}
		return ans;
	}
	
	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");

		public String next() {
			while (!st.hasMoreElements())
				try {
					st=new StringTokenizer(br.readLine());
				} catch (IOException e) {
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

		public int[] readArray(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++) {
				a[i]=nextInt();
			}
			return a;
		}

		public double nextDouble() {
			return Double.parseDouble(next());
		}

	}
	
}