import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;
import java.util.TreeMap;
/*
5 6 4 14
1 2 3 4 5
1 5 2
1 2 5
2 3 5
3 5 3

 */
public class D {

	public static void main(String[] args) {
//		System.out.println(999*999+999+999);
		for (int i=0; i<10; i++) {
			for (int j=0; j<1_000_0; j++) {
				if (works(i, j)) {
//					System.out.println(i+" "+j);
				}
			}
		}
		//a can be anything
		//b has to be 10^x-1 (if a is not 0)
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		for (int t=0; t<T; t++) {
			long a=fs.nextInt(), b=fs.nextInt();
			int tenPows=0;
			long value=1;
			while (value*10<=b+1) {
				tenPows++;
				value*=10;
			}
			System.out.println(a*(tenPows));
		}
	}
	
	static boolean works(long a, long b) {
		long ans1=Long.parseLong(a+""+b);
		long ans2=a*b+a+b;
		return ans1==ans2;
	}
	
	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");
		
		String next() {
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
	}

}