import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Random;
import java.util.StringTokenizer;

/*
2 3 3

2 8
 */
public class D {
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		Random r=new Random(5);
		for (int t=0; t<1; t++) {
			long xor=fs.nextLong(), sum=fs.nextLong();
//			int n=r.nextInt(5)+1;
//			long[] a=new long[n];
//			long xor=0, sum=0;
//			for (int i=0; i<n; i++) {
//				a[i]=r.nextInt(5);
//				xor^=a[i];
//				sum+=a[i];
//			}
//			System.out.println();
//			System.out.println(Arrays.toString(a));
//			System.out.println(xor+" "+sum);
			if (xor==0 && sum==0) {
				System.out.println(0);
				continue;
			}
			if (xor>sum || xor%2!=sum%2) {
				System.out.println(-1);
				continue;
			}
			if (xor==sum) {
				System.out.println(1);
				System.out.println(xor);
				continue;
			}
			if (try2(xor, sum)) {
				continue;
			}
			if (try3(xor, sum)) {
				continue;
			}
			//is this the case?
			System.out.println(-1);
			throw null;
//			return;
		}
	}
	
	static boolean try2(long xor, long sum) {
		long a=0, b=0;
		for (int bit=61; bit>=0; bit--) {
			if ((xor & (1l<<bit))!=0) {
				a+=1l<<bit;
			}
			else {
				//either both or neither
				long left=sum-a-b;
				if (left<(1l<<bit)*2) {
					//then neither
				}
				else {
					a+=(1l<<bit);
					b+=(1l<<bit);
				}
			}
		}
		if (a+b==sum && ((a^b)==xor)) {
			System.out.println(2);
			System.out.println(a+" "+b);
			return true;
		}
		return false;
	}
	
	static boolean try3(long xor, long sum) {
		long a=0, b=0, c=0;
		System.out.println(3);
		c=xor;
		sum-=c;
		a=b=sum/2;
		System.out.println(a+" "+b+" "+c);
		return true;
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