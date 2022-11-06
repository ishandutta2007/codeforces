import java.io.IOException;
import java.io.InputStream;
import java.util.NoSuchElementException;

public class Main {
	static FastScanner sc = new FastScanner();

	public static void main(String[] args) {
		int n = sc.nextInt();
		int m = sc.nextInt();
		boolean[][] bd = new boolean[n][m];
		for(int i=0; i<n; i++) {
			char[] temp = sc.next().toCharArray();
			for(int j=0; j<m; j++) {			
				bd[i][j] = temp[j+1] == '1' ? true : false;
			}
		}
		
		int min_empty_idx = 0;
		for(int i=0; i<n; i++) {
			boolean flag = false;
			for(int j=0; j<m; j++) {
				if(bd[i][j]) {
					flag = true;
					break;
				}
			}
			if(flag) {
				break;
			}
			min_empty_idx++;
		}
		
		if(min_empty_idx == n) {
			System.out.println(0);
			return;
		}
		
		//leftstairs:false rightstairs:true
		int min = Integer.MAX_VALUE;
		for(int k=0; k<(1<<n); k++) {
			boolean lorr = false;
			int cnt = 0;
			
			for(int i=n-1; i>=0; i--) {
				int j;	
				boolean flag = false;
				if(!lorr) {			
					for(j=m-1; j>=0; j--) {
						if(bd[i][j]) {
							flag = true;
							break;
						}
					}
					if(flag) {
						cnt += j + 1;
					} else {
						if(i == min_empty_idx) {
							break;
						} else {
							cnt++;
							continue;
						}
					}
					
				} else {
					for(j=0; j<m; j++) {
						if(bd[i][j]) {
							flag = true;
							break;
						}
					}
					if(flag) {
						cnt += m - j;
					} else {
						if(i == min_empty_idx) {
							break;
						} else {
							cnt++;
							continue;
						}
					}
				}
				
				if(i == min_empty_idx) {
					break;
				}
				
				if((k>>i)%2 == 0) {
					cnt += j + 1;
					lorr = false;
				} else {
					cnt += m - j;
					lorr = true;
				}
				
				
				
				cnt++;
			}
			
			if(cnt < min) {
				min = cnt;
			}
		}
		
		
		System.out.println(min);
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