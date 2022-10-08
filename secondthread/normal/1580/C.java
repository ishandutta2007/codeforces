import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Random;
import java.util.StringTokenizer;

public class C {
	static int SQRT=450;
//	static int SQRT=2;

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		PrintWriter out=new PrintWriter(System.out);
		int nTypes=fs.nextInt();
		int nQueries=fs.nextInt();
		int[] as=new int[nTypes], bs=new int[nTypes];
		for (int i=0; i<nTypes; i++) {
			as[i]=fs.nextInt();
			bs[i]=fs.nextInt();
		}
		int[] deltas=new int[nQueries];
		//modVal, curMod = offset
		int[][] smallOffset=new int[SQRT][SQRT];
		int[] initiallyAddedAt=new int[nTypes];
		int sum=0;
		int nAlive=0;
		for (int qq=0; qq<nQueries; qq++) {
			int multiplier=fs.nextInt()==1?1:-1;
			int type=fs.nextInt()-1;
			nAlive+=multiplier;
			int a=as[type], b=bs[type];
			int mod=a+b;
			int startVal=qq;
			if (multiplier==-1)
				startVal=initiallyAddedAt[type];
			else
				initiallyAddedAt[type]=qq;
			
			if (mod<SQRT) {
				int curVal=startVal%mod;
				for (int i=0; i<a; i++) {
					smallOffset[mod][curVal]+=multiplier;
					curVal=curVal==mod-1?0:curVal+1;
				}	
				
			}
			else {
				if (multiplier==-1 && (qq-startVal)%mod!=0 && (qq-startVal)%mod<=a) {
					sum--;
//					System.out.println("Subtracting from sum");
				}
//				else {
//					System.out.println(multiplier+" "+qq+" "+startVal+" "+mod+" "+a);
//				}
				for (int start=startVal; start<nQueries; start+=mod) {
					deltas[start]+=multiplier;
					if (start+a<nQueries) deltas[start+a]-=multiplier;
				}
			}
			sum+=deltas[qq];
//			System.out.println("Deltas "+Arrays.toString(deltas)+" "+sum);
			int curAns=sum;
			for (mod=2; mod<SQRT; mod++) {
				curAns+=smallOffset[mod][qq%mod];
			}
			out.println(nAlive-curAns);
		}
		out.close();
	}
	static class Pair {
		int x, y;
		public Pair(int x, int y) {
				this.x=x;
				this.y=y;
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