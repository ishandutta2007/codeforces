

import java.beans.PersistenceDelegate;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class B {
	
	static int[][][] appearsKAfter;
	static int[] string;
	
	public static void solve(FastScanner fs) {	
		String next=fs.next();
		string=new int[next.length()];
		for (int i=0; i<next.length(); i++)
			string[i]=next.charAt(i)-'a';
		appearsKAfter=new int[26][26][next.length()];
		precomp();
		int[] cs=new int[26];
		for (int i:string)
			cs[i]++;
		
		double total=0;
		
		//brute force all possible numbers I could be given
		for (int numberGiven=0; numberGiven<26; numberGiven++) {
			if (cs[numberGiven]==0)
				continue;
			
			double chanceOfBeingGivenThisNumber=cs[numberGiven]/(double)string.length;
			double highestPercentage=0;
			
			//look at all my choices and pick the best one
			for (int offsetPicked=1; offsetPicked<string.length; offsetPicked++) {
				double percentCorrect=0;
				
				//for each choice, consider all of the numbers it could result in
				for (int otherNumber=0; otherNumber<26; otherNumber++) {
					if (appearsKAfter[numberGiven][otherNumber][offsetPicked]==0)
						continue;
					double chanceOfOther=appearsKAfter[numberGiven][otherNumber][offsetPicked]/(double)(cs[numberGiven]);
					percentCorrect+=chanceOfOther*(1/appearsKAfter[numberGiven][otherNumber][offsetPicked]);
//					System.out.println("chance of other "+otherNumber+" is "+chanceOfOther+", successRate for other: "+(1/appearsKAfter[numberGiven][otherNumber][offsetPicked]));
				}
//				System.out.println("for numGiven: "+numberGiven+", offset: "+offsetPicked+", percentCorrect: "+percentCorrect);
				highestPercentage=Math.max(highestPercentage, percentCorrect);
			}
			total+=highestPercentage*chanceOfBeingGivenThisNumber;
		}
		System.out.println(total);
	}

	private static void precomp() {
		for (int i=0; i<string.length; i++) {
			for (int j=1; j<string.length; j++) {
				int first=string[i], second=string(i+j);
				appearsKAfter[first][second][j]++;
			}
		}
	}
	
	private static int string(int i) {
		return string[i%string.length];
	}
	
	
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		FastScanner scanner = new FastScanner(System.in);
		solve(scanner);
	}
	

	private static class FastScanner {
		BufferedReader br;
		StringTokenizer st;
		public FastScanner(InputStream in) {
			br = new BufferedReader(new InputStreamReader(in));
		}
		String next() {
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}
		int nextInt() {
			return Integer.parseInt(next());
		}
		long nextLong() {
			return Long.parseLong(next());
		}
		double nextDouble() {
			return Double.parseDouble(next());
		}
		String nextLine() {
			String str = "";
			try {
				str = br.readLine();
			} catch (IOException e) {
				e.printStackTrace();
			}
			return str;
		}
		int[] readArray(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++)
				a[i]=nextInt();
			return a;
		}
		long[] readLongArray(int n) {
			long[] a=new long[n];
			for (int i=0; i<n; i++)
				a[i]=nextLong();
			return a;
		}
	}
}