import java.io.IOException;
import java.io.InputStream;
import java.util.NoSuchElementException;

public class Main {
    private static FastScanner sc = new FastScanner();
    private static long mod = 1000000007;

    public static void main(String[] args) {
    	int n = sc.nextInt();
    	int T = sc.nextInt();
    	int[] t = new int[n];
    	int[] g = new int[n];
    	for(int i=0; i<n; i++) {
    		t[i] = sc.nextInt();
    		g[i] = sc.nextInt() - 1;
    	}
    	long[][][] dp = new long[T+1][3][1 << 15];
    	for(int i=1; i<=T; i++) {
    		for(int j=0; j<n; j++) {
    			if(i - t[j] == 0) {
    				dp[i][g[j]][1 << j] = (dp[i][g[j]][1 << j] + 1) % mod;
    			} else if(i - t[j] > 0) {
    				for(int k=0; k<(1 << 15); k++) {
    					if((k >> j & 1) == 1) {
    						continue;
    					}
    					dp[i][g[j]][k + (1 << j)] = (dp[i][g[j]][k + (1 << j)] + dp[i - t[j]][(g[j] + 1) % 3][k] + dp[i - t[j]][(g[j] + 2) % 3][k]) % mod;
    				}
    			}
    		}
    	}
    	long ans = 0;
    	for(int j=0; j<3; j++) {
    		for(int k=0; k<(1 << 15); k++) {
    			ans = (ans + dp[T][j][k]) % mod;
    		}
    	}
    	System.out.println(ans);
    }

    static long power(long m , long n){
    	if(n == 0) {
    		return 1;
    	}else if(n == 1){
            return m;
        }else if(n % 2 == 0){
            long s = power(m, n/2);
            return ( (s % mod) * (s % mod) ) % mod;
        }else{
            return ( (m % mod) * (power(m, n-1) % mod) ) % mod;
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