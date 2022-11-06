import java.io.IOException;
import java.io.InputStream;
import java.util.NoSuchElementException;
 
public class Main {
	private static FastScanner sc = new FastScanner();
	
	public static void main(String[] args) {
		String ss = sc.next();
		String ts = sc.next();
		int n = sc.nextInt();
		
		int s = 0;
		int t = 0;
		if(ss.equals("^")) {
			s = 0;
		} else if(ss.equals(">")) {
			s = 1;
		} else if(ss.equals("v")) {
			s = 2;
		} else {
			s = 3;
		}
		if(ts.equals("^")) {
			t = 0;
		} else if(ts.equals(">")) {
			t = 1;
		} else if(ts.equals("v")) {
			t = 2;
		} else {
			t = 3;
		}
		
		if((t - s + 4) % 4 == 2 || (t - s + 4) % 4 == 0) {
			System.out.println("undefined");
		} else if((t - s + 4) % 4 == 1) {
			if(n % 4 == 1) {
				System.out.println("cw");
			} else {
				System.out.println("ccw");
			}
		} else {
			if(n % 4 == 3) {
				System.out.println("cw");
			} else {
				System.out.println("ccw");
			}
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