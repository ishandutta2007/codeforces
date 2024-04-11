import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.text.DecimalFormat;
import java.util.StringTokenizer;
import java.util.TreeMap;


public class C {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt();
			char[] line=fs.next().toCharArray();
			int start=-1, end=1_000_000_000;
			TreeMap<Vec, Integer> map=new TreeMap<>();
			Vec cur=new Vec(0, 0);
			map.put(cur, -1);
			for (int i=0; i<n; i++) {
				cur=new Vec(cur.x, cur.y);
				if (line[i]=='U') cur.y++;
				else if (line[i]=='D') cur.y--;
				else if (line[i]=='L') cur.x--;
				else cur.x++;
				
				int last=map.getOrDefault(cur, -1000000000);
				if (i-last<end-start) {
					end=i;
					start=last;
//					System.out.println("On i "+i+" setting start to "+start);
				}
				map.put(cur, i);
			}
			if (end-start+1<1_000_000) {
				System.out.println((start+2)+" "+(end+1));
			}
			else {
				System.out.println(-1);
			}
		}
	}
	
	static class Vec implements Comparable<Vec> {
		int x, y;
		public Vec(int x, int y) {
			this.x=x;
			this.y=y;
		}
		
		public int compareTo(Vec o) {
			if (x!=o.x) return Integer.compare(x, o.x);
			return Integer.compare(y, o.y);
		}
	}
	
	
	static class FastScanner {
		StringTokenizer st = new StringTokenizer("");
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		public String next() {
			while (!st.hasMoreElements())
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			return st.nextToken();
		}

		public int nextInt() {
			return Integer.parseInt(next());
		}

		public int[] readArray(int n) {
			int[] a = new int[n];
			for (int i = 0; i < n; i++)
				a[i] = nextInt();
			return a;
		}

	}
}