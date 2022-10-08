import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

/*
5
100
 */
public class C {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		int[] nWaysToGet=new int[20];
		for (int i=0; i<10; i++)
			for (int j=0; j<10; j++)
				nWaysToGet[i+j]++;
		
		for (int tt=0; tt<T; tt++) {
			char[] inp=fs.next().toCharArray();
			int[] endBits=new int[12];
			for (int i=0; i<12; i++) {
				endBits[i]=inp.length<=i?0:inp[inp.length-1-i]-'0';
			}
			long ans=0;
			for (int endMask=0; endMask<1<<12; endMask++) {
				if ((endMask&3)!=0) continue;
				long nWays=1;
				//check if potentially legal
				//count nWaysToDoIt
				for (int endPosition=0; endPosition<12; endPosition++) {
					//only a problem if we have a 1 carry bit, 0 sum bit
					int targetSum=((endMask&(1<<endPosition))!=0) ? endBits[endPosition]-1:endBits[endPosition];
					if (endPosition<10 && ((endMask&(1<<endPosition+2))!=0))
						targetSum+=10;
					if (targetSum<0) {
						nWays=0;
						break;
					}
					nWays*=nWaysToGet[targetSum];
				}
				ans+=nWays;
//				if (nWays!=0)
//					System.out.println("For endMask "+endMask+" got "+ans);
			}
			System.out.println(ans-2);
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