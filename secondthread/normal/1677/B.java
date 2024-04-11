import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Random;
import java.util.StringTokenizer;

/*



 */
public class B {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		PrintWriter out=new PrintWriter(System.out);
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			int h=fs.nextInt(), w=fs.nextInt();
			char[] line=fs.next().toCharArray();
			int[] cs=new int[line.length+1];
			for (int i=1; i<cs.length; i++) cs[i]=cs[i-1]+(line[i-1]-'0');
			long[] rowAnswersDetas=new long[line.length+w];
			boolean[] anyInCol=new boolean[line.length];
			long[] colAnswerDeltas=new long[line.length+w];
			//count row contribution
			{
				for (int end=0; end<line.length; end++){
					int start=Math.max(0, end-w+1);
					if (hasAny(start, end, cs)) {
						//update now until forever if we haven't yet
						rowAnswersDetas[end]++;
					}
				}

			}
			
			//count col contribution
			{
				for (int i=0; i<line.length; i++) {
					boolean colFilled=line[i]=='1';
					if (i>=w)
						colFilled |= anyInCol[i-w];
					anyInCol[i]=colFilled;
					if (anyInCol[i]) {
						colAnswerDeltas[i]++;
						colAnswerDeltas[i+w]--;
					}
				}
			}
			for (int i=1; i<colAnswerDeltas.length; i++) {
				colAnswerDeltas[i]+=colAnswerDeltas[i-1];
			}
			for (int i=w; i<rowAnswersDetas.length; i++) {
				rowAnswersDetas[i]+=rowAnswersDetas[i-w];
			}
			// System.out.println("Row answers "+Arrays.toString(rowAnswersDetas));
			for (int i=0; i<line.length; i++) {
				out.print(rowAnswersDetas[i]+colAnswerDeltas[i]+" ");
			}
			out.println();
		}
		out.close();
	}

	static boolean hasAny(int l, int r, int[] cs) {
		return cs[r+1]-cs[l]>0;
	}
	
	static final Random random=new Random();
	static final int mod=998244353;
	
	static void ruffleSort(int[] a) {
		int n=a.length;//shuffle, then sort 
		for (int i=0; i<n; i++) {
			int oi=random.nextInt(n), temp=a[oi];
			a[oi]=a[i]; a[i]=temp;
		}
		Arrays.sort(a);
	}
	static long add(long a, long b) {
		return (a+b)%mod;
	}
	static long sub(long a, long b) {
		return ((a-b)%mod+mod)%mod;
	}
	static long mul(long a, long b) {
		return (a*b)%mod;
	}
	static long exp(long base, long exp) {
		if (exp==0) return 1;
		long half=exp(base, exp/2);
		if (exp%2==0) return mul(half, half);
		return mul(half, mul(half, base));
	}
	static long[] factorials=new long[2_000_001];
	static long[] invFactorials=new long[2_000_001];
	static void precompFacts() {
		factorials[0]=invFactorials[0]=1;
		for (int i=1; i<factorials.length; i++) factorials[i]=mul(factorials[i-1], i);
		invFactorials[factorials.length-1]=exp(factorials[factorials.length-1], mod-2);
		for (int i=invFactorials.length-2; i>=0; i--)
			invFactorials[i]=mul(invFactorials[i+1], i+1);
	}
	
	static long nCk(int n, int k) {
		return mul(factorials[n], mul(invFactorials[k], invFactorials[n-k]));
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