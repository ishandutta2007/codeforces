import java.io.*;
import java.util.*;

public class Ed2qC {

	public static void main(String args[]) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);
		
		String inp = in.readString();
		char s[] = inp.toCharArray();
		
		ArrayList<String> list = new ArrayList<String>();
		
		StringBuilder pro = new StringBuilder("");
		for(int i=0;i<s.length;i++){
			if(s[i] == ';' || s[i] == ','){
				list.add(pro.toString());
				pro = new StringBuilder("");
			}
			else
				pro.append(s[i]);
		}
		list.add(pro.toString());
		
		ArrayList<String> a = new ArrayList<String>();
		ArrayList<String> b = new ArrayList<String>();
		
		for(String x : list){
			char t[] = x.toCharArray();
			boolean yes = true;
			for(char y : t)
				yes &= y >= '0' && y <= '9';
			yes &= t.length <= 1 || t[0] != '0';
			if(yes && t.length != 0)
				a.add(x);
			else
				b.add(x);
		}
		
		if(a.size() == 0)
			w.println("-");
		else{
			w.print("\"");
			for(int i=0;i<a.size();i++)
				w.print(i == 0 ? a.get(i) : ("," + a.get(i)));
			w.println("\"");
		}
		
		if(b.size() == 0)
			w.println("-");
		else{
			w.print("\"");
			for(int i=0;i<b.size();i++)
				w.print(i == 0 ? b.get(i) : ("," + b.get(i)));
			w.println("\"");
		}
		
		
		w.close();
	}
	
	static class InputReader {

		private InputStream stream;
		private byte[] buf = new byte[8192];
		private int curChar;
		private int snumChars;
		
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
			return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
		}

	}
}