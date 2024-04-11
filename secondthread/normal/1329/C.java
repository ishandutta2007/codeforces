import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class C {
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		PrintWriter out=new PrintWriter(System.out);
		for (int tt=0; tt<T; tt++) {
			int initialHeight=fs.nextInt();
			int finalHeight=fs.nextInt();
			int[] orig=new int[1<<initialHeight];
			int[] end=new int[1<<finalHeight];
			for (int i=1; i<1<<initialHeight; i++)
				orig[i]=fs.nextInt();
			Entry[] entries=new Entry[(1<<initialHeight)-1];
			for (int i=1; i<1<<initialHeight; i++)
				entries[i-1]=new Entry(i, orig[i]);
			Arrays.sort(entries);
			long total=0;
			for (Entry e:entries) {
				int at=e.index;
				int val=e.value;
				while (at>=end.length)
					at/=2;
				while (at!=0 && end[at]!=0)
					at/=2;
				int lChild=at*2;
				int rChild=at*2+1;
				if ((lChild<end.length && end[lChild]==0) || (rChild<end.length && end[rChild]==0)) {
					e.used=false;
				}
				else {
					e.used=true;
					end[at]=val;
					total+=val;
				}
			}
			out.println(total);
			for (Entry e:entries) {
				if (!e.used) {
					out.print(e.index+" ");
				}
			}
			out.println();
		}
		out.close();
	}
	
	static class Entry implements Comparable<Entry> {
		int index;
		int value;
		boolean used=false;
		public Entry(int index, int value) {
			this.index=index;
			this.value=value;
		}
		
		public int compareTo(Entry o) {
			return Integer.compare(value, o.value);
		}
		
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