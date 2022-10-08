import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;

/*
1
3
aab
bcc

1
3
abc
tsr
 */
public class A {
	
	public static void main(String[] args) throws InterruptedException {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		outer: for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt();
			char[] a=fs.next().toCharArray(), b=fs.next().toCharArray();
			int[][] counts=new int[26][26];
			int[] ofInA=new int[26];
			for (char c:a) ofInA[c-'a']++;
			
			for (int i=0; i<n; i++) {
				if (a[i]>b[i]) {
					System.out.println(-1);
					continue outer;
				}
			}
			
			int moves=0;
			for (int i=0; i<n; i++)
				counts[a[i]-'a'][b[i]-'a']++;
			for (int from=0; from<26; from++) {
				ofInA[from]-=counts[from][from];
				counts[from][from]=0;
//				System.out.println("Of in a: "+Arrays.toString(ofInA));
				if (ofInA[from]==0) continue;
				moves++;
				int to=from+1;
				while (counts[from][to]==0) to++;
//				System.out.println("Moving from "+from+" to "+to);
				for (int i=0; i<26; i++) {
					int toMove=counts[from][i];
//					if (toMove!=0) System.out.println("moving "+toMove+" from "+from+" to "+to+" "+i);
					counts[from][i]-=toMove;
					counts[to][i]+=toMove;
					ofInA[from]-=toMove;
					ofInA[to]+=toMove;
//					System.out.println("Incrementing counts at "+to+" by "+toMove+" "+ofInA[to]);
				}
			}
			
			System.out.println(moves);
		}
	}
	
	void sort(int[] a) {
		ArrayList<Integer> list=new ArrayList<>();
		for (int i:a) list.add(i);
		Collections.sort(list);
		for (int i=0; i<a.length; i++) a[i]=list.get(i);
	}
	
	
	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");
		
		public String next() {
			while (!st.hasMoreTokens())
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
		
		public int[] readArray(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++) a[i]=nextInt();
			return a;
		}
		
		public long nextLong() {
			return Long.parseLong(next());
		}
		
		public long[] readLongArray(int n) {
			long[] a=new long[n];
			for (int i=0; i<n; i++) a[i]=nextLong();
			return a;
		}
	}

}