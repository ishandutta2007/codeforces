import java.io.IOException;
import java.io.InputStream;
import java.util.ArrayList;
import java.util.NoSuchElementException;

public class Main {
    private static FastScanner sc = new FastScanner();

    public static void main(String[] args) {
    	int n = sc.nextInt();
    	ArrayList<ArrayList<Integer>> list = new ArrayList<>();
    	for(int i=0; i<n+1; i++) {
    		list.add(new ArrayList<Integer>());
    	}
    	for(int i=0; i<n; i++) {
    		int a = sc.nextInt();
    		list.get(n-a).add(i);
    	}
    	int now = 1;
    	int[] b = new int[n];
    	for(int i=1; i<=n; i++) {
    		if(list.get(i).size() % i != 0) {
    			System.out.println("Impossible");
    			return;
    		}
    		int cnt = 0;
    		for(int x : list.get(i)) {
    			b[x] = now;
    			cnt++;
    			if(cnt == i) {
    				now++;
    				cnt = 0;
    			}
    		}
    	}
    	System.out.println("Possible");
    	for(int i=0; i<n; i++) {
    		System.out.print(b[i]);
    		if(i != n-1) System.out.print(" ");
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