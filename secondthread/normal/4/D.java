import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class A {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		int w0=fs.nextInt(), h0=fs.nextInt();
		En[] ens=new En[n+1];
		En base=ens[n]=new En(w0, h0, -1);
		for (int i=0; i<n; i++) ens[i]=new En(fs.nextInt(), fs.nextInt(), i);
		Arrays.sort(ens);
		n++;
		for (int i=n-1; i>=0; i--) {
			for (int j=i+1; j<n; j++) {
				ens[i].tryFit(ens[j]);
			}
		}
		System.out.println(base.length-1);
		ArrayList<Integer> toPrint=new ArrayList<>();
		while (base!=null) {
			toPrint.add(base.id);
			base=base.next;
		}
		for (int i=1; i<toPrint.size(); i++) {
			System.out.print(toPrint.get(i)+1+" ");
		}
		System.out.println();
	}
	
	static class En implements Comparable<En> {
		int w, h, id;
		En next=null;
		int length=1;
		
		public En(int w, int h, int id) {
			this.w=w; this.h=h;
			this.id=id;
		}
		
		public int compareTo(En o) {
			return Integer.compare(w, o.w);
		}
		
		public void tryFit(En o) {
			if (o.w>w && o.h>h && o.length>=length) {
				length=o.length+1;
				next=o;
			}
		}
	}
	
	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");
		
		public String next() {
			while (!st.hasMoreTokens())
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
		
		public int[] readArray(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++) a[i]=nextInt();
			return a;
		}
		
		public long nextLong() {
			return Long.parseLong(next());
		}
		
		public long[] readLongArray(int n) {
			long[] a=new long[n];
			for (int i=0; i<n; i++) a[i]=nextLong();
			return a;
		}
	}

}