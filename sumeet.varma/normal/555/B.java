import java.io.*;
import java.util.*;

public class R310qBCaseOfFugitive {

	static long oo = Long.MAX_VALUE - 100;
	static int seg[];
	static Node node[];
	
	public static void main(String args[]) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);

		int n = in.nextInt();
		int m = in.nextInt();
		
		long l[] = new long[n];
		long r[] = new long[n];
		
		for(int i=0;i<n;i++){
			l[i] = in.nextLong();
			r[i] = in.nextLong();
		}
		
		Pair a[] = new Pair[m];
		for(int i=0;i<m;i++)
			a[i] = new Pair(i,in.nextLong());
		Arrays.sort(a);
	
		node = new Node[n - 1];
		for(int i=0;i<n-1;i++)
			node[i] = new Node(i,l[i],r[i],l[i+1],r[i+1]);
		Arrays.sort(node);
		
		int ans[] = new int[n - 1];
		Arrays.fill(ans, -1);
		
		PriorityQueue<Node> pq = new PriorityQueue<Node>(new NodeComp());
		
		int curr = 0;
		for(int i=0;i<m;i++){
			while(curr < n-1 && node[curr].min <= a[i].val){
				pq.add(node[curr]);
				curr++;
			}
			if(pq.isEmpty())	continue;
			Node top = pq.peek();
			if(top.max >= a[i].val){
				pq.remove();
				ans[top.idx] = a[i].idx;
			}
		}
		
		boolean found = true;
		for(int i=0;i<n-1;i++)
			found &= ans[i] != -1;
		
		if(!found)
			w.println("No");
		else{	
			w.println("Yes");
			for(int i=0;i<n-1;i++){
				w.print(ans[i] + 1);
				w.print(" ");
			}
			w.println();
		}
		
		w.close();
	}
	
	static class Pair implements Comparable<Pair>{
		int idx;
		long val;
		Pair(int i,long v){
			idx = i;
			val = v;
		}
		public int compareTo(Pair o){
			return Long.compare(val, o.val);
		}
		public String toString(){
			return idx + " " + val;
		}
	}
	
	
	static class Node implements Comparable<Node>{
		long min,max;
		int idx;
		public Node(int i,long l1,long r1,long l2,long r2){
			min = l2 - r1;
			max = r2 - l1;
			idx = i;
		}
		public int compareTo(Node o){
			return Long.compare(min, o.min);
		}
		public String toString(){
			return idx + " " + min + " " + max;
		}
	}
	
	static class NodeComp implements Comparator<Node>{
		public int compare(Node a,Node b){
			return Long.compare(a.max, b.max);
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