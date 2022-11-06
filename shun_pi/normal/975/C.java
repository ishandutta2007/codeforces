import java.io.IOException;
import java.io.InputStream;
import java.util.NoSuchElementException;
 
public class Main {
	private static FastScanner sc = new FastScanner();
	
	public static void main(String[] args) {
		int n = sc.nextInt();
		int q = sc.nextInt();
		long[] a = new long[n];
		long[] asum = new long[n];
		long sum = 0;
		for(int i=0; i<n; i++) {
			a[i] = sc.nextLong();
			if(i != 0) asum[i] = asum[i-1] + a[i-1];
			sum += a[i];
		}
		long[] k = new long[q];
		for(int i=0; i<q; i++) {
			k[i] = sc.nextLong();
		}
		long nowdmg = 0;
		for(int i=0; i<q; i++) {
			nowdmg += k[i];
			if(nowdmg >= sum) {
				System.out.println(n);
				nowdmg = 0;
				continue;
			}
			int l = 0;
			int r = n-1;
			int m = (l + r) / 2;
			while(l <= r) {
				m = (l + r) / 2;
//				System.out.println(l + " " + r + " " + m);
				if(m == n-1 || (asum[m] <= nowdmg && nowdmg < asum[m+1])) {
					break;
				}
				if(nowdmg < asum[m]) {
					r = m-1;
				} else {
					l = m+1;
				}
			}
			System.out.println(n - m);
		}
	}
	
	static class FastScanner {
        private final InputStream in = System.in;
        private final byte[] buffer = new byte[1024];
        private int ptr = 0;
        private int buflen = 0;
        private boolean hasNextByte() {
            if(ptr < buflen) {
                return true;
            } else {
                ptr = 0;
                try {
                    buflen = in.read(buffer);
                } catch(IOException e) {
                    e.printStackTrace();
                }
                if(buflen <= 0) {
                    return false;
                }
            }
            return true;
        }
        private int readByte() { if (hasNextByte()) return buffer[ptr++]; else return -1;}
        private static boolean isPrintableChar(int c) { return 33 <= c && c <= 126;}
        private void skipUnprintable() { while(hasNextByte() && !isPrintableChar(buffer[ptr])) ptr++;}
        public boolean hasNext() { skipUnprintable(); return hasNextByte();}
        public String next() {
            if (!hasNext()) throw new NoSuchElementException();
            StringBuilder sb = new StringBuilder();
            int b = readByte();
            while(isPrintableChar(b)) {
                sb.appendCodePoint(b);
                b = readByte();
            }
            return sb.toString();
        }
        public long nextLong() {
            return Long.parseLong(next());
        }
        public int nextInt(){
            return Integer.parseInt(next());
        }
        public double nextDouble(){
            return Double.parseDouble(next());
        }
    }
}