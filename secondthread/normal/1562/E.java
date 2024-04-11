import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Map;
import java.util.StringTokenizer;
import java.util.TreeMap;

/*
1
5
acbac

1
3
abc

1
10
abacabadac
1
8
acabacba
 */
public class E2 {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt();
			char[] line=(fs.next()).toCharArray();
			int[][] valueOfSubstring=new int[n][n];
			for (int i=0; i<n; i++)
				 Arrays.fill(valueOfSubstring[i], -1);
			int curInd=0;
			int[] sa=suffixArray(line);
			int[] indexOf=new int[n];
			for (int i=0; i<n; i++) indexOf[sa[i]]=i;
			int[] lcp=lcp(sa, line);
			int[] stk=new int[n+1];
			Arrays.fill(stk, -2);

			int[][] lcp2=new int[n][n];
			for (int i=0; i<n; i++) {
				int ans=n-sa[i];
				lcp2[sa[i]][sa[i]]=ans;
				for (int j=i+1; j<n; j++) {
					ans=Math.min(ans, lcp[j-1]);
					lcp2[sa[i]][sa[j]]=ans;
				}
			}
			int ans=0;
			int[] dp=new int[n];//if we build off the prefix starting here
			for (int start=n-1; start>=0; start--) {
				//build off any later prefix, but only if it's also after us in the SA
				int maxTransition=n-start;
				for (int to=start+1; to<n; to++) {
					if (indexOf[to]>indexOf[start]) {
						int lcpToLose=lcp2[start][to];
						int getFromMe=n-start;
						int getFromHim=dp[to];
//						System.out.println("Considering "+start+" "+to+" with "+lcpToLose+" "+getFromMe+" "+getFromHim);
						maxTransition=Math.max(maxTransition, getFromMe+getFromHim-lcpToLose);
					}
				}
				dp[start]=maxTransition;//TODO;
				ans=Math.max(ans, dp[start]);
			}
			System.out.println(ans);
		}
	}

//	static int lis(int[] a) {
//		int n=a.length;
//		TreeMap<Integer, Integer> map=new TreeMap<>();
//		int ans=0;
//		for (int i:a) {
//			Map.Entry<Integer, Integer> buildOff = map.lowerEntry(i);
//			int fromVal=buildOff==null?0:buildOff.getValue();
//			int myVal=fromVal+1;
//			while (true) {
//				Map.Entry<Integer, Integer> bigger= map.ceilingEntry(i);
//				if (bigger!=null && bigger.getValue()<=myVal) map.remove(bigger.getKey());
//				else break;
//			}
//			map.put(i, myVal);
//			ans=Math.max(ans, myVal);
//		}
//		return ans;
//	}
	
	// sort suffixes of S in O(n*log(n))
	static int[] suffixArray(char[] S) {
		int n=S.length;
		Integer[] order=new Integer[n];
		for (int i=0; i<n; i++)
			order[i]=n-1-i;

		// stable sort of characters //%
		Arrays.sort(order, (a, b)->Character.compare(S[a], S[b]));

		int[] sa=new int[n];
		int[] classes=new int[n];
		for (int i=0; i<n; i++) {
			sa[i]=order[i];
			classes[i]=S[i];
		}
		// sa[i] - suffix on i'th position after sorting by first len characters //%
		// classes[i] - equivalence class of the i'th suffix after sorting by first len
		// characters //%

		for (int len=1; len<n; len*=2) {
			int[] c=classes.clone();
			for (int i=0; i<n; i++) {
				// condition sa[i - 1] + len < n simulates 0-symbol at the end of the string //%
				// a separate class is created for each suffix followed by simulated 0-symbol
				// //%
				classes[sa[i]]=i>0&&c[sa[i-1]]==c[sa[i]]&&sa[i-1]+len<n&&c[sa[i-1]+len/2]==c[sa[i]+len/2]
						?classes[sa[i-1]]
						:i;
			}
			// Suffixes are already sorted by first len characters //%
			// Now sort suffixes by first len * 2 characters //%
			int[] cnt=new int[n];
			for (int i=0; i<n; i++)
				cnt[i]=i;
			int[] s=sa.clone();
			for (int i=0; i<n; i++) {
				// s[i] - order of suffixes sorted by first len characters //%
				// (s[i] - len) - order of suffixes sorted only by second len characters //%
				int s1=s[i]-len;
				// sort only suffixes of length > len, others are already sorted //%
				if (s1>=0)
					sa[cnt[classes[s1]]++]=s1;
			}
		}
		return sa;
	}

	// longest common prefixes array in O(n)
	static int[] lcp(int[] sa, char[] s) {
		int n=sa.length;
		int[] rank=new int[n];
		for (int i=0; i<n; i++)
			rank[sa[i]]=i;
		int[] lcp=new int[n-1];
		for (int i=0, h=0; i<n; i++) {
			if (rank[i]<n-1) {
				for (int j=sa[rank[i]+1]; Math.max(i, j)+h<s.length&&s[i+h]==s[j+h]; ++h)
					;
				lcp[rank[i]]=h;
				if (h>0)
					--h;
			}
		}
		return lcp;
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