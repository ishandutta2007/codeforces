import java.io.IOException;
import java.io.InputStream;
import java.util.NoSuchElementException;
 
public class Main {
	private static FastScanner sc = new FastScanner();
	
	public static void main(String[] args) {
		int n = sc.nextInt();
		long[] y = new long[n];
		for(int i=0; i<n; i++) {
			y[i] = sc.nextInt();
		}
		
		boolean[] onceused = new boolean[n];
		for(int i=1; i<n; i++) {
//			System.out.println(i);
			if(onceused[i]) continue;
			long yd = y[i] - y[0];
			boolean[] used = new boolean[n];
			used[0] = true;
			used[i] = true;
			for(int j=i+1; j<n; j++) {
				if((yd*j)%i != 0) continue;
				if(y[0] + (yd*j)/i == y[j]) {
					used[j] = true;
					onceused[j] = true;
				}
			}
			boolean flag = false;
			boolean flag2 = true;
			long bef = 0;
			long befpos = 0;
			long ydz = Long.MAX_VALUE;
			long xdz = 0;
			for(int j=1; j<n; j++) {
				if(!used[j]) {
					if(!flag) {
						flag = true;
						bef = y[j];
						befpos = j;
					} else {
						if(ydz == Long.MAX_VALUE) {
							ydz = y[j] - bef;
							xdz = j - befpos;
							if(yd * xdz != ydz * i) {
								flag2 = false;
								break;
							}
							bef = y[j];
							befpos = j;
						} else {
							if(ydz * (j - befpos) != xdz * (y[j] - bef)) {
								flag2 = false;
								break;
							}
							bef = y[j];
							befpos = j;
						}
					}
				}
			}
			
			if(!flag || !flag2) {
				continue;
			} else {
				System.out.println("Yes");
				return;
			}
		}
		
		boolean flag = false;
		boolean flag2 = true;
		long bef = 0;
		long befpos = 0;
		long ydz = Long.MAX_VALUE;
		long xdz = 0;
		for(int j=1; j<n; j++) {
			if(!flag) {
				flag = true;
				bef = y[j];
				befpos = j;
			} else {
				if(ydz == Long.MAX_VALUE) {
					ydz = y[j] - bef;
					xdz = j - befpos;
					if((y[j] - y[0]) * xdz == ydz * j) {
						flag2 = false;
						break;
					}
					bef = y[j];
					befpos = j;
				} else {
					if(ydz * (j - befpos) != xdz * (y[j] - bef)) {
						flag2 = false;
						break;
					}
					bef = y[j];
					befpos = j;
				}
			}	
		}
		
		if(flag && flag2) {
			System.out.println("Yes");
			return;
		}
		
		System.out.println("No");
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