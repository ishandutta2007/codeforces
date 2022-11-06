import java.io.IOException;
import java.io.InputStream;
import java.util.NoSuchElementException;
 
public class Main {
	private static FastScanner sc = new FastScanner();
	
	public static void main(String[] args) {
		int n = sc.nextInt();
		int m = sc.nextInt();
		
		if(m == 0) {
			if(n == 1) {
				System.out.println(1);
				return;
			} else {
				System.out.println(-1);
				return;
			}
		}
		
		int[] k = new int[m];
		int[] f = new int[m];
		for(int i=0; i<m; i++) {
			k[i] = sc.nextInt();
			f[i] = sc.nextInt();
		}
		
		boolean flag = false;
		int ans = -1;
		a:
		for(int d=1; d<=100; d++) {
			int[] floor = new int[101];
			for(int i=1; i<101; i++) {
				floor[i] = (i-1) / d + 1;
			}
			
			for(int i=0; i<m; i++) {
//				System.out.println("d " + d + " floor[k[i]] " + floor[k[i]] + " f[i] " + f[i]);
				if(floor[k[i]] != f[i]) {
					continue a;
				}
			}
			
			if(!flag) {
				flag = true;
				ans = floor[n];
			} else {
				if(floor[n] != ans) {
					System.out.println(-1);
					return;
				}
			}
		}
		if(!flag) {
			System.out.println(-1);
		} else {
			System.out.println(ans);
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