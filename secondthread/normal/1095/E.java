import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Random;
import java.util.StringTokenizer;

public class E {

	static int n;
	static char[] line;
	static Random r=new Random();
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		char[] line=fs.next().toCharArray();
		System.out.println(ans(n, line));
		/*for (int i=0; i<1000; i++) {
			gen();
			int ans=bruteForce(n, line.clone());
			int my=ans(n, line.clone());
			if (ans!=my) {
				System.out.println(ans+" "+my);
				System.out.println(n);
				for (char c:line) 
					System.out.print(c+" ");
				System.out.println();
			}
		}*/
	}
	
	public static void gen() {
		n=r.nextInt(10);
		line=new char[n];
		for (int i=0; i<n; i++) {
			line[i]=r.nextBoolean()?'(':')';
		}
	}
	
	static int bruteForce(int n, char[] line) {
		int c=0;
		for (int i=0; i<n; i++) {
			char o=line[i];
			line[i]=o==')'?'(':')';
//			System.out.println("Checking "+Arrays.toString(line));
			if (check(line, n))
				c++;
			line[i]=o;
		}
		return c;
	}
	
	static boolean check(char[] line, int n) {
		int total=0;
		for (int i=0; i<line.length; i++) {
			total+=line[i]=='('?1:-1;
			if (total<0)
				return false;
		}
		return total==0;
	}
	
	static int ans(int n, char[] line) {
		if (n%2!=0||n==0) {
			return 0;
		}
		char[] rev=new char[n];
		for (int i=0; i<n; i++)
			rev[n-1-i]=line[i]==')'?'(':')';
		int total=go(line)+go(rev);
		return total;
	}
	
	static int go(char[] a) {
		int total=0;
		int[] preSum=new int[a.length];
		for (int i=0; i<a.length; i++) {
			preSum[i]=total;
			if (a[i]=='(')
				total++;
			else
				total--;
		}
		if (total!=2)
			return 0;
		
		int[] minAfter=new int[preSum.length];
		minAfter[preSum.length-1]=preSum[preSum.length-1];
		for (int i=preSum.length-2; i>=0; i--) {
			minAfter[i]=Math.min(preSum[i], minAfter[i+1]);
		}
		
		int[] minBefore=new int[preSum.length];
		for (int i=1; i<minBefore.length; i++) {
			minBefore[i]=Math.min(minBefore[i-1], preSum[i]);
		}
		
		int c=0;
		for (int i=0; i<a.length; i++)
			if (a[i]=='('&&(i==minAfter.length-1||minAfter[i+1]>1)&&minBefore[i]>=0) {
				c++;
//				System.out.println(c);
			}
		return c;
	}

	static class Node {
		ArrayList<Node> children=new ArrayList<>();
		ArrayList<Query> queries=new ArrayList<>();
		int height;
		long answer=0;
		
		public void dfs(Node parent, int height) {
			this.height=height;
			if (parent!=null)
				children.remove(parent);
			for (Node n:children)
				n.dfs(this, height+1);
		}
		
		public void calculateAnswer(BIT bit) {
			answer+=bit.pointQuery(height);
			for (Query q:queries) {
				int end=Math.min(n, height+q.length);
				answer+=q.delta;
				bit.rangeUpdate(height, end, q.delta);
			}
			for (Node nn:children) {
				nn.calculateAnswer(bit);
			}
			for (Query q:queries) {
				int end=Math.min(n, height+q.length);
				bit.rangeUpdate(height, end, -q.delta);
			}
		}
	}
	
	static class Query {
		int delta;
		int length;
		
		public Query(int delta, int length) {
			this.delta=delta;
			this.length=length;
		}
	}

	static class BIT {
		long[] vs;

		public BIT(int s) {
			vs=new long[s+5];
		}

		public long zzrangeSum(int idx) {
			idx++;
			long ret=0;
			for (int i=idx; i>0; i-=(i&-i))
				ret+=vs[i];
			return ret;
		}

		public void zzpointUpdate(int idx, int v) {
			idx++;
			for (int i=idx; i<vs.length; i+=(i&-i))
				vs[i]+=v;
		}
		
		public void rangeUpdate(int from, int to, int delta) {
			zzpointUpdate(from, delta);
			zzpointUpdate(to+1, -delta);
		}

		public long pointQuery(int to) {
			return zzrangeSum(to);
		}		
	}

	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");

		public String next() {
			while (!st.hasMoreTokens())
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

		public int[] readArray(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++)
				a[i]=nextInt();
			return a;
		}

		public long nextLong() {
			return Long.parseLong(next());
		}

	}

}