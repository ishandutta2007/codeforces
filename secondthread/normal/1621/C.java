import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;
import java.util.StringTokenizer;

public class C {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt();
			boolean[] solved=new boolean[n];
			int turnsUsed=0;
			int[] ans=new int[n];
			for (int i=0; i<n; i++) {
				if (solved[i]) continue;
				ArrayList<Integer> inCycle=new ArrayList<>();
				HashSet<Integer> set=new HashSet<>();
				int startTurnsUsed=turnsUsed;
				while (true) {
					System.out.println("? "+(i+1));
					int next=fs.nextInt()-1;
					turnsUsed++;
					if (set.contains(next)) break;
					set.add(next);
					inCycle.add(next);
				}
				for (int j:inCycle) solved[j]=true;
				
				for (int offset=0; offset<inCycle.size(); offset++) {
					int current=inCycle.get((startTurnsUsed+offset)%inCycle.size());
					int next=inCycle.get((startTurnsUsed+offset+1)%inCycle.size());
					ans[current]=next;
				}
			}
			System.out.print("! ");
			for (int i:ans) System.out.print(1+i+" ");
			System.out.println();
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