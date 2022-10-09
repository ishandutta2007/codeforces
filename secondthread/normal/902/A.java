

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class A {

	public static void solve(FS fs) {	
		int n=fs.nextInt();
		int targetPos=fs.nextInt();
		Teleport[] t=new Teleport[n];
		for (int i=0; i<n; i++)
			t[i]=new Teleport(fs.nextInt(), fs.nextInt());
		
		int max=0;
		for (int i=0; i<1000; i++) {
			for (int j=0; j<n; j++) {
				if (max>=t[j].pos) {
					max=Math.max(max, t[j].end);
				}
			}
		}
		if (max>=targetPos) {
			System.out.println("YES");
		}
		else {
			System.out.println("NO");
		}
		
	}
	
	static class Teleport {
		int pos, end;
		public Teleport(int pos, int end) {
			this.pos=pos;
			this.end=end;
		}
	}

	
	
	
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		FS scanner = new FS(System.in);
		solve(scanner);
	}
	

	private static class FS {
		BufferedReader br;
		StringTokenizer st;
		public FS(InputStream in) {
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
	}
}