import java.io.*;
import java.util.*;

public class R331qA {

	public static void main(String args[]) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);
		
		int n = in.nextInt();
	
		TreeSet<Integer> x = new TreeSet<Integer>();
		TreeSet<Integer> y = new TreeSet<Integer>();
		
		for(int i=0;i<n;i++){
			x.add(in.nextInt());
			y.add(in.nextInt());
		}
		
		if(x.size() == 1 || y.size() == 1)
			w.println(-1);
		else{
			int x1 = x.first();
			x.remove(x1);
			int x2 = x.first();
			int y1 = y.first();
			y.remove(y1);
			int y2 = y.first();
			w.println((y2 - y1) * 1L * (x2 - x1) );
		}
			
		
		w.close();
	}
	
	static class Pair implements Comparable<Pair>{
		int x,y;
		Pair(int x,int y){
			this.x = x;
			this.y = y;
		}
		public int compareTo(Pair o){
			if(x != o.x)
				return Integer.compare(x, o.x);
			return Integer.compare(y, o.y);
		}
	}
	
	static class InputReader {
		private InputStream stream;		private byte[] buf = new byte[8192];
		private int curChar, snumChars;	private SpaceCharFilter filter;
		public InputReader(InputStream stream) {	this.stream = stream; }
		public int snext() {
			if (snumChars == -1)	throw new InputMismatchException();
			if (curChar >= snumChars) {
				curChar = 0;
				try {	snumChars = stream.read(buf);
				} catch (IOException e) {	throw new InputMismatchException();}
				if (snumChars <= 0)	return -1;
			}	return buf[curChar++];}
		public int nextInt() {
			int c = snext();	while (isSpaceChar(c))	c = snext();	int sgn = 1;
			if (c == '-') {	sgn = -1;	c = snext();	}	int res = 0;
			do {
				if (c < '0' || c > '9')	throw new InputMismatchException();
				res *= 10;	res += c - '0';	c = snext();
			} while (!isSpaceChar(c));	return res * sgn;}
		public String readString() {
			int c = snext();
			while (isSpaceChar(c))	c = snext();	StringBuilder res = new StringBuilder();
			do {	res.appendCodePoint(c);	c = snext();
			} while (!isSpaceChar(c));	return res.toString();}
		public boolean isSpaceChar(int c) {	if (filter != null)	return filter.isSpaceChar(c);
			return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;}
		public interface SpaceCharFilter {	public boolean isSpaceChar(int ch);}
	}
}