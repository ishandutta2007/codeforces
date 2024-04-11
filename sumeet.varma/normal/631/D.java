import java.io.*;
import java.util.*;

public class R344qD {

	public static void main(String[] args) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);

		int n = in.nextInt();
		int m = in.nextInt();
		
		int s[] = new int[n];
		int t[] = new int[m];
		
		long sl[] = new long[n];
		long tl[] = new long[m];
		
		int si[] = new int[n];
		int ti[] = new int[m];
		
		@SuppressWarnings("unchecked")
		HashMap<Long, Integer> map[] = new HashMap[26];
		for(int i = 0; i < 26; i++)
			map[i] = new HashMap<Long, Integer>();
		
		int glo = 0;
		int k = 0;
		int prev = -1;
		long curr = 0;
		
		for(int i = 0; i < n; i++){
			String p[] = in.readString().split("-");
			int l = Integer.parseInt(p[0]);
			int x = p[1].charAt(0) - 'a';
			if(x == prev)
				curr += l;
			else{
				if(prev != -1){
					s[k] = prev;
					sl[k++] = curr;
				}
				curr = l;
				prev = x;
			}
		}
		
		s[k] = prev;
		sl[k++] = curr;
		n = k;
		
		for(int i = 0; i < n; i++){
			if(map[s[i]].containsKey(sl[i]))
				si[i] = map[s[i]].get(sl[i]);
			else{
				si[i] = glo;
				map[s[i]].put(sl[i], glo++);
			}
		}
		
		k = 0;
		prev = -1;
		curr = 0;
		
		for(int i = 0; i < m; i++){
			String p[] = in.readString().split("-");
			int l = Integer.parseInt(p[0]);
			int x = p[1].charAt(0) - 'a';
			if(x == prev)
				curr += l;
			else{
				if(prev != -1){
					t[k] = prev;
					tl[k++] = curr;
				}
				curr = l;
				prev = x;
			}
		}
		
		t[k] = prev;
		tl[k++] = curr;
		m = k;
		
		for(int i = 0; i < m; i++){
			if(map[t[i]].containsKey(tl[i]))
				ti[i] = map[t[i]].get(tl[i]);
			else{
				ti[i] = glo;
				map[t[i]].put(tl[i], glo++);
			}
		}
		
		
		if(m == 1){
			long ans = 0;
			for(int i = 0; i < n; i++){
				if(s[i] == t[0])
					ans += Math.max(0, sl[i] - tl[0] + 1);
			}
			w.println(ans);
			w.close();
			return;
		}
		
		if(m == 2){
			long ans = 0;
			for(int i = 0; i + 1 < n; i++){
				if(s[i] == t[0] && s[i + 1] == t[1]){
					if(sl[i] >= tl[0] && sl[i + 1] >= tl[1])
						ans++;
				}
			}
			w.println(ans);
			w.close();
			return;
		}
		
		int Z[] = new int[n + m - 2];
		k = 0;
		for(int i = 1; i < m - 1; i++)
			Z[k++] = ti[i];
		int here = k;
		for(int i = 0; i < n; i++)
			Z[k++] = si[i];
		
		int z[] = zFunction(Z);
		int ans = 0;
		int last;
		
		//System.out.println(Arrays.toString(Z));
		//System.out.println(Arrays.toString(z));
		//System.out.println(here);
		
		for(int i = here + 1; (i - 1) + (m - 1) < k; i++){
			if(z[i] >= m - 2){
				prev = i - 1 - here;
				last = prev + m - 1;
				if(s[prev] == t[0] && s[last] == t[m - 1]){
					if(sl[prev] >= tl[0] && sl[last] >= tl[m - 1])
						ans++;
				}
			}
		}
		
		w.println(ans);
		w.close();
	}
	
	public static int[] zFunction(int pat[]) {
		int n = pat.length;
		int z[] = new int[n];

		int l = 0, r = 0;
		for (int i = 1; i < n; i++) {
			if (i > r) {
				l = r = i;
				while (r < n && pat[r - l] == pat[r])
					r++;
				z[i] = r - l;
				r--;
			} else {
				int k = i - l;
				if (z[k] < r - i + 1)
					z[i] = z[k];
				else {
					l = i;
					while (r < n && pat[r - l] == pat[r])
						r++;
					z[i] = r - l;
					r--;
				}
			}
		}

		// z[0] = 0 , n;
		return z;
	}

	static class InputReader {

		private InputStream stream;
		private byte[] buf = new byte[8192];
		private int curChar, snumChars;
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

		public int[] nextIntArray(int n) {
			int a[] = new int[n];
			for (int i = 0; i < n; i++)
				a[i] = nextInt();
			return a;
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