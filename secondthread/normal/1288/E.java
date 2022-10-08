import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

/*
6
0 0
1 0
0 1
1 1
10 3
-1 10

 */
public class E {

	public static void main(String[] args) {
		FastScanner fs = new FastScanner();
		int n=fs.nextInt();
		int m=fs.nextInt();
		BIT bit=new BIT(m+n);
		int curIndex=m;
		int[] indexOf=new int[n];
		int[] minAns=new int[n];
		int[] maxAns=new int[n];
		for (int i=0; i<n; i++) {
			bit.update(curIndex, 1);
			minAns[i]=maxAns[i]=i;
			indexOf[i]=curIndex++;
		}
		curIndex=m-1;
		for (int i=0; i<m; i++) {
			int toMove=fs.nextInt()-1;
			minAns[toMove]=0;
			int at=indexOf[toMove];
			bit.update(at, -1);
			maxAns[toMove]=Math.max(maxAns[toMove], bit.read(at));
			indexOf[toMove]=curIndex;
			bit.update(curIndex--, 1);
		}
		for (int i=0; i<n; i++) {
			maxAns[i]=Math.max(maxAns[i], bit.read(indexOf[i])-1);
		}
		for (int i=0; i<n; i++) {
			System.out.println(minAns[i]+1+" "+(maxAns[i]+1));
		}
	}
	
	static class BIT {
		int[] a;
		int n;
		public BIT(int n) {
			n+=2;
			this.n=n;
			a=new int[n];
		}
		
		int read(int i) {
			i++;
			int ans=0;
			for (; i>0; i-=i&-i) ans+=a[i];
			return ans;
		}
		void update(int i, int v) {
			i++;
			for (; i<n; i+=i&-i) a[i]+=v;
		}
	}
	
	static class FastScanner {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer("");

		String next() {
			while (!st.hasMoreElements())
				try {
					st = new StringTokenizer(br.readLine());
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