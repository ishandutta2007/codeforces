import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Temp {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		int[] a=fs.readArray(n);
		int[] freq=new int[1_000_000];
		for (int i:a) freq[i]++;
		BIT bit=new BIT(1_000_000);
		for (int i:freq) bit.update(i, 1);
		int nQueries=fs.nextInt();
		PrintWriter out=new PrintWriter(System.out);
//		for (int i=0; i<10; i++) {
//			System.out.println(i+" "+bit.after(i));
//		}
		for (int qq=0; qq<nQueries; qq++) {
			char type=fs.next().charAt(0);
			int val=fs.nextInt();
			int oldFreq=freq[val];
			int newFreq=freq[val]+(type=='-'?-1:1);
//			System.out.println("OldFreq "+oldFreq+" newFreq"+newFreq);
			bit.update(oldFreq, -1);
			bit.update(newFreq, 1);
			freq[val]=newFreq;
			
//			System.out.println("Query "+qq);
//			for (int i=0; i<10; i++) {
//				System.out.println(i+" "+bit.after(i));
//			}
			
			boolean possible=bit.after(8)>0;
			possible|=bit.after(6)>0 && bit.after(2)>1;
			possible|=bit.after(4)>1;
			possible|=bit.after(4)>0 && bit.after(2)>2;
			out.println(possible?"YES":"NO");
		}
		out.close();
	}
	
	static class BIT {
		int n;
		int[] tree;
		
		public BIT(int n) {
			this.n = n;
			tree = new int[n + 2];
		}
		
		int read(int i) {
			i++;
			int sum = 0;
			while (i > 0) {
				sum += tree[i];
				i -= i & -i;
			}
			return sum;
		}
		
		int after(int i) {
			return read(n)-read(i-1);
		}
		
		void update(int i, int val) {
			i++;
			while (i <= n) {
				tree[i] += val;
				i += i & -i;
			}
		}

		// if the BIT is a freq array, returns the
		// index of the kth item, or n if there are fewer
		// than k items.
		int getKth(int k) {
			int e=Integer.highestOneBit(n), o=0;
			for (; e!=0; e>>=1) {
				if (e+o<=n && tree[e+o]<=k) {
					k-=tree[e+o];
					o+=e;
				}
			}
			return o;
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
		
		int nextInt() {
			return Integer.parseInt(next());
		}
		
		int[] readArray(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++) a[i]=nextInt();
			return a;
		}
	}

}