import java.io.*;
import java.util.*;

public class LsryQE {

	public static void main(String args[] ) throws Exception {
		   
		InputReader in = new InputReader(System.in);
	    PrintWriter w = new PrintWriter(System.out);
	    
	    int n = in.nextInt();
	    
	    Node p[] = new Node[n];
	    for(int i=0;i<n;i++)
	    	p[i] = new Node(i,in.nextInt());
	    
	    Arrays.sort(p);
	    
	    int ans[] = new int[n];
	    int prev = -100;
	    
	    for(int i=0;i<n;i++){
	    	ans[i] = p[i].val + p[i].idx - i;
	    	if(ans[i] < prev){
	    		System.out.println(":(");
	    		return;
	    	}
	    	prev = ans[i];
	    }
	    
	    for(int i=0;i<n;i++)
	    	w.print(ans[i] + " ");
	    
	    w.close(); 
	}
	
	static class Node implements Comparable<Node>{
		int idx,val;
		Node(int idx,int val){
			this.idx = idx;
			this.val = val;
		}
		public int compareTo(Node b){
			int w1 = idx + val;
			int w2 = b.idx + b.val;
			return Integer.compare(w1, w2);
		}
		public String toString(){
			return idx + " " + val;
		}
	}
	
	static class InputReader {

		private InputStream stream;
		private byte[] buf = new byte[1024];
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