import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class B {
	static char[] alpha;
	static String alphaSS;

	public static void main(String[] args) {
		String alphaS="abcdefghijklmnopqrstuvwxyz";
		alphaS+=alphaS.toUpperCase();
		alpha=alphaS.toCharArray();
		alphaSS=alphaS;
		
		FastScanner fs=new FastScanner();
		int nTurns=fs.nextInt();
		char[][] words= new char[][]{fs.next().toCharArray(), fs.next().toCharArray(), fs.next().toCharArray()};
		int[][] cs=new int[3][];
		for (int i=0; i<3; i++)
			cs[i]=cs(words[i]);
		
		int[] highest=new int[3];
		for (int i=0; i<3; i++) {
			for (int j:cs[i])
				highest[i]=Math.max(highest[i], j);
		}
		int[] score=new int[3];
		int length=words[0].length;
		if (nTurns==1) {
			for (int i=0; i<3; i++) {
				if (highest[i]==length) {
					score[i]=highest[i]-1;
				}
				else {
					score[i]=highest[i]+1;
				}
			}
		}
		else {
			for (int i=0; i<3; i++) {
				score[i]=Math.min(length, highest[i]+nTurns);
			}
		}
//		System.out.println(Arrays.toString(score));
		int max=0;
		for (int i:score)max=Math.max(max, i);
		int maxCount=0;
		for (int i:score) if (i==max) maxCount++;
		if (maxCount!=1) {
			System.out.println("Draw");
		}
		else if (score[0]==max) {
			System.out.println("Kuro");
		}
		else if (score[1]==max) {
			System.out.println("Shiro");
		}
		else {
			System.out.println("Katie");
		}
	}

	static int[] cs(char[] string) {
		int[] toReturn=new int[alpha.length];
		for (char c:string)
			toReturn[alphaSS.indexOf(c+"")]++;
		return toReturn;
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
			for (int i=0; i<n; i++)
				a[i]=nextInt();
			return a;
		}
	}
	
}