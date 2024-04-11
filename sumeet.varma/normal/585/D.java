import java.io.*;
import java.util.*;

public class R325qD  {
	
	final static long para = (int)1e9 + 7;

	public static void main(String args[]) {
		InputReader in = new InputReader(System.in);
		PrintWriter p = new PrintWriter(System.out);
		
		int pow3[] = new int[16];
		pow3[0] = 1;
		for(int i=1;i<16;i++)
			pow3[i] = pow3[i-1] * 3;
		
		int n = in.nextInt();
		
		int inp[][] = new int[n][3];
		for(int i=0;i<n;i++)
			for(int j=0;j<3;j++)
				inp[i][j] = in.nextInt();
		
		HashMap<Long,Pair> left = new HashMap<Long,Pair>();
		
		int n2 = n >> 1;
		int L = pow3[n2];
		
		int proVal[] = new int[3];
		for(int i=0;i<n2;i++)
			for(int j=0;j<3;j++)
				proVal[j] += inp[i][j];
		
		for(int i=0;i<L;i++){
			int val[] = Arrays.copyOf(proVal, 3);
			int curr = i;
			for(int j=0;j<n2;j++){
				val[curr % 3] -= inp[j][curr % 3];
				curr /= 3;
			}
			
			int base = val[0];
			val[1] -= base;
			val[2] -= base;
			
			long nowHash = getHash(val[1],val[2]);
			
			if(left.containsKey(nowHash)){
				Pair hash = left.get(nowHash);
				if(base > hash.base)
					left.put(nowHash, new Pair(base,i));
			}
			else
				left.put(nowHash,new Pair(base,i));
		}		
		
		proVal = new int[3];
		for(int i=n2;i<n;i++)
			for(int j=0;j<3;j++)
				proVal[j] += inp[i][j];
		
		int R = pow3[n - n2];
		
		int ans = Integer.MIN_VALUE,wowLeft = -1,wowRight = -1;
		
		for(int i=0;i<R;i++){
			int val[] = Arrays.copyOf(proVal, 3);
			int curr = i;
			
			for(int j=n2;j<n;j++){
				val[curr % 3] -= inp[j][curr % 3];
				curr /= 3;
			}

			int base = val[0];
			val[1] -= base;
			val[2] -= base;
			
			long nowHash = getHash(-val[1],-val[2]);
			
			if(left.containsKey(nowHash)){
				Pair pro = left.get(nowHash);
				//System.out.println(proBase + " " + proLeft + " " + i);
				if(pro.base + base > ans){
					ans = pro.base + base;
					wowLeft = pro.idx;
					wowRight = i;
				}
			}
		}
		
		if(ans == Integer.MIN_VALUE)
			p.println("Impossible");
		else{
			for(int j=0;j<n2;j++){
				long shit = wowLeft % 3;
				wowLeft /= 3;
				if(shit == 0)
					p.println("MW");
				else if(shit == 1)
					p.println("LW");
				else
					p.println("LM");
			}
			for(int j=n2;j<n;j++){
				long shit = wowRight % 3;
				wowRight /= 3;
				if(shit == 0)
					p.println("MW");
				else if(shit == 1)
					p.println("LW");
				else
					p.println("LM");
			}
		}
		
		p.close();
	}
	
	static class Pair{
		int base,idx;
		Pair(int base,int idx){
			this.base = base;
			this.idx = idx;
		}
	}
	
	static long getHash(int y,int z){
		return para * y + z;
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