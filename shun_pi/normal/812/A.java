import java.io.IOException;
import java.io.InputStream;
import java.util.NoSuchElementException;

public class Main {
	static FastScanner sc = new FastScanner();

	public static void main(String[] args) {
		boolean A[][] = new boolean[4][4];
		for(int i=0; i<4; i++) {
			for(int j=0; j<4; j++) {
				A[i][j] = sc.nextInt() == 1 ? true : false;
			}
		}
		
		for(int i=0; i<4; i++) {
			if(A[i][3]) {
				if(A[i][0] || A[i][1] || A[i][2] || A[(i+1)%4][0] || A[(i+2)%4][1] || A[(i+3)%4][2]) {
					System.out.println("YES");
					return;
				}
			}
		}
		
		System.out.println("NO");
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