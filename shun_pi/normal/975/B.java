import java.io.IOException;
import java.io.InputStream;
import java.util.NoSuchElementException;
 
public class Main {
	private static FastScanner sc = new FastScanner();
	
	public static void main(String[] args) {
		long[] a = new long[14];
		for(int i=0; i<14; i++) {
			a[i] = sc.nextLong();
		}
		long maxscore = 0;
		for(int i=0; i<14; i++) {
			long[] at = new long[14];
			for(int j=0; j<14; j++) {
				at[j] = a[j];
			}
			if(at[i] == 0) continue;
			long div = at[i] / 14;
			long rem = at[i] % 14;
			at[i] = 0;
			long score = 0;
			for(int j=0; j<14; j++) {
				if(((j + 14) - i) % 14 > 0 && ((j + 14) - i) % 14 <= rem) {
					at[j] += div + 1;
				} else {
					at[j] += div;
				}
				if(at[j] % 2 == 0) score += at[j];
			}
			if(score > maxscore) maxscore = score;
		}
		System.out.println(maxscore);
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