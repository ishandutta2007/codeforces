import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class G2 {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		s=fs.next().toCharArray();
		t=fs.next().toCharArray();
		int n=s.length;
		
		//-1 if it never happens, or i if we could then start at i
		nextCounterZero=new int[n];
		//can make this linear I think
		outer: for (int start=0; start<n; start++) {
			int counter=0;
			if (s[start]=='.') {
				nextCounterZero[start]=-1;
				continue;
			}
			counter++;
			for (int i=start+1; i<n; i++) {
				if (s[i]=='.') {
					counter--;
					if (counter==0) {
						nextCounterZero[start]=i+1;
						continue outer;
					}
				}
				else {
					counter++;
				}
			}
			nextCounterZero[start]=-1;
		}
		int[][] dp=new int[1_000_5][1_000_5];
		for (int i=0; i<dp.length; i++) {
			dp[s.length][i]=i==t.length?0:oo;
		}
		for (int sIndex=s.length-1; sIndex>=0; sIndex--) {
			for (int tIndex=t.length; tIndex>=0; tIndex--) {
				int best=oo;
				if (tIndex<t.length && s[sIndex]==t[tIndex]) {
					//take from both
					best=min(best, dp[sIndex+1][tIndex+1]);
				}
				//delete the next thing in s
				best=min(best, 1+dp[sIndex+1][tIndex]);
				
				if (nextCounterZero[sIndex]!=-1) {
					best=min(best, dp[nextCounterZero[sIndex]][tIndex]);
				}
				dp[sIndex][tIndex]=best;
			}
		}
		
		
		int ans=dp[0][0];
		System.out.println(ans);
	}
	
	static final int oo=(int) 1e9;
	static char[] s;
	static char[] t;
	static int[] nextCounterZero;
	
	static int min(int a, int b) {
		return a<b?a:b;
	}
	
//	static int go(int sIndex, int tIndex) {
//		if (sIndex==s.length) {
//			if (tIndex==t.length) {
//				return 0;
//			}
//			else {
//				return oo;
//			}
//		}
//		int best=oo;
//		if (tIndex<t.length && s[sIndex]==t[tIndex]) {
//			//take from both
//			best=Math.min(best, go(sIndex+1, tIndex+1));
//		}
//		//delete the next thing in s
//		best=Math.min(best, 1+go(sIndex+1, tIndex));
//		
//		if (nextCounterZero[sIndex]!=-1) {
//			best=Math.min(best, go(nextCounterZero[sIndex], tIndex));
//		}
//		return best;
//	}

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