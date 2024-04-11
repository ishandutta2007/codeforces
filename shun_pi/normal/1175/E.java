import java.io.IOException;
import java.io.InputStream;
import java.util.NoSuchElementException;
import java.util.Random;

public class Main {
    private static FastScanner sc = new FastScanner();
    private static boolean DEBUG_FLG = false;

    public static void main(String[] args) {
    	int n = sc.nextInt();
    	int m = sc.nextInt();
    	int[] l = new int[n];
    	int[] r = new int[n];
    	int[][] dp = new int[500001][18];
    	for(int i=0; i<n; i++) {
    		l[i] = sc.nextInt();
    		r[i] = sc.nextInt();
    		if(r[i] > dp[l[i]][0]) {
    			dp[l[i]][0] = r[i];
    		}
    	}
    	for(int i=1; i<=500000; i++) {
    		if(dp[i-1][0] > dp[i][0]) {
    			dp[i][0] = dp[i-1][0];
    		}
    	}
    	for(int k=1; k<18; k++) {
    		for(int i=0; i<=500000; i++) {
        		dp[i][k] = dp[dp[i][k-1]][k-1];
        	}
    	}
    	StringBuilder sb = new StringBuilder();
    	for(int i=0; i<m; i++) {
    		int x = sc.nextInt();
    		int y = sc.nextInt();

    		int ll = 1;
    		int rr = n+1;
    		int mm = (ll + rr) / 2;
    		while(ll < rr) {
    			int tmp = x;
    			for(int j=0; j<18; j++) {
    				if((mm >> j & 1) == 1) {
    					tmp = dp[tmp][j];
    				}
    			}
    			if(tmp >= y) {
    				rr = mm;
    			} else {
    				ll = mm + 1;
    			}
    			mm = (ll + rr) / 2;
    		}
    		if(mm >= n+1) {
    			sb.append(-1 + "\n");
    		} else {
        		sb.append(mm + "\n");
    		}
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

    static void shuffleArray(long[] arr){
        int n = arr.length;
        Random rnd = new Random();
        for(int i=0; i<n; ++i){
            long tmp = arr[i];
            int randomPos = i + rnd.nextInt(n-i);
            arr[i] = arr[randomPos];
            arr[randomPos] = tmp;
        }
    }
}