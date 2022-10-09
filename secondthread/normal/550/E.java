import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class BracketsInImplications {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		PrintWriter out=new PrintWriter(System.out);
		int[] a=new int[n];
		for (int i=0; i<n; i++) a[i]=fs.nextInt();
		if (n==1) {
			if (a[0]==0) {
				out.println("YES");
				out.println(0);
				out.close();
				return;
			}
			out.println("NO");
			out.close();
			return;
		}
		if (a[n-1]==1) {
			out.println("NO");
			out.close();
			return;
		}
		if (a[n-2]==1) {
			out.println("YES");
			//ends in 1 0 so (... -> 1)->0
			out.print('(');
			for (int i=0; i<n-2; i++) {
				out.print(a[i]);
				out.print("->");
			}
			out.println("1)->0");
			out.close();
			return;
		}
		if (n==2) {
			out.println("NO");
			out.close();
			return;
		}
		int thirdZeroIndex=-1;
		for (int i=0; i<n-2; i++)
			if (a[i]==0) thirdZeroIndex=i;
		if (thirdZeroIndex==-1) {
			out.println("NO");
			out.close();
			return;
		}
		out.println("YES");
		out.print('(');
		for (int i=0; i<thirdZeroIndex; i++) {
			out.print(a[i]+"->");
		}
		int closeParens=2;
		out.print("(0->");
		for (int i=thirdZeroIndex+1; i<n-2; i++) {
			out.print("(1->");
			closeParens++;
		}
		//after third index before n-2
		out.print("0");
		for (int i=0; i<closeParens; i++) out.print(')');
		out.println("->0");
		out.close();
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
	}

}