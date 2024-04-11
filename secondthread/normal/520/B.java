import java.util.*;
import java.io.*;

public class A {
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt(), to=fs.nextInt();
		int[] dist=new int[10001];
		Arrays.fill(dist, -1);
		dist[to]=0;
		ArrayDeque<Integer> bfs=new ArrayDeque<>();
		bfs.add(to);
		while (!bfs.isEmpty()) {
			int next=bfs.remove();
			if (next==n) {
				System.out.println(dist[next]);
				return;
			}
			if (next%2==0&&dist[next/2]==-1) {
				dist[next/2]=dist[next]+1;
				bfs.add(next/2);
			}
			if (next+1<dist.length&&dist[next+1]==-1) {
				dist[next+1]=dist[next]+1;
				bfs.add(next+1);
			}
		}
	}
	
	private static boolean possible(int n, int rocketWeight, int[] planetLiftoffWeightPerFuel, int[] planetLandWeightPerFuel, double fuel) {
		for (int i=0; i<n; i++) {
			double newCost=(rocketWeight+fuel)/planetLiftoffWeightPerFuel[i];
			if (newCost>fuel) return false;
			fuel-=newCost;
			newCost=(rocketWeight+fuel)/planetLandWeightPerFuel[(i+1)%n];
			if (newCost>fuel) return false;
			fuel-=newCost;
		}
		return true;
	}
	
	private static class FastScanner {
		BufferedReader br;
		StringTokenizer st;
		public FastScanner() {
			br = new BufferedReader(new InputStreamReader(System.in));
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
		long[] readLongArray(int n) {
			long[] a=new long[n];
			for (int i=0; i<n; i++)
				a[i]=nextLong();
			return a;
		}
	}
}