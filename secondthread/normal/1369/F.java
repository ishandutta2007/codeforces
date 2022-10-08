import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class F {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int rounds=fs.nextInt();
		long[] small=new long[rounds];
		long[] big=new long[rounds];
		for (int i=0; i<rounds; i++) {
			small[i]=fs.nextLong(); big[i]=fs.nextLong();
		}
		boolean canWin=false;
		boolean canLose=true;
		for (int r=rounds-1; r>=0; r--) {
			boolean winNow=play(big[r], small[r], false);
			boolean loseNow=play(big[r], small[r], true);
			boolean nextWin=(canWin&&loseNow) || (winNow && !canWin);
			boolean nextLose=(canLose&&loseNow) || (winNow && !canLose);
			canWin=nextWin;
			canLose=nextLose;
		}
		System.out.println((canWin?'1':'0')+" "+(canLose?"1":"0"));
	}
	
	//returns whether small is a one
	static boolean play(long big, long small, boolean startOnes) {
		if (big%2==1 && !startOnes) {
			//alternates forever
			return (big-small)%2!=0;
		}
		else if (!startOnes && big%2==0) {
			long half=big/2;
			if (small>half) {
				return (big-small)%2!=0;
			}
			else {
				return play(half, small, true);
			}
		}
		//TODO: handle last case
		if (startOnes) {
			//startOnes assumes that odd above is all zero
			long nextRelevant=big/2;
			if (small>nextRelevant) {
				return true;
			}
			else {
				return play(nextRelevant, small, false);
			}
		}
		throw null;
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