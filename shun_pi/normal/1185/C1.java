import java.io.IOException;
import java.io.InputStream;
import java.util.NoSuchElementException;
import java.util.Random;

public class Main {
    private static FastScanner sc = new FastScanner();
    private static boolean DEBUG_FLG = false;

    public static void main(String[] args) {
    	int n = sc.nextInt();
    	int M = sc.nextInt();
    	int[] t = new int[n];
    	for(int i=0; i<n; i++) {
    		t[i] = sc.nextInt();
    	}
    	int sum = 0;
    	int[] tnum = new int[101];
    	StringBuilder sb = new StringBuilder();
    	for(int i=0; i<n; i++) {
    		if(i != 0) sb.append(" ");

    		sum += t[i];
    		int tmp = sum - M;
    		if(tmp > 0) {
    			int ans = 0;
    			for(int j=100; j>=1; j--) {
    				if(tmp - j * tnum[j] <= 0) {
    					ans += Math.ceil((double)tmp / (double)j);
    					break;
    				} else {
    					tmp -= j * tnum[j];
    					ans += tnum[j];
    				}
        		}
    			sb.append(ans);
    		} else {
    			sb.append(0);
    		}
    		tnum[t[i]]++;
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