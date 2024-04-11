import java.io.*;
import java.util.*;

public class R210qCLevkoAndArrayRecovery {

	static int limit = (int)1e9;
	
	public static void main(String args[]) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);

		int n = in.nextInt();
		int m = in.nextInt();
		
		long a[] = new long[n + 1];
		
		int type[] = new int[m];
		int l[] = new int[m];
		int r[] = new int[m];
		int dm[] = new int[m];
		
		long curr[] = new long[n + 1];
		long max[] = new long[n + 1];
		
		for(int k=0;k<m;k++){
			type[k] = in.nextInt();
			l[k] = in.nextInt();
			r[k] = in.nextInt();
			dm[k] = in.nextInt();
			if(type[k] == 1){
				for(int i=l[k];i<=r[k];i++){
					curr[i] += dm[k];
					max[i] = Math.max(max[i], curr[i]);
				}
			}
		}
		
		for(int i=1;i<=n;i++)
			a[i] = curr[i] = limit - max[i];
		
		//System.out.println(Arrays.toString(a));
		
		for(int k=0;k<m;k++){
			if(type[k] == 1){
				for(int i=l[k];i<=r[k];i++)
					curr[i] += dm[k];
			}
			else{
				long mx = 0;
				for(int i=l[k];i<=r[k];i++)
					mx = Math.max(mx, curr[i]);
				if(mx < dm[k]){
					System.out.println("NO");
					return;
				}
				for(int i=l[k];i<=r[k];i++){
					a[i] -= Math.max(0,curr[i] - dm[k]);
					curr[i] = Math.min(curr[i],dm[k]);
				}
			}
		}
		
		//System.out.println(Arrays.toString(a));
		
		boolean yes = true;
		for(int i=1;i<=n && yes;i++)
			yes &= Math.abs(a[i]) <= limit;
		
		long ansCopy[] = new long[n + 1];
		System.arraycopy(a, 1, ansCopy, 1, n);
		
		for(int k=0;k<m;k++){
			if(type[k] == 1)
				for(int i=l[k];i<=r[k];i++)
					ansCopy[i] += dm[k];
			else{
				long mx = ansCopy[l[k]];
				for(int i=l[k];i<=r[k];i++)
					mx = Math.max(mx,ansCopy[i]);
				if(mx != dm[k])
					yes = false;
			}
			//System.out.println(Arrays.toString(ansCopy));
		}
		
		if(!yes)
			w.println("NO");
		else{
			w.println("YES");
			for(int i=1;i<=n;i++)
				w.print(a[i] + " ");
			w.println();
		}
		
		w.close();
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