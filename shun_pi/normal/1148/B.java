import java.io.IOException;
import java.io.InputStream;
import java.util.NoSuchElementException;

public class Main {
    private static FastScanner sc = new FastScanner();
    private static boolean DEBUG_FLG = false;

    public static void main(String[] args) {
    	int n = sc.nextInt();
    	int m = sc.nextInt();
    	long ta = sc.nextLong();
    	long tb = sc.nextLong();
    	int k = sc.nextInt();
    	long[] a = new long[n];
    	for(int i=0; i<n; i++) {
    		a[i] = sc.nextLong() + ta;
    	}
    	long[] b = new long[m];
    	for(int i=0; i<m; i++) {
    		b[i] = sc.nextLong();
    	}
    	if(k >= n || k >= m) {
    		System.out.println(-1);
    		return;
    	}
    	long maxtb = 0;
    	for(int i=0; i<=k; i++) {
    		long t = a[i];
    		int l = 0;
    		int r = m-1;
    		int mm = (l+r) / 2;
    		if(a[i] > b[m-1]) {
    			System.out.println(-1);
        		return;
    		}
    		while(l < r) {
    			mm = (l+r) / 2;
    			if(b[mm] >= t) {
    				r = mm;
    			} else if(b[mm] < t) {
    				l = mm + 1;
    			}
    		}
    		mm = l;
    		if(mm + (k-i) >= m) {
    			System.out.println(-1);
        		return;
    		}
    		if(b[mm + (k-i)] > maxtb) {
    			maxtb = b[mm + (k-i)];
    		}
     	}
    	System.out.println(maxtb + tb);
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