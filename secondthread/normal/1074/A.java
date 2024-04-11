import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;
import java.util.TreeMap;

public class _LiftLevel5A {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int nVertical=fs.nextInt(), nHorizontal=fs.nextInt();
		ArrayList<Integer> verticalSpells=new ArrayList<>();
		for (int i=0; i<nVertical; i++) verticalSpells.add(fs.nextInt());
		verticalSpells.add(1_000_000_000);
		nVertical++;
		Collections.sort(verticalSpells);
		TreeMap<Integer, Integer> indexOf=new TreeMap<>();
		for (int i=0; i<nVertical; i++)
			indexOf.put(verticalSpells.get(i), i);
		
		BIT bit=new BIT(nVertical+2);
		for (int i=0; i<nHorizontal; i++) {
			int x1=fs.nextInt(), x2=fs.nextInt(), y=fs.nextInt();
			if (x1!=1) continue;
			if (indexOf.firstKey()<=x2) {
				int updateTo=indexOf.floorEntry(x2).getValue();
				bit.update(0, 1);
				bit.update(updateTo+1, -1);
			}
		}
		int ans=Integer.MAX_VALUE;
		for (int toCut=0; toCut<nVertical; toCut++) {
			int cost=toCut+bit.read(toCut);
			ans=Math.min(ans, cost);
		}
		System.out.println(ans);
	}
	
	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");
		public String next() {
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
		
		int[] readArray(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++) a[i]=nextInt();
			return a;
		}
	}

	static class BIT {
		int[] a;
		int n;
		public BIT(int n) {
			this.n=n+2;
			a=new int[n+4];
		}
		
		int read(int i) {
			i++;
			int res=0;
			for (; i!=0; i-= i&-i)
				res+=a[i];
			return res;
		}
		void update(int i, int val) {
			i++;
			for (; i<n; i+=i&-i)
				a[i]+=val;
		}
	}
	
}