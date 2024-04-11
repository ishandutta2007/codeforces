import java.io.IOException;
import java.io.InputStream;
import java.util.NoSuchElementException;

public class Main {
    private static FastScanner sc = new FastScanner();
    private static boolean DEBUG_FLG = false;

    public static void main(String[] args) {
    	int n = sc.nextInt();
    	char[] s = sc.next().toCharArray();
    	int min = Integer.MAX_VALUE;
    	for(int i=0; i<n-3; i++) {
    		int x = 0;
    		x += Math.min(Math.min(Math.abs('A' - s[i] + 26), Math.abs('A' - s[i])), Math.abs('A' - s[i] - 26));
    		x += Math.min(Math.min(Math.abs('C' - s[i+1] + 26), Math.abs('C' - s[i+1])), Math.abs('C' - s[i+1] - 26));
    		x += Math.min(Math.min(Math.abs('T' - s[i+2] + 26), Math.abs('T' - s[i+2])), Math.abs('T' - s[i+2] - 26));
    		x += Math.min(Math.min(Math.abs('G' - s[i+3] + 26), Math.abs('G' - s[i+3])), Math.abs('G' - s[i+3] - 26));
    		if(x < min) min = x;
    	}
    	System.out.println(min);
    }

    static void debug(long... args) {
    	if(!DEBUG_FLG) return;
    	boolean flg = false;
    	for(long s : args) {
    		if(flg) System.out.print(" ");
    		flg = true;
    		System.out.print(s);
    	}
    	System.out.println();
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