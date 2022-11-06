import java.io.IOException;
import java.io.InputStream;
import java.util.NoSuchElementException;
 
public class Main {
	private static FastScanner sc = new FastScanner();
	
	public static void main(String[] args) {
		int[] sums = new int[500];
		for(int i=2; i<500; i++) {
			sums[i] = sums[i-1] + (i-1);
		}
		
		int k = sc.nextInt();
		
		if(k == 0) {
			System.out.println("a");
			return;
		}
		
		char c = 'a';
		String s = "";
		while(k > 0) {
			int i = 1;
			for(; i<500; i++) {
				if(sums[i] > k) {
					i--;
					break;
				}
			}
			
			k -= sums[i];
			for(int j=0; j<i; j++) {
				s += c;
			}
			c++;
		}
		
		System.out.println(s);
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