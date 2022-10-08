import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Random;
import java.util.StringTokenizer;

public class C {
	
	static int[][] precomp;
//	static String[][] pals;
	static int n;
	static int[][] dp;
static char[] line;
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		line=fs.next().toCharArray();
		n=line.length;
		precomp=new int[n][n];
//		pals=new String[n][n];
		for (int i=0; i<n; i++) {
			for (int j=i; j<n; j++) {
//				StringBuilder sb=new StringBuilder();
				for (int k=0; k+k<j-i+1; k++) {
					int len=j-i+1;
					if (line[i+k]!=line[i+len-1-k])
						precomp[i][j]++;
//					sb.append(line[i+k]);
				}
//				if ((j-i)%2==1) {
//					pals[i][j]=sb.toString()+sb.reverse().toString();
//				}
//				else {
//					pals[i][j]=sb.toString().substring(0, sb.length()-1) + sb.reverse().toString();
//				}
//				if (!isPal(pals[i][j])) throw null;
//				System.out.println(i+" "+j+" "+pals[i][j]);
//				if (pals[i][j].length()!=(j-i+1)) throw null;
			}
		}
		int k=fs.nextInt();
		dp=new int[n+1][n+1];
		for (int i=0; i<=n; i++) Arrays.fill(dp[i], -1);
		int ans=go(0, k);
		System.out.println(ans);
		buildback(0, k);
	}
	
//	static boolean isPal(String s) {
//		for (int i=0; i<s.length(); i++) {
//			if (s.charAt(i)!=s.charAt(s.length()-1-i)) return false;
//		}
//		return true;
//	}
	
	static int go(int index, int k) {
		if (k<0) return 1_000_000_000;
		if (index==n)
			return 0;
		if (dp[index][k]!=-1) return dp[index][k];
		int best=1_000_000_000;
		for(int toPlace=index; toPlace<n; toPlace++) {
			best=Math.min(best, precomp[index][toPlace]+go(toPlace+1, k-1));
		}
		return dp[index][k]=best;
	}
	
	static void buildback(int index, int k) {
//		if (k<0) throw null;
		if (index==n)
			return;
		int best=go(index, k);
		for(int toPlace=index; toPlace<n; toPlace++) {
			if (precomp[index][toPlace]+go(toPlace+1, k-1)==best) {
//				System.out.print(pals[index][toPlace]);
				StringBuilder sb=new StringBuilder();
				
				for (int i=0; i+i<(toPlace-index+1); i++) sb.append(line[index+i]);
				String pal;
				if ((toPlace-index)%2==1) {
					pal=sb.toString()+sb.reverse().toString();
				}
				else {
					pal=sb.toString().substring(0, sb.length()-1) + sb.reverse().toString();
				}
				System.out.print(pal);
				if (toPlace!=n-1) {
					System.out.print("+");
				}
				buildback(toPlace+1, k-1);
				return;
			}
		}
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