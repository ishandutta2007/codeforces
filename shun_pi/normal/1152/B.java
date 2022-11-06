import java.io.IOException;
import java.io.InputStream;
import java.util.ArrayList;
import java.util.NoSuchElementException;

public class Main {
    private static FastScanner sc = new FastScanner();
    private static boolean DEBUG_FLG = false;

    public static void main(String[] args) {
    	int x = sc.nextInt();
    	int t=0;
    	int now = x;
    	ArrayList<Integer> ans = new ArrayList<>();
    	while(true) {
    		t++;
    		for(int i=0; i<=20; i++) {
    			if(i == 20 || (now >> i)%2 == 1) {
    				now += (int)Math.pow(2, i) - 1;
    				ans.add(i);
    				boolean flg = false;
    				for(int j=0; j<=20; j++) {
    					if(now == (int)Math.pow(2, j) - 1) {
    						flg = true;
    						break;
    					}
    				}
    				if(i == 20 || flg) {
    					System.out.println(t);
    					for(int j=0; j<ans.size(); j++) {
    						if(j != 0) System.out.print(" ");
    						System.out.print(ans.get(j));
    					}
    					System.out.println();
    					return;
    				}
    				break;
    			}
    		}
    		now++;
    		t++;
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