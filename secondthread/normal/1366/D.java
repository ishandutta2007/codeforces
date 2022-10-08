import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class D {

	static int[] factorOf=new int[1_100_000_0];
	
	public static void main(String[] args) {
		precomp();
		FastScanner fs=new FastScanner();
		int qq=fs.nextInt();
//		int qq=1000;
		int[] ans1s=new int[qq], ans2s=new int[qq];
		outer: for (int q=0; q<qq; q++) {
			int n=fs.nextInt();
//			int n=q+2;
			ArrayList<Integer> primes=new ArrayList<>();
			int at=n;
			while (factorOf[at]!=0) {
				int fact=factorOf[at];
				while (at%fact==0) at/=fact;
				primes.add(fact);
			}
			int num1=primes.get(0);
			int num2=n;
			while (num2%num1==0) num2/=num1;
			
			if (gcd(num1+num2, n) !=1) {
				System.out.println("Broke on "+n);
				throw null;
			}
			if (Math.min(num1, num2)<=1) {
				ans1s[q]=ans2s[q]=-1;
			}
			else {
				ans1s[q]=num1;
				ans2s[q]=num2;
				continue outer;
			}
//			for (int i:primes) {
//				for (int j:primes) {
//					if (gcd(i+j, n)==1) {
//						ans1s[q]=i;
//						ans2s[q]=j;
//						continue outer;
//					}
//				}
//			}
//			for (int i=2; i<n; i++) {
//				for (int j=2; j<n; j++) {
//					if (n%i!=0 || n%j!=0) continue;
//					if (gcd(i+j, n) == 1) {
//						System.out.println("FOUND "+i+" "+j+" for "+n);
////						return;
//					}
//				}	
//			}
//			ans1s[q]=ans2s[q]=-1;
		}
		PrintWriter out=new PrintWriter(System.out);
		for (int i=0; i<qq; i++) out.print(ans1s[i]+" ");
		out.println();
		for (int i=0; i<qq; i++) out.print(ans2s[i]+" ");
		out.println();
		out.close();
	}
	
	static int gcd(int a, int b) {
		if (b==0) return a;
		return gcd(b, a%b);
	}
	
	static void precomp() {
		for (int i=2; i<factorOf.length; i++) {
			if (factorOf[i]!=0) continue;
			for (int j=i; j<factorOf.length; j+=i) factorOf[j]=i;
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