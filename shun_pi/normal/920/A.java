import java.io.IOException;
import java.io.InputStream;
import java.util.NoSuchElementException;
 
public class Main {
	private static FastScanner sc = new FastScanner();
	
	public static void main(String[] args) {
		int T = sc.nextInt();
		for(int t=0; t<T; t++) {
			int n = sc.nextInt();
			int k = sc.nextInt();
			boolean[] w = new boolean[n];
			for(int i=0; i<k; i++) {
				w[sc.nextInt()-1] = true;
			}
			int s = 1;
			while(true) {
				boolean flag = false;
				for(int i=0; i<n; i++) {
					if(!w[i]) {
						flag = true;
						break;
					}
				}
				if(!flag) break;
				s++;
				boolean[] wtemp = new boolean[n];
				for(int i=0; i<n; i++) {
					if(w[i]) {
						if(i != 0) wtemp[i-1] = true;
						wtemp[i] = true;
						if(i != n-1) wtemp[i+1] = true;
					}
				}
				w = wtemp;
			}
			System.out.println(s);
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