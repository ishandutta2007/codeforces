import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Random;
import java.util.StringTokenizer;
/*
2
1123465
10000000

3
123
123465
10000000

2
7 7
 */
public class B {
	static int maxPOW=27;
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		int[] a=fs.readArray(n);

//		int T=100;
		int T=1;
		for (int tt=0; tt<T; tt++) {
//			int n=1+r.nextInt(100);
//			int[] a=genArray(n);
			long ans=0;
			for (int power=1; power<maxPOW; power++) {
				long count=0;
				int[] values=new int[n];
				int cutoff=1<<(power-1), mod=cutoff*2;
				for (int i=0; i<n; i++) values[i]=a[i]&(mod-1);
				int[] cs=new int[mod];
				for (int i:values) cs[i]++;
				for (int i=1; i<cs.length; i++) cs[i]+=cs[i-1];
		
				for (int l=0; l<cutoff; l++) {
					int r2=(mod)-l-1;
					int r1=Math.max(l+1, r2-(cutoff)+1);
					int csl=cs[l]-(l==0?0:cs[l-1]);
					if (l*2>=cutoff) {
						long at=csl;
						count+=(at*(at-1))/2;
					}
					if (r1<=r2) {
						long baseAdd=csl*(cs[r2]-cs[r1-1]);
						count+=baseAdd;
						if (csl!=0) {
//								System.out.println(" "+l+" "+r1+" "+r2);
//								System.out.println("  After left "+l+" count: "+count+" "+baseAdd);
						}
					}
				}
				cutoff+=mod;
				int maxCuttoff=2*mod;
				for (int l=mod/2; l<mod; l++) {
					int r2=(maxCuttoff)-l-1;
					int r1=Math.max(l+1, cutoff-l);
					int csl=cs[l]-(l==0?0:cs[l-1]);
					if (l*2>=cutoff && l*2<maxCuttoff) {
						long at=csl;
						count+=(at*(at-1))/2;
					}
					r2=Math.min(r2, mod-1);
					if (r1<=r2) {
						long baseAdd=csl*(cs[r2]-cs[r1-1]);
						count+=baseAdd;
						if (csl!=0) {
//								System.out.println(" "+l+" "+r1+" "+r2);
//								System.out.println("  After left "+l+" count: "+count+" "+baseAdd);
						}
					}
				}
//					System.out.println("For power "+power+" values: "+Arrays.toString(values)+" count "+count);
				if (count%2==1) ans+=1<<(power-1);
				
			}
//			int bf=bf(a, n);
//			if (ans!=bf) {
//				System.out.println(ans+" "+bf);
//				System.out.println(Arrays.toString(a));
//				throw null;
//			}
			System.out.println(ans);
		}
//		System.out.println("Tests passed");
	}
	
	static int bf(int[] a, int n) {
		int ans=0;
		for (int i=0; i<n; i++) {
			for (int j=i+1; j<n; j++) {
				ans^=a[i]+a[j];
			}
		}
		return ans;
	}
	
	static Random r=new Random(5);
	static int[] genArray(int n) {
		int[] a=new int[n];
		for (int i=0; i<n; i++) a[i]=r.nextInt(10000_000);
		return a;
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