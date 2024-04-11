import java.io.IOException;
import java.io.InputStream;
import java.util.NoSuchElementException;

public class Main {
    private static FastScanner sc = new FastScanner();

    public static void main(String[] args) {
    	int n = sc.nextInt();
    	int[] a = new int[n];
    	if(n == 1) {
    		System.out.println(1);
    		return;
    	}
    	if(n == 2) {
    		System.out.println(0);
    		return;
    	}
    	for(int i=0; i<n; i++) {
    		a[i] = sc.nextInt();
    	}
    	int[] left = new int[n];
    	for(int i=0; i<n; i++) {
    		left[i] = a[i];
    	}
    	for(int i=2; i<n; i++) {
    		left[i] += left[i-2];
    	}
    	int[] right = new int[n];
    	for(int i=0; i<n; i++) {
    		right[i] = a[i];
    	}
    	for(int i=n-3; i>=0; i--) {
    		right[i] += right[i+2];
    	}
    	int ans = 0;
    	for(int i=0; i<n; i++) {
    		if(i == 0) {
    			if(right[i+2] == right[i+1]) {
    				ans++;
    				//System.out.println(i+1);
    			}
    		} else if(i == 1) {
    			if(left[i-1] + right[i+2] == right[i+1]) {
    				ans++;
    				//System.out.println(i+1);
    			}
    		} else if(i == n-1) {
    			if(left[i-1] == left[i-2]) {
    				ans++;
    				//System.out.println(i+1);
    			}
    		} else if(i == n-2) {
    			if(left[i-1] == left[i-2] + right[i+1]) {
    				ans++;
    				//System.out.println(i+1);
    			}
    		} else {
    			if(left[i-1] + right[i+2] == left[i-2] + right[i+1]) {
    				ans++;
    				//System.out.println(i+1);
    			}
    		}
    	}
    	System.out.println(ans);
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