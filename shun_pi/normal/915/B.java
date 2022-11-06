import java.io.IOException;
import java.io.InputStream;
import java.util.NoSuchElementException;
 
public class Main {
	private static FastScanner sc = new FastScanner();
	
	public static void main(String[] args) {
		int n = sc.nextInt();
		int pos = sc.nextInt();
		int l = sc.nextInt();
		int r = sc.nextInt();
		int ans1 = 0;
		int postemp = pos;
		if(l != 1) {
			ans1 += Math.abs(l - postemp);
			postemp = l;
			ans1++;
		}
		if(r != n) {
			ans1 += Math.abs(r - postemp);
			ans1++;
		}
		int ans2 = 0;
		postemp = pos;
		if(r != n) {
			ans2 += Math.abs(r - postemp);
			postemp = r;
			ans2++;
		}
		if(l != 1) {
			ans2 += Math.abs(l - postemp);
			ans2++;
		}
		System.out.println(Math.min(ans1, ans2));
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