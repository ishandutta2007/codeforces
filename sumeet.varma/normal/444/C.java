import java.io.*;
import java.util.*;

public class R254qCDzyLovesColors {

	static int bs[],be[],id[],bState[],bSize[],pState[];
	static long ca[],ta[],pa[];
	
	public static void main(String args[]) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);
		
		final int n = in.nextInt();
		final int m = in.nextInt();
		
		final int size = 220;
		final int blocks = n % size == 0 ? n/size : (n/size+1);
		
		bs = new int[blocks];
		be = new int[blocks];
		id = new int[n];
		ca = new long[blocks];
		ta = new long[blocks];
		bState = new int[blocks];
		bSize = new int[blocks];
		pa = new long[n];
		pState = new int[n];
		for(int i=0;i<n;i++)
			pState[i] = i + 1;
		
		for(int i=0;i<blocks;i++){
			bs[i] = i*size;
			be[i] = Math.min(n, i*size + size) - 1;
			for(int j=bs[i];j<=be[i];j++)
				id[j] = i;
			bSize[i] = be[i] - bs[i] + 1;
		}
		
		/*
		System.out.println(Arrays.toString(bs));
		System.out.println(Arrays.toString(be));
		System.out.println(Arrays.toString(id));
		System.out.println(Arrays.toString(pState));
		System.out.println(Arrays.toString(bSize));
		*/
		
		for(int q=0;q<m;q++){
			
			int type = in.nextInt();
			int l = in.nextInt() - 1;
			int r = in.nextInt() - 1;

			int b1 = id[l];
			int b2 = id[r];
			
			if(type == 1){
				int x = in.nextInt();
				
				if(b1 == b2){
	
					relax(b1);
					
					for(int i=l;i<=r;i++){
						pa[i] += Math.abs(pState[i] - x);
						ta[b1] += Math.abs(pState[i] - x);
						pState[i] = x;
					}
					
					bState[b1] = 0;
				}
				
				else{
					
					relax(b1);
					relax(b2);
					
					for(int i=l;i<=be[b1];i++){
						pa[i] += Math.abs(pState[i] - x);
						ta[b1] += Math.abs(pState[i] - x);
						pState[i] = x;
					}
					
					for(int i=bs[b2];i<=r;i++){
						pa[i] += Math.abs(pState[i] - x);
						ta[b2] += Math.abs(pState[i] - x);
						pState[i] = x;
					}
					
					for(int i=b1+1;i<b2;i++)
						change(i,x);
					
				}
				
			}
			
			else{
				
				long ans = 0;
				
				if(b1 == b2){
					
					relax(b1);
					for(int i=l;i<=r;i++)
						ans += pa[i] + ca[b1];
					
				}
				
				else{
					
					relax(b1);
					relax(b2);
					
					for(int i=l;i<=be[b1];i++)
						ans += pa[i] + ca[b1];
					
					for(int i=b1+1;i<b2;i++)
						ans += ta[i];
					
					for(int i=bs[b2];i<=r;i++)
						ans += pa[i] + ca[b2];
				}
				
				w.println(ans);
			}
			
			/*
			System.out.println(Arrays.toString(ca));
			System.out.println(Arrays.toString(ta));
			System.out.println(Arrays.toString(pa));
			System.out.println(Arrays.toString(bState));
			System.out.println(Arrays.toString(pState));
			*/
		}
		
		w.close();
	}
	
	static void relax(int blockID){
		if(bState[blockID] != 0){
			for(int i=bs[blockID];i<=be[blockID];i++)
				pState[i] = bState[blockID];
			bState[blockID] = 0;
		}
	}
	
	static void change(int blockID,int x){
		if(bState[blockID] != 0){
			ca[blockID] += Math.abs(x - bState[blockID]);
			ta[blockID] += bSize[blockID] * 1L * Math.abs(x - bState[blockID]);
		}
		else{
			for(int i=bs[blockID];i<=be[blockID];i++){
				pa[i] += Math.abs(x - pState[i]);
				ta[blockID] += Math.abs(x - pState[i]);
			}
		}
		bState[blockID] = x;
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