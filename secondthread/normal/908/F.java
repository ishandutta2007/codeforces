import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Random;
import java.util.StringTokenizer;

/*

All greens will need to be connected
If we have only one green, we need to connect everything to it

Within a pair of greens, we get to skip any red or any green pair

 */
public class I {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		PrintWriter out=new PrintWriter(System.out);
		// int T=fs.nextInt();
		int T=1;
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt();
			long[] positions=new long[n];
			char[] colors=new char[n];
			for (int i=0; i<n; i++) {
				positions[i]=fs.nextInt();
				colors[i]=fs.next().charAt(0);
			}
			if (noGreens(colors)) {
				solveForNoGreens(positions, colors);
				return;
			}
			
			int firstGreenIndex=n-1, lastGreenIndex=0;
			for (int i=0; i<n; i++) {
				if (colors[i]=='G') {
					firstGreenIndex=Math.min(firstGreenIndex, i);
					lastGreenIndex=Math.max(lastGreenIndex, i);
				}
			}
			
			boolean seenR=false, seenB=false;
			long total=0;
			for (int i=0; i<firstGreenIndex; i++) {
				if (colors[i]=='R'&&!seenR) {
					seenR=true;
					total+=positions[firstGreenIndex]-positions[i];
				}
				if (colors[i]=='B'&&!seenB) {
					seenB=true;
					total+=positions[firstGreenIndex]-positions[i];
				}
			}
			
			seenR=seenB=false;
			for (int i=n-1; i>lastGreenIndex; i--) {
				if (colors[i]=='R'&&!seenR) {
					seenR=true;
					total+=positions[i]-positions[lastGreenIndex];
				}
				if (colors[i]=='B'&&!seenB) {
					seenB=true;
					total+=positions[i]-positions[lastGreenIndex];
				}
			}
			
			int[] greenIndicies=getGreenIndicies(colors);
			for (int g=0; g<greenIndicies.length-1; g++) {
				boolean gapContainsR=false, gapContainsB=false;
				long longestRGap=0, longestBGap=0;
				long lastRPos=positions[greenIndicies[g]], lastBPos=positions[greenIndicies[g]];
				long penalty=0;
				for (int i=greenIndicies[g]+1; i<greenIndicies[g+1]; i++) {
					if (colors[i]=='R') {
						longestRGap=Math.max(longestRGap, positions[i]-lastRPos);
						lastRPos=positions[i];
						gapContainsR=true;
					}
					if (colors[i]=='B') {
						longestBGap=Math.max(longestBGap, positions[i]-lastBPos);
						lastBPos=positions[i];
						gapContainsB=true;
					}
				}
				if (gapContainsR) {
					longestRGap=Math.max(longestRGap, positions[greenIndicies[g+1]]-lastRPos);
					penalty+=positions[greenIndicies[g+1]]-positions[greenIndicies[g]]-longestRGap;
				}
				if (gapContainsB) {
					longestBGap=Math.max(longestBGap, positions[greenIndicies[g+1]]-lastBPos);
					penalty+=positions[greenIndicies[g+1]]-positions[greenIndicies[g]]-longestBGap;
				}
				
				penalty+=positions[greenIndicies[g+1]]-positions[greenIndicies[g]];
				penalty=Math.min(penalty, 2*(positions[greenIndicies[g+1]]-positions[greenIndicies[g]]));
				total+=penalty;
			}
			
			out.println(total);

		}
		out.close();
	}

	private static void solveForNoGreens(long[] positions, char[] colors) {
		long total = 0;
		long lastR = -1, lastB = -1;
		for (int i = 0; i < positions.length; i++) {
			if (colors[i] == 'R') {
				if (lastR == -1)
					lastR = positions[i];
				else {
					total += positions[i] - lastR;
					lastR = positions[i];
				}
			} else {
				if (lastB == -1)
					lastB = positions[i];
				else {
					total += positions[i] - lastB;
					lastB = positions[i];
				}
			}
		}
		System.out.println(total);
	}
	
	private static int[] getGreenIndicies(char[] colors) {
		int c = 0;
		for (char cc : colors)
			if (cc == 'G')
				c++;
		int[] toReturn = new int[c];
		int ind = 0;
		for (int i = 0; i < colors.length; i++)
			if (colors[i] == 'G')
				toReturn[ind++] = i;
		return toReturn;
	}
 
	private static boolean noGreens(char[] colors) {
		for (char c : colors)
			if (c == 'G')
				return false;
		return true;
	}
 
	
	static final Random random=new Random();
	static final int mod=998244353;
	
	static void ruffleSort(int[] a) {
		int n=a.length;//shuffle, then sort 
		for (int i=0; i<n; i++) {
			int oi=random.nextInt(n), temp=a[oi];
			a[oi]=a[i]; a[i]=temp;
		}
		Arrays.sort(a);
	}
	static long add(long a, long b) {
		return (a+b)%mod;
	}
	static long sub(long a, long b) {
		return ((a-b)%mod+mod)%mod;
	}
	static long mul(long a, long b) {
		return (a*b)%mod;
	}
	static long exp(long base, long exp) {
		if (exp==0) return 1;
		long half=exp(base, exp/2);
		if (exp%2==0) return mul(half, half);
		return mul(half, mul(half, base));
	}
	static long[] factorials=new long[2_000_001];
	static long[] invFactorials=new long[2_000_001];
	static void precompFacts() {
		factorials[0]=invFactorials[0]=1;
		for (int i=1; i<factorials.length; i++) factorials[i]=mul(factorials[i-1], i);
		invFactorials[factorials.length-1]=exp(factorials[factorials.length-1], mod-2);
		for (int i=invFactorials.length-2; i>=0; i--)
			invFactorials[i]=mul(invFactorials[i+1], i+1);
	}
	
	static long nCk(int n, int k) {
		return mul(factorials[n], mul(invFactorials[k], invFactorials[n-k]));
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

		public FastScanner() {
			try {
				String filename=this.getClass().getEnclosingClass().getSimpleName();
				br=new BufferedReader(new FileReader(new File(filename+".in")));
			}
			catch (Exception e) {
				System.err.println("Using standard input instead.");
				br=new BufferedReader(new InputStreamReader(System.in));
			}
		}
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