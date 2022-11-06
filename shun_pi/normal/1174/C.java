import java.io.IOException;
import java.io.InputStream;
import java.util.NoSuchElementException;

public class Main {
    private static FastScanner sc = new FastScanner();
    private static boolean DEBUG_FLG = false;

    public static void main(String[] args) {
    	int n = sc.nextInt();
    	int[] prime = new int[100001];
    	for(int i=2; i<=100000; i++) {
    		prime[i] = 0;
    	}
    	for(int i=2; i<=100000; i++) {
    		if(prime[i] == 0) {
    			for(int j=i*2; j<=100000; j+=i) {
    				if(prime[j] == 0) prime[j] = i;
    			}
    		}
    	}

    	int num = 0;
    	int[] ans = new int[100001];
    	for(int i=2; i<=n; i++) {
    		if(prime[i] == 0) {
    			num++;
    			ans[i] = num;
    		} else {
    			ans[i] = ans[prime[i]];
    		}
    	}
    	StringBuilder sb = new StringBuilder();
    	for(int i=2; i<=n; i++) {
    		if(i != 2) sb.append(" ");
    		sb.append(ans[i]);
    	}
    	System.out.println(sb);
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