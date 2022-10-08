import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Random;
import java.util.StringTokenizer;

public class EBrute {
	
	static FastScanner fs;
	//TODO: don't fix seed before submitting!
	static Random random=new Random();
//	static Random random=new Random(5);
	static boolean local=false;

	public static void main(String[] args) {
		fs=new FastScanner();
		int n=fs.nextInt();
		if (n<93) {
			small(n);
			return;
		}
		else {
			big(n);
			return;
		}
	
//		int T=100;
//		for (int tt=0; tt<T; tt++) {
//			int n=3+random.nextInt(2045);
//			setup(n);
//			if (n<93) 
//				small(n);
//			else 
//				big(n);
//			if (nQueries>4269) throw null;
////			System.out.println("nQueries: "+nQueries);
//		}
//		System.out.println("All tests complete...");
		
	}
	
	static void setup(int n) {
		nQueries=0;
		CORRECT_ANSWER=perm(n);
	}
	
	static int[] CORRECT_ANSWER;
	static int nQueries=0;

//	static boolean works(int x) {
//		if (x*(x-1)/2>4269) return false;
//		return true;
//	}
	
	//n>=93
	static void big(int n) {
		int[] perm=perm(n);
		int cand1=0, cand2=1;
		int or=getOr(cand1, cand2, perm);
		for (int third=2; third<n; third++) {
			int _13=getOr(third, cand1, perm);
			//if this isn't a submask of 1 | 2, continue
			boolean submask = (_13 & (~or)) == 0;
			if (!submask) {
				//not helpful
				continue;
			}
			else {
				//hopefully this is rare
				int _23=getOr(third, cand2, perm);
				if (Integer.bitCount(_13)<Integer.bitCount(or) && Integer.bitCount(_13)<Integer.bitCount(_23)) {
					or=_13;
					cand2=third;
				}
				else if (Integer.bitCount(_23)<Integer.bitCount(or)) {
					or=_23;
					cand1=third;
				}
			}
		}
		
		//now we have zero and something else
		int zeroIndex=-1;
		while (zeroIndex==-1) {
			int thirdIndex=random.nextInt(n);
			if (thirdIndex==cand1 || thirdIndex==cand2) continue;
			int _13 = getOr(cand1, thirdIndex, perm);
			int _23 = getOr(cand2, thirdIndex, perm);
			if (_13 != _23) {
				zeroIndex=_13<_23?cand1:cand2;
			}
		}
		
		
		int[] answer=new int[n];
		answer[zeroIndex]=0;
		for (int i=0; i<n; i++) {
			if (i==zeroIndex) continue;
			answer[i]=getOr(i, zeroIndex, perm);
		}
		
		printAns(answer, perm);
	}
	
	static void small(int n) {
		int[][] ans=new int[n][n];
		for (int i=0; i<n; i++)
			for (int j=i+1; j<n; j++)
				ans[i][j]=ans[j][i]=getOrNoPerm(i, j);
		int[] a=new int[n];
		for (int i=0; i<n; i++) {
			a[i]=-1;
			for (int j=0; j<n; j++) if (i!=j) a[i]&=ans[i][j];
		}
		printAnsNoPerm(a);
	}
	
	static int getOrNoPerm(int i, int j) {
		if (local) {
			nQueries++;
			return CORRECT_ANSWER[i]|CORRECT_ANSWER[j];
		}
		else {
			System.out.println("? "+(i+1)+" "+(j+1));
			System.out.flush();
			int answer=fs.nextInt();
			return answer;
		}
	}
	
	static int getOr(int i, int j, int[] perm) {
		return getOrNoPerm(perm[i], perm[j]);
	}
	
	static void printAnsNoPerm(int[] ans) {
		if (local) {
			for (int i=0; i<ans.length; i++) if (ans[i]!=CORRECT_ANSWER[i]) throw null;
		}
		else {
			System.out.print("! ");
			for (int i:ans) System.out.print(i+" ");
			System.out.println();
			System.out.flush();
		}
	}
	
	static void printAns(int[] ans, int[] perm) {
		int n=ans.length;
		int[] res=new int[n];
		for (int i=0; i<n; i++) res[perm[i]]=ans[i];
		printAnsNoPerm(res);
	}
	
	static int[] perm(int n) {
		int[] a=new int[n];
		for (int i=0; i<n; i++) a[i]=i;
		for (int i=0; i<n; i++) {
			int oi=random.nextInt(n);
			int t=a[i];
			a[i]=a[oi];
			a[oi]=t;
		}
		return a;
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