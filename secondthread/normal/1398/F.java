import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Random;
import java.util.StringTokenizer;

/*
10
100??0010101
10 2 1 1 0 0 0 0 0 0 

6
00??00
 */

public class F {
	
	static int[] cs0, cs1, nextQ;

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		char[] line=fs.next().toCharArray();
		int[] a=new int[n];
		for (int i=0; i<n; i++) a[i]=(line[i]=='?')?-1:line[i]-'0';
		cs0=new int[n+1]; cs1=new int[n+1];
		for (int i=1; i<=n; i++) {
			cs0[i]=cs0[i-1]+((a[i-1]==-1||a[i-1]==0)?1:0);
			cs1[i]=cs1[i-1]+((a[i-1]==-1||a[i-1]==1)?1:0);
		}
		PrintWriter out=new PrintWriter(System.out);
		nextQ=new int[n];
//		int next=n;
		for (int i=n-1; i>=0; i--) {
//			nextQ[i]=next;
//			if (a[i]==-1) next=i;
			nextQ[i]=i+1;
		}
		for (int size=1; size<=n; size++) {
			int at=0;
			int ans=0;
			while (at!=n) {
				if (works(at, size)) {
					ans++;
					at+=size;
				}
				else {
					at=go(at, size);
				}
			}
			
			out.print(ans+" ");
		}
		out.println();
		out.close();
	}
	
	//return where next start is
	static int go(int index, int size) {
		if (index==nextQ.length) return index;
		if (works(index, size))
			return index;
		int candPos=nextQ[index];
		return nextQ[index]=go(candPos, size);
	}
	
	static boolean works(int from, int len) {
		if (from+len>=cs0.length) {
//			System.out.println("asdf");
			return false;
		}
		return works(from, from+len-1, cs0) || works(from, from+len-1, cs1);
	}
	
	static boolean works(int from, int to, int[] cs) {
		return cs[to+1]-cs[from]==(to-from+1);
	}
	
	
	static final Random random=new Random();
	
	static void ruffleSort(int[] a) {
		int n=a.length;//shuffle, then sort 
		for (int i=0; i<n; i++) {
			int oi=random.nextInt(n), temp=a[oi];
			a[oi]=a[i]; a[i]=temp;
		}
		Arrays.sort(a);
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