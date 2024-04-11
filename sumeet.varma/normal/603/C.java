import java.io.*;
import java.util.*;

public class R334qCLiegesOfLegendre {

	static int m;
	static int gE[];
	static int gO[];
	
	public static void main(String args[]) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);
		
		m = 20;
		gE = new int[m + 1];
		gO = new int[m + 1];
		gE[0] = gO[0] = 0;
		
		for(int i=1;i<=m;i++){
			boolean we[] = new boolean[5];
			boolean wo[] = new boolean[5];
			we[gE[i - 1]] = true;
			wo[gO[i - 1]] = true;
			if( (i % 2) == 0 ){
				wo[gO[i/2]] = true;
				we[0] = true;
			}
			for(int j=0;j<5;j++){
				if(wo[j] == false){
					gO[i] = j;
					break;
				}
			}
			for(int j = 0 ; j < 5; j++)
				if(we[j] == false){
					gE[i] = j;
					break;
				}
		}
		
		int n = in.nextInt();
		int k = in.nextInt();
		
		int xor = 0;
		boolean even = k % 2 == 0;
		for(int i = 1 ; i <= n; i++){
			int x = in.nextInt();
			if(x <= m){
				if(even)
					xor ^= gE[x];
				else
					xor ^= gO[x];
			}
			else if(even){
				if(x % 2 == 0)
					xor ^= 1;
				else
					xor ^= 0;
			}
			else{
				if(x % 2 == 1)
					xor ^= 0;
				else
					xor ^= get(x);
			}
		}
		
		w.println(xor == 0 ? "Nicky" : "Kevin");
		w.close();
	}
	
	public static int get(int x){
		if(x <= m)
			return gO[x];
		if(x % 2 == 1)
			return 0;
		boolean der[] = new boolean[3];
		der[0] = true;
		der[get(x/2)] = true;
		for(int i=0;i<3;i++)
			if(!der[i])
				return i;
		return -1;
	}
	
	public static boolean get(ArrayList<Integer> l,int k){
		if(l.size() == 0)
			return false;
		boolean wins = false;
		for(int i = 0; i < l.size(); i++){
			ArrayList<Integer> pro = new ArrayList<Integer>();
			for(int j = 0 ; j < l.size(); j++)
				if(j != i)
					pro.add(l.get(j));
				else if(l.get(i) > 1)
					pro.add(l.get(i) - 1);
			wins |= !get(pro , k);
			int x = l.get(i) / 2;
			if(2 * x == l.get(i)){
				pro = new ArrayList<Integer>();
				for(int j = 0 ;j < l.size(); j++)
					if(j != i)
						pro.add(l.get(j));
				for(int j = 0; j < k; j++)
					pro.add(x);
				wins |= !get(pro,k);
			}
		}
		return wins;
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
		
		public int[] nextArray(int n){
			int a[] = new int[n];
			for(int i=0;i<n;i++)
				a[i] = nextInt();
			return a;
		}
		
		public char[][] nextGrid(int n,int m){
			char s[][] = new char[n][m];
			for(int i=0;i<n;i++)
				s[i] = readString().toCharArray();
			return s;
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