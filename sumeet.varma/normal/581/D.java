import java.io.*;
import java.util.*;

public class R322qD {

	static PrintWriter w;
	static int n;
	
	public static void main(String args[]) {
		InputReader in = new InputReader(System.in);
		w = new PrintWriter(System.out);
		
		int x[] = new int[3];
		int y[] = new int[3];
		
		for(int i=0;i<3;i++){
			x[i] = in.nextInt();
			y[i]  = in.nextInt();
		}
		
		for(int i=0;i<8;i++){
			int X[] = new int[3];
			int Y[] = new int[3];
			for(int j=0;j<3;j++){
				if ( ((1<<j) & i) != 0){
					X[j] = y[j];
					Y[j] = x[j];
				}
				else{
					X[j] = x[j];
					Y[j] = y[j];
				}
			}
			if(wow(X,Y)){
				w.close();
				return;
			}
		}
		
		w.println(-1);
		w.close();
	}
	
	public static boolean wow(int x[],int y[]){
		int area = 0;
		for(int i=0;i<3;i++)
			area += x[i] * y[i];
		n = (int)(Math.sqrt(area) + 0.01);
		if(n*n != area){
			if( (n + 1) * (n + 1) != area){
				if( (n - 1) * (n - 1) != area )
					return false;
				else
					n--;
			}
			else
				n++;
		}
		//now n*n = area;
		char ans[][] = new char[n][n];
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				ans[i][j] = ' ';
		
		boolean yes = go(x,y,0,ans);
		
		if(yes){
			w.println(n);
			for(int i=0;i<n;i++)
				w.println(new String(ans[i]));
		}
		
		return yes;
	}
	
	static boolean go(int x[],int y[],int z,char ans[][]){

		if(z == 3){
			for(int i=0;i<n;i++)
				for(int j=0;j<n;j++)
					if(ans[i][j] == ' ')
						return false;
			return true;
		}
		else{
			int firstRowX = -1,firstRowY = -1;
			for(int i=0;i<n && firstRowX == -1;i++)
				for(int j=0;j<n && firstRowX == -1;j++)
					if(ans[i][j] == ' '){
						firstRowX = i;
						firstRowY = j;
					}
			
			char X = (char)('A' + z);
			boolean hmm = true;
			for(int i=firstRowX;hmm && i<(firstRowX + x[z]);i++){
				for(int j=firstRowY;hmm && j<(firstRowY + y[z]);j++){
					if(i >= n || j >= n || i < 0 || j < 0 || ans[i][j] != ' ')
						hmm = false;
				}
			}
			if(hmm){
				for(int i=firstRowX;i<(firstRowX + x[z]);i++)
					for(int j=firstRowY;j<(firstRowY + y[z]);j++)
						ans[i][j] = X;
				if(go(x,y,z+1,ans))
					return true;
				for(int i=firstRowX;i<(firstRowX + x[z]);i++)
					for(int j=firstRowY;j<(firstRowY + y[z]);j++)
						ans[i][j] = ' ';
			}
			
			int firstColX = -1,firstColY = -1;
			for(int j=0;j<n && firstColX == -1;j++)
				for(int i=0;i<n && firstColX == -1;i++)
					if(ans[i][j] == ' '){
						firstColX = i;
						firstColY = j;
					}
			
			hmm = true;
			for(int i=firstColX;hmm && i<(firstColX + x[z]);i++)
				for(int j=firstColY;hmm && j<(firstColY + y[z]);j++)
					if(i >= n || j >= n || i < 0 || j < 0 || ans[i][j] != ' ')
						hmm = false;
			
			if(hmm){
				for(int i=firstColX;i<(firstColX + x[z]);i++)
					for(int j=firstColY;j<(firstColY + y[z]);j++)
						ans[i][j] = X;
				if(go(x,y,z+1,ans))
					return true;
				for(int i=firstColX;i<(firstColX + x[z]);i++)
					for(int j=firstColY;j<(firstColY + y[z]);j++)
						ans[i][j] = ' ';
			}
			
			return false;
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