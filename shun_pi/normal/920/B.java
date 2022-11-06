import java.io.IOException;
import java.io.InputStream;
import java.util.ArrayDeque;
import java.util.NoSuchElementException;
 
public class Main {
	private static FastScanner sc = new FastScanner();
	
	public static void main(String[] args) {
		int T = sc.nextInt();
		for(int t=0; t<T; t++) {
			int n = sc.nextInt();
			int[] l = new int[n];
			int[] r = new int[n];
			int[] ans = new int[n];
			for(int i=0; i<n; i++) {
				l[i] = sc.nextInt();
				r[i] = sc.nextInt();
			}
			ArrayDeque<Integer> que = new ArrayDeque<>();
			int idx = 0;
			for(int s=1; s<=6000; s++) {
				while(true) {
					if(idx != n && l[idx] == s) {
						que.add(idx);
						idx++;
					} else {
						break;
					}
				}
				while(true) {
					if(!que.isEmpty()) {
						int x = que.poll();
						if(s <= r[x]) {
							ans[x] = s;
							break;
						}
					} else {
						break;
					}
				}
			}
			for(int i=0; i<n; i++) {
				System.out.print(ans[i]);
				if(i != n-1) System.out.print(" ");
			}
			System.out.println();
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