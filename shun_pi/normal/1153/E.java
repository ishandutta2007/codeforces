import java.io.IOException;
import java.io.InputStream;
import java.util.ArrayList;
import java.util.NoSuchElementException;

public class Main {
    private static FastScanner sc = new FastScanner();
    private static boolean DEBUG_FLG = false;

    public static void main(String[] args) {
    	int n = sc.nextInt();
    	ArrayList<Integer> ansx = new ArrayList<>();
    	ArrayList<Integer> ansy = new ArrayList<>();
    	for(int i=1; i<=n; i++) {
    		System.out.println("? " + i + " 1 " + i + " " + n);
    		System.out.flush();
    		int ans = sc.nextInt();
    		if(ans % 2 == 1) {
    			int l = 1;
    			int r = n;
    			int m = (l + r) / 2;
    			while(l < r) {
    				m = (l + r) / 2;
    				System.out.println("? " + i + " " + l + " " + i + " " + m);
    				System.out.flush();
    				ans = sc.nextInt();
    				if(ans % 2 == 1) {
    					r = m;
    				} else {
    					l = m + 1;
    				}
    			}
    			m = (l + r) / 2;
    			ansx.add(i);
    			ansy.add(m);
    			if(ansx.size() == 2) {
    				System.out.println("! " + ansx.get(0) + " " + ansy.get(0) + " " + ansx.get(1) + " " + ansy.get(1));
    				System.out.flush();
    				return;
    			}
    		}
    	}
    	for(int i=1; i<=n; i++) {
    		int ans = 1;
    		if(i != n) {
        		System.out.println("? 1 " + i + " " + n + " " + i);
        		System.out.flush();
        		ans = sc.nextInt();
    		}
    		if(ans % 2 == 1) {
    			int l = 1;
    			int r = n;
    			int m = (l + r) / 2;
    			while(l < r) {
    				m = (l + r) / 2;
    				System.out.println("? " + l + " " + i + " " + m + " " + i);
    				System.out.flush();
    				ans = sc.nextInt();
    				if(ans % 2 == 1) {
    					r = m;
    				} else {
    					l = m + 1;
    				}
    			}
    			m = (l + r) / 2;
    			ansx.add(m);
    			ansy.add(i);
    			if(ansx.size() == 2) {
    				System.out.println("! " + ansx.get(0) + " " + ansy.get(0) + " " + ansx.get(1) + " " + ansy.get(1));
    				System.out.flush();
    				return;
    			}
    		}
    	}
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