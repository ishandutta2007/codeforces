import java.io.IOException;
import java.io.InputStream;
import java.util.NoSuchElementException;

public class Main {
    private static FastScanner sc = new FastScanner();

    public static void main(String[] args) {
    	int n = sc.nextInt();
    	int q = sc.nextInt();
    	int[] l = new int[q];
    	int[] r = new int[q];
    	int[] p = new int[n];
    	for(int i=0; i<q; i++) {
    		l[i] = sc.nextInt() - 1;
    		r[i] = sc.nextInt() - 1;
    		for(int j=l[i]; j<=r[i]; j++) {
    			p[j]++;
    		}
    	}
    	int zero = 0;
    	for(int i=0; i<n; i++) {
    		if(p[i] == 0) zero++;
    	}
    	int[] one = new int[n+1];
    	for(int i=1; i<n+1; i++) {
    		one[i] = (p[i-1] == 1) ? one[i-1]+1 : one[i-1];
    	}
    	int[] two = new int[n+1];
    	for(int i=1; i<n+1; i++) {
    		two[i] = (p[i-1] == 2) ? two[i-1]+1 : two[i-1];
    	}
    	int ans = n;
    	for(int i=0; i<q; i++) {
    		for(int j=i+1; j<q; j++) {
    			if(r[i] < l[j] || r[j] < l[i]) {
    				if((one[r[i]+1] - one[l[i]]) + (one[r[j]+1] - one[l[j]]) < ans) {
    					ans = (one[r[i]+1] - one[l[i]]) + (one[r[j]+1] - one[l[j]]);
    				}
    			} else {
    				if((one[Math.max(r[i], r[j])+1] - one[Math.min(l[i], l[j])]) + (two[Math.min(r[i], r[j])+1] - two[Math.max(l[i], l[j])]) < ans) {
    					ans = (one[Math.max(r[i], r[j])+1] - one[Math.min(l[i], l[j])]) + (two[Math.min(r[i], r[j])+1] - two[Math.max(l[i], l[j])]);
    				}
    			}
    		}
    	}
    	System.out.println(n - ans - zero);
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