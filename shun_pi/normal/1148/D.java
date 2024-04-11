import java.io.IOException;
import java.io.InputStream;
import java.util.ArrayList;
import java.util.NoSuchElementException;

public class Main {
    private static FastScanner sc = new FastScanner();
    private static boolean DEBUG_FLG = false;

    public static void main(String[] args) {
    	int n = sc.nextInt();
    	ArrayList<Set> up = new ArrayList<>();
    	ArrayList<Set> down = new ArrayList<>();
    	for(int i=0; i<n; i++) {
    		int a = sc.nextInt();
    		int b = sc.nextInt();
    		if(a < b) {
        		up.add(new Set(i+1, a, b));
    		} else {
        		down.add(new Set(i+1, a, b));
    		}
    	}
		StringBuilder sb = new StringBuilder();
    	if(up.size() >= down.size()) {
    		up.sort((a, b) -> b.a - a.a);
    		System.out.println(up.size());
    		for(int i=0; i<up.size(); i++) {
    			if(i != 0) sb.append(" ");
    			sb.append(up.get(i).idx);
    		}
    	} else {
    		down.sort((a, b) -> a.a - b.a);
    		System.out.println(down.size());
    		for(int i=0; i<down.size(); i++) {
    			if(i != 0) sb.append(" ");
    			sb.append(down.get(i).idx);
    		}
    	}
    	System.out.println(sb);
    }

    static class Set {
    	int idx;
    	int a;
    	int b;
		public Set(int idx, int a, int b) {
			this.idx = idx;
			this.a = a;
			this.b = b;
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