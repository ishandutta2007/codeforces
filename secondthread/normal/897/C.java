import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class C {
	
	private static String f0="What are you doing at the end of the world? Are you busy? Will you save us?";
	private static String f11="What are you doing while sending \"";
	private static String f12="\"? Are you busy? Will you send \"";
	private static String f13="\"?";
	
	private static int f0Length=f0.length(), f11Length=f11.length(), f12Length=f12.length(), f13Length=f13.length();
	
	private static long[] lengthOf=new long[100001];
	
	public static void main(String[] args) throws InterruptedException {
		Thread t=new Thread(null, null, "T", 1<<28) {
			public void run() {				
				new C();
			}
		};
		t.start();
		t.join();
	}
	
	public C() {
		Arrays.fill(lengthOf, -1);
//		System.out.println(lengthOf(0));
//		System.out.println(lengthOf(1));
//		System.out.println(lengthOf(2));
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		for (int t=0; t<T; t++) {
			int degree=fs.nextInt();
			long index=fs.nextLong()-1;
			char c=getChar(index,degree);
			System.out.print(c);
		}
		System.out.println();
	}

	private static long lengthOf(int degree) {
		if (lengthOf[degree]!=-1)
			return lengthOf[degree];
		if (degree==0)
			return lengthOf[degree]=f0Length;
		if (lengthOf(degree-1)>=1000000000100000000l)
			return lengthOf[degree]=1000000000100000000l;
		return lengthOf[degree]=f11Length+lengthOf(degree-1)+f12Length+lengthOf(degree-1)+f13Length;
	}
	
	private static char getChar(long index, int degree) {
		if (degree==0) {
			if (index>=f0Length) {
				return '.';
			}
			return f0.charAt((int)index);
		}
		
		if (index<f11Length) {
			return f11.charAt((int)index);
		}
		index-=f11Length;
		if (index>=lengthOf(degree-1)) {
			index-=lengthOf(degree-1);
		}
		else {
			return getChar(index, degree-1);
		}
		
		if (index<f12Length) {
			return f12.charAt((int)index);
		}
		index-=f12Length;
		
		if (index>=lengthOf(degree-1)) {
			index-=lengthOf(degree-1);
		}
		else {
			return getChar(index, degree-1);
		}
		
		if (index<f13Length) {
			return f13.charAt((int)index);
		}
		return '.';
	}
	
	
	public static class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		public FastScanner() {
			try {
				br = new BufferedReader(new InputStreamReader(System.in));
				// br = new BufferedReader(new FileReader("testdata.out"));
				st = new StringTokenizer("");
			} catch (Exception e) {
				e.printStackTrace();
			}
		}

		public String next() {
			if (st.hasMoreTokens())
				return st.nextToken();
			try {
				st = new StringTokenizer(br.readLine());
			} catch (Exception e) {
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

		public double nextDouble() {
			return Double.parseDouble(next());
		}

		public String nextLine() {
			String line = "";
			try {
				line = br.readLine();
			} catch (Exception e) {
				e.printStackTrace();
			}
			return line;
		}
	}
	
}