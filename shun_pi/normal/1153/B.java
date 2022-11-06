import java.io.IOException;
import java.io.InputStream;
import java.util.NoSuchElementException;

public class Main {
    private static FastScanner sc = new FastScanner();
    private static boolean DEBUG_FLG = false;

    public static void main(String[] args) {
    	int n = sc.nextInt();
    	int m = sc.nextInt();
    	int h = sc.nextInt();
    	int[] a = new int[m];
    	for(int i=0; i<m; i++) {
    		a[i] = sc.nextInt();
    	}
    	int[] b = new int[n];
    	for(int i=0; i<n; i++) {
    		b[i] = sc.nextInt();
    	}
    	int[][] c = new int[n][m];
    	for(int i=0; i<n; i++) {
    		for(int j=0; j<m; j++) {
    			c[i][j] = sc.nextInt();
    		}
    	}
    	for(int i=0; i<n; i++) {
    		for(int j=0; j<m; j++) {
    			if(c[i][j] != 0) {
    				c[i][j] = a[j];
    			}
    		}
    	}
    	for(int i=0; i<n; i++) {
    		for(int j=0; j<m; j++) {
    			if(c[i][j] != 0 && c[i][j] > b[i]) {
    				c[i][j] = b[i];
    			}
    		}
    	}
    	StringBuilder sb = new StringBuilder();
    	for(int i=0; i<n; i++) {
    		for(int j=0; j<m; j++) {
    			if(j != 0) sb.append(" ");
    			sb.append(c[i][j]);
    		}
    		sb.append("\n");
    	}
    	System.out.print(sb);
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