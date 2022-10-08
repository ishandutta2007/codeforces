import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

/*

 */
public class A {

	public static void main(String[] a) throws InterruptedException {
		Thread t=new Thread(null, null, "!", 1<<28) {
			public void run() {
				new A();
			}
		};
		t.start();
		t.join();
	}
	
	public A() {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			int h=fs.nextInt(), m=fs.nextInt();
			h++;
			int ans=60-m;
			ans+=(60*(24-h));
			System.out.println(ans);
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
					// TODO Auto-generated catch block
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
	}

}