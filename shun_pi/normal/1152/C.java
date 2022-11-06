import java.io.IOException;
import java.io.InputStream;
import java.util.ArrayList;
import java.util.NoSuchElementException;

public class Main {
    private static FastScanner sc = new FastScanner();
    private static boolean DEBUG_FLG = false;

    public static void main(String[] args) {
    	long a = sc.nextLong();
    	long b = sc.nextLong();
    	if(a > b) {
    		long tmp = b;
    		b = a;
    		a = tmp;
    	}
    	long d = b - a;
    	ArrayList<Long> div = new ArrayList<>();
    	for(int i=1; i*i<=d; i++) {
    		if(d%i == 0) {
    			div.add((long)i);
    			div.add(d/i);
    		}
    	}
    	long min = Long.MAX_VALUE;
    	long ktmp = 0;
    	for(long x : div) {
    		long k = x - (a - (a / x) * x);
    		if(k == x) k = 0;
    		long lcm = (a + k) * (b + k) / gcd(a+k, b+k);
    		if(lcm < min) {
    			min = lcm;
    			ktmp = k;
    		} else if(lcm == min && k < ktmp) {
    			ktmp = k;
    		}
    	}
    	System.out.println(ktmp);
    }

    private static long gcd(long x, long y) {
        long biggerNum = Math.max(x, y);
        long smallerNum = Math.min(x, y);
        long surplus = biggerNum % smallerNum;
        if (surplus == 0) {
            return smallerNum;
        }
        surplus = gcd(smallerNum, surplus);

        return surplus;
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