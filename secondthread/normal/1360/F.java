import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class F {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		outer: for (int tt=0; tt<T; tt++) {
			int nStrings=fs.nextInt(), len=fs.nextInt();
			char[][] strings=new char[nStrings][];
			for (int i=0; i<nStrings; i++) strings[i]=fs.next().toCharArray();
			for (int baseStr=0; baseStr<nStrings; baseStr++) {
				nextCand: for (int changeInd=0; changeInd<len; changeInd++) {
					boolean[] needsToBe=new boolean[26];
					for (int otherString=0; otherString<nStrings; otherString++) {
						if (otherString==baseStr) continue;
						int nMisses=0;
						for (int i=0; i<len; i++) {
							if (i==changeInd) continue;
							if (strings[otherString][i]!=strings[baseStr][i]) nMisses++;
						}
						if (nMisses>1) continue nextCand;
						if (nMisses==0) continue;
						needsToBe[strings[otherString][changeInd]-'a']=true;
					}
					int needCount=0;
					char needVal='a';
					for (int i=0; i<26; i++) {
						if (needsToBe[i]) {
							needVal=(char)('a'+i);
							needCount++;
						}
					}
					if (needCount<=1) {
						for (int i=0; i<len; i++) {
							if (i==changeInd) {
								System.out.print(needVal);
							}
							else {
								System.out.print(strings[baseStr][i]);
							}
						}
						System.out.println();
						continue outer;
					}
				}
			}
			
			System.out.println(-1);
		}
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