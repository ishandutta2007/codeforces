import java.io.IOException;
import java.io.InputStream;
import java.util.NoSuchElementException;

public class Main {
	private static FastScanner sc = new FastScanner();
	
	public static void main(String[] args) {
		int n = sc.nextInt();
		int k = sc.nextInt();
		int q = sc.nextInt();
		
		int[] t = new int[200002];
		for(int i=0; i<n; i++) {
			int l = sc.nextInt();
			int r = sc.nextInt();
			
			t[l]++;
			t[r+1]--;
		}
		
		for(int i=1; i<t.length; i++) {
			t[i] += t[i-1];
		}
		
		for(int i=0; i<t.length; i++) {
			if(t[i] >= k) {
				t[i] = 1;
			} else {
				t[i] = 0;
			}
		}
		
		for(int i=1; i<t.length; i++) {
			t[i] += t[i-1];
		}
		
		StringBuilder ans = new StringBuilder();
		for(int i=0; i<q; i++) {
			int l = sc.nextInt();
			int r = sc.nextInt();
			
			ans.append(t[r] - t[l-1]);
			ans.append("\n");
		}
		
		System.out.print(ans);
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