import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;


public class A {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			int nFriends=fs.nextInt(), nPresents=fs.nextInt();
			int[] friends=fs.readArray(nFriends);
			int[] presents=fs.readArray(nPresents);
			for (int i=0; i<friends.length; i++) friends[i]--;
			sort(friends);
			int presentsToBuy=0;
			for (int i:friends) if (i>=presentsToBuy) presentsToBuy++;
			long ans=0;
			
			long cost=0;
			for (int i:friends) cost+=presents[i];
			ans=cost;
			for (int realBuy=1; realBuy<=presentsToBuy; realBuy++) {
				cost+=presents[realBuy-1];
				cost-=presents[friends[nFriends-realBuy]];
				ans=Math.min(ans, cost);
			}
			System.out.println(ans);
		}
	}
	
	static void sort(int[] a) {
		ArrayList<Integer> list=new ArrayList<>();
		for (int i:a) list.add(i);
		Collections.sort(list);
		for (int i=0; i<a.length; i++) a[i]=list.get(i);
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