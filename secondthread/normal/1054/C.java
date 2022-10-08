import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class C {
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		int[] l=fs.readArray(n), r=fs.readArray(n);
		boolean[] removed=new boolean[n];
		int[] ans=new int[n];
		int numGiven=n;
		for (int i=0; i<n; i++) {
			//remove from all with 0
			ArrayDeque<Integer> taken=new ArrayDeque<Integer>();
			for (int toTake=0; toTake<n; toTake++) {
				if (removed[toTake])
					continue;
				if (l[toTake]==0&&r[toTake]==0) {
					ans[toTake]=numGiven;
					removed[toTake]=true;
					taken.add(toTake);
				}
			}
			while (!taken.isEmpty()) {
				int next=taken.remove();
				for (int j=0; j<next; j++) {
					if (!removed[j]) r[j]--;
				}
				for (int j=next+1; j<n; j++) {
					if (!removed[j]) l[j]--;
				}
			}
			numGiven--;
		}
		
		for (int i=0; i<n; i++) {
			if (l[i]<0||r[i]<0||!removed[i]) {
				System.out.println("NO");
				return;
			}
		}
		System.out.println("YES");
		for (int i=0; i<n; i++)
			System.out.print(ans[i]+" ");
		System.out.println();
	}
	
	
	static int bs(int[] a, int highestLegal) {
		int l=0, r=a.length-1;
		while (l!=r) {
			int mid=(l+r+1)/2;
			if (a[mid]<=highestLegal) {
				l=mid;
			}
			else {
				r=mid-1;
			}
		}
		return l;
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
		
		public int nextInt() {
			return Integer.parseInt(next());
		}
		
		public long nextLong() {
			return Long.parseLong(next());
		}
		
		public int[] readArray(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++) {
				a[i]=nextInt();
			}
			return a;
		}
		
		public double nextDouble() {
			return Double.parseDouble(next());
		}
		
	}

}