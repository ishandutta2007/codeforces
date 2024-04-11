

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class C {

	
	public static void solve(FastScanner fs) {	
		int n=fs.nextInt()-1;
		boolean[][] guesses=new boolean[n][26];
		boolean[] possible=new boolean[26];
		boolean[] gotShockOnTurn=new boolean[n];
		boolean[] wasGuess=new boolean[n];
		int numberOfShocks=0;
		for (int i=0; i<n; i++) {
			String guessType=fs.next();
			gotShockOnTurn[i]=!guessType.equals(".");
			wasGuess[i]=guessType.equals("?");
			if (gotShockOnTurn[i])
				numberOfShocks++;
			String guess=fs.next();
//			System.out.println("guess: "+guess);
			for (int j=0; j<guess.length(); j++) {
				guesses[i][guess.charAt(j)-'a']=true;
			}
		}
		Arrays.fill(possible, true);
		
		int neededShocks=0;
		for (int turn=0; turn<n; turn++) {
			if (gotShockOnTurn[turn])
				neededShocks++;
			if (gotShockOnTurn[turn]&&!wasGuess[turn]) {
				for (int i=0; i<26; i++) {
					if (!guesses[turn][i]) {
						possible[i]=false;
					}
				}
			}
			else {
				for (int i=0; i<26; i++) {
					if (guesses[turn][i]) {
						possible[i]=false;
					}
				}
			}
//			System.out.println(count(possible));
			if (count(possible)==1) {
				break;
			}
			else {
			}
		}
		System.out.println(numberOfShocks-neededShocks);
	}
	
	private static int count(boolean[] a) {
		int c=0;
		for (boolean b:a)
			if (b)c++;
		return c;
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
	}
}