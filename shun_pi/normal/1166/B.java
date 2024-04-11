import java.io.IOException;
import java.io.InputStream;
import java.util.NoSuchElementException;

public class Main {
    private static FastScanner sc = new FastScanner();
    private static boolean DEBUG_FLG = false;

    public static void main(String[] args) {
    	int k = sc.nextInt();
    	for(int r=5; r<=2000; r++) {
    		for(int c=r; c*r<=10000; c++) {
    			if(r * c == k) {
    				StringBuilder ans = new StringBuilder();
    				for(int i=0; i<r; i++) {
    					if(i == 0) {
    						ans.append("aeiou");
    					} else if(i == 1){
    						ans.append("uaeio");
    					} else if(i == 2) {
    						ans.append("ouaei");
    					} else if(i == 3) {
    						ans.append("iouae");
    					} else if(i == 4) {
    						ans.append("eioua");
    					} else {
    						ans.append("aeiou");
        				}
    					for(int j=5; j<c; j++) {
    						if(i == 0) {
    							ans.append("a");
    						} else if(i == 1) {
    							ans.append("e");
    						} else if(i == 2) {
    							ans.append("i");
    						} else if(i == 3) {
    							ans.append("o");
    						} else {
    							ans.append("u");
    						}
        				}
    				}
    				System.out.println(ans);
    				return;
    			}
    		}
    	}
    	System.out.println(-1);
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