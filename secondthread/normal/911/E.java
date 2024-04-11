

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class E {

	public static void solve(FastScanner fs) {	
		int n=fs.nextInt();
		int lengthGiven=fs.nextInt();
		int[] permutation=new int[n];
		Arrays.fill(permutation, -1);
		for (int i=0; i<lengthGiven; i++)
			permutation[i]=fs.nextInt()-1;

		boolean worked=solve(permutation, 0, 0, n-1);
		if (!worked) {
			System.out.println(-1);
			return;
		}
		
		for (int i=0; i<n; i++) {
			System.out.print((permutation[i]+1)+" ");
		}
		System.out.println();
	}

	private static boolean solve(int[] permutation, int index, int firstIndexAvailable, int lastIndexAvailable) {
//		System.out.println("In solve from "+firstIndexAvailable+" "+lastIndexAvailable+" index: "+index);
		if (index>permutation.length)
			return true;
		if (firstIndexAvailable>lastIndexAvailable)
			return true;
		
		if (permutation[index]==-1) {
			permutation[index]=lastIndexAvailable;
			lastIndexAvailable--;
			index++;
			return solve(permutation, index, firstIndexAvailable, lastIndexAvailable);
		}
		if (permutation[index]>lastIndexAvailable) {
			return false;
		}
		boolean firstHalfWorked=solve(permutation, index+1, firstIndexAvailable, permutation[index]-1);
		if (!firstHalfWorked)
			return false;
//		System.out.println("Back in solve from "+firstIndexAvailable+" "+lastIndexAvailable);
		int numberUsedInFirstHalf=(permutation[index]-1)-firstIndexAvailable+1;
		boolean secondHalfWorked=solve(permutation, index+numberUsedInFirstHalf+1, permutation[index]+1, lastIndexAvailable);
		return secondHalfWorked;
	}
	
	
	
	public E() throws NumberFormatException, IOException {
		FastScanner scanner = new FastScanner(System.in);
		solve(scanner);
	}
	
	public static void main(String[] args) throws InterruptedException {
		Thread t=new Thread(null, null, "T", 1<<28) {
			public void run() {
				try {
					new E();
				} catch (NumberFormatException e) {
					e.printStackTrace();
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
		};
		t.start();
		t.join();
	}

	private static class FastScanner {
		BufferedReader br;
		StringTokenizer st;
		public FastScanner(InputStream in) {
			br = new BufferedReader(new InputStreamReader(in));
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
	}
}