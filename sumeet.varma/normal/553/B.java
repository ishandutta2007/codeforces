import java.io.*;
import java.util.*;

public class R309qB {

	static long p[];
	static int ans[];
	
	public static void main(String args[]) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);

		int n = in.nextInt();
		long k = in.nextLong();
		
		p = new long[51];
		p[1] = 1;
		p[2] = 2;
		for(int i=3;i<=50;i++)
			p[i] = p[i-1] + p[i - 2];
		
		ans = new int[n + 1];
		go2(1,n,k,0);
		for(int i=1;i<=n;i++)
			w.print(ans[i] + " ");
		w.println();
		
		w.close();
	}
	
	public static void go2(int curr,int n,long k,int offset){
		if(n == 1)
			ans[curr] = 1 + offset;
		else if(n == 0)
			return;
		else{
			if(k <= p[n-1]){
				ans[curr] = 1 + offset;
				go2(curr+1,n-1,k,offset+1);
			}
			else{
				ans[curr] = 2 + offset;
				ans[curr + 1] = 1 + offset;
				go2(curr+2,n-2,k - p[n-1],offset+2);
			}
		}
	}
	
	public static void go(int curr,int n,int[] a,int d[]){
		if(curr == n + 1){
			if(check(a,n)){
				if(!check2(a,n))
					System.out.println(Arrays.toString(a));
			}
			return;
		}
		for(int i=1;i<=n;i++){
			if(d[i] == 0){
				d[i] = 1;
				a[curr] = i;
				go(curr+1,n,a,d);
				d[i] = 0;
			}
		}
	}
	
	public static boolean check2(int []a,int n){
		for(int i=1;i<=n;i++)
			if(a[i] != i && a[i] != i - 1 && a[i] != i + 1)
				return false;
		return true;
	}
	
	public static boolean check(int[] a,int n){
		int ans[] = new int[n + 1];
		ArrayList<ArrayList<Integer>> list = new ArrayList<ArrayList<Integer>>();
		boolean vis[] = new boolean[n + 1];
		for(int i=1;i<=n;i++){
			if(!vis[i]){
				vis[i] = true;
				ArrayList<Integer> temp = new ArrayList<Integer>();
				temp.add(i);
				int x = i;
				while(true){
					x = a[x];
					if(vis[x] == true)
						break;
					vis[x] = true;
					temp.add(x);
				}
				make(temp);
				list.add(temp);
			}
		}
		Collections.sort(list,new MyComp());
		int k = 1;
		for(ArrayList<Integer> x : list)
			for(int z : x)
				ans[k++] = z;
		for(int i=1;i<=n;i++)
			if(a[i] != ans[i])
				return false;
		return true;
	}
	
	public static void make(ArrayList<Integer> l){
		int max = 0;
		for(int x : l)
			max = Math.max(x,max);
		while(l.get(0) != max)
			l.add(l.remove(0));
	}
	
	static class MyComp implements Comparator<ArrayList<Integer>>{
		public int compare(ArrayList<Integer> a,ArrayList<Integer> b){
			return Integer.compare(a.get(0), b.get(0));
		}
	}

	static class InputReader {

		private InputStream stream;
		private byte[] buf = new byte[8192];
		private int curChar;
		private int snumChars;
		private SpaceCharFilter filter;

		public InputReader(InputStream stream) {
			this.stream = stream;
		}

		public int snext() {
			if (snumChars == -1)
				throw new InputMismatchException();
			if (curChar >= snumChars) {
				curChar = 0;
				try {
					snumChars = stream.read(buf);
				} catch (IOException e) {
					throw new InputMismatchException();
				}
				if (snumChars <= 0)
					return -1;
			}
			return buf[curChar++];
		}

		public int nextInt() {
			int c = snext();
			while (isSpaceChar(c))
				c = snext();
			int sgn = 1;
			if (c == '-') {
				sgn = -1;
				c = snext();
			}

			int res = 0;

			do {
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res *= 10;
				res += c - '0';
				c = snext();
			} while (!isSpaceChar(c));

			return res * sgn;
		}
		
		public long nextLong() {
			int c = snext();
			while (isSpaceChar(c))
				c = snext();
			int sgn = 1;
			if (c == '-') {
				sgn = -1;
				c = snext();
			}

			long res = 0;

			do {
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res *= 10;
				res += c - '0';
				c = snext();
			} while (!isSpaceChar(c));

			return res * sgn;
		}
		
		public String readString() {
			int c = snext();
			while (isSpaceChar(c))
				c = snext();
			StringBuilder res = new StringBuilder();
			do {
				res.appendCodePoint(c);
				c = snext();
			} while (!isSpaceChar(c));
			return res.toString();
		}

		public boolean isSpaceChar(int c) {
			if (filter != null)
				return filter.isSpaceChar(c);
			return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
		}

		public interface SpaceCharFilter {
			public boolean isSpaceChar(int ch);
		}
	}

}