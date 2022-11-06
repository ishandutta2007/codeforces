import java.io.IOException;
import java.io.InputStream;
import java.util.NoSuchElementException;

public class Main {
    private static FastScanner sc = new FastScanner();

    public static void main(String[] args) {
    	long x1 = sc.nextLong();
    	long y1 = sc.nextLong();
    	long x2 = sc.nextLong();
    	long y2 = sc.nextLong();
    	long n = sc.nextLong();
    	char[] s = sc.next().toCharArray();
    	long windsumx = 0;
    	long windsumy = 0;
    	for(int i=0; i<n; i++) {
    		if(s[i] == 'U') {
    			windsumy++;
    		} else if(s[i] == 'D') {
    			windsumy--;
    		} else if(s[i] == 'R') {
    			windsumx++;
    		} else {
    			windsumx--;
    		}
    	}
    	//System.out.println(windsumx + " " + windsumy + " " + speed);
    	long l = 1;
    	long r = (long) Math.pow(10, 10);
    	long m = 0;
    	while(l < r) {
    		m = (l + r) / 2;
    		//System.out.println(l + " " + r);
    		if((Math.abs(x1 + (windsumx * m) - x2) + Math.abs(y1 + (windsumy * m) - y2)) <= n * m) {
    			r = m;
    		} else {
    			l = m + 1;
    		}
    	}
    	if(r >= (long) Math.pow(10, 10)) {
    		System.out.println(-1);
    		return;
    	}
    	m = (l + r) / 2;
    	m--;
    	x1 += windsumx * m;
    	y1 += windsumy * m;
    	long ans = n * m;
    	//System.out.println(m);
    	for(int i=1; i<=n; i++) {
    		if(s[i-1] == 'U') {
    			y1++;
    		} else if(s[i-1] == 'D') {
    			y1--;
    		} else if(s[i-1] == 'R') {
    			x1++;
    		} else {
    			x1--;
    		}
    		if((Math.abs(x1 - x2) + Math.abs(y1 - y2)) <= n * m + (long)i) {
    			System.out.println(ans + (long)i);
    			return;
    		}
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