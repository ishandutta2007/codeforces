import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;
/*
5 6 4 14
1 2 3 4 5
1 5 2
1 2 5
2 3 5
3 5 3


5 6 4 14
1 2 3 4 5
1 5 2
2 2 5
2 3 5
1 5 3

 */
public class D2 {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int nSoldiers=fs.nextInt(), dist=fs.nextInt(), nTraps=fs.nextInt(), time=fs.nextInt();
		ArrayList<Integer> soldiers=new ArrayList<>();
		for (int i=0; i<nSoldiers; i++) soldiers.add(fs.nextInt());
		Collections.sort(soldiers);
		Trap[] traps=new Trap[nTraps];
		for (int i=0; i<nTraps; i++) {
			traps[i]=new Trap(fs.nextInt()-1, fs.nextInt(), fs.nextInt());
		}
		
		int min=0, max=nSoldiers;
		while (min!=max) {
			int mid=(min+max)/2;
			if (possible(time, traps, soldiers.get(mid), dist)) {
				max=mid;
			}
			else {
				min=mid+1;
			}
		}
		System.out.println(nSoldiers-max);
	}
	
	static boolean possible(int time, Trap[] traps, int minAglility, int dist) {
		int[] delta=new int[dist+1];
		for (Trap t:traps) {
			if (t.danger>minAglility) {
				delta[t.l]++;
				delta[t.r]--;
			}
		}
		int[] cs=new int[dist+2];
		int overlap=0;
		for (int i=0; i<delta.length; i++) {
			cs[i+1]=cs[i]+delta[i];
			if (cs[i]!=0) overlap++;
		}
		int totalTime=overlap*2+dist+1;
		return totalTime<=time;
	}
	
	
	static class Trap implements Comparable<Trap> {
		int l, r, danger;
		public Trap(int l, int r, int danger) {
			this.l=l;
			this.r=r;
			this.danger=danger;
		}
		
		public int compareTo(Trap o) {
			return -Integer.compare(danger, o.danger);
		}
	}
	
	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");
		
		String next() {
			while (!st.hasMoreElements())
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
	}

}