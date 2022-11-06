import java.io.IOException;
import java.io.InputStream;
import java.util.NoSuchElementException;

public class Main {
    private static FastScanner sc = new FastScanner();

    public static void main(String[] args) {
    	int n = sc.nextInt();
    	int[] cnt = new int[1001];
    	for(int i=0; i<n*n; i++) {
    		cnt[sc.nextInt()]++;
    	}

    	int[][] ans = new int[n][n];
    	int x = 0;
    	int y = 0;
    	if(n%2 == 0) {
    		for(int i=1; i<=1000; i++) {
    			if(cnt[i]%4 != 0) {
    				System.out.println("NO");
    				return;
    			} else if(cnt[i] >= 4) {
    				cnt[i] -= 4;
    				ans[x][y] = i;
    				ans[n-1-x][y] = i;
    				ans[x][n-1-y] = i;
    				ans[n-1-x][n-1-y] = i;
    				x++;
    				if(x == n / 2) {
    					x = 0;
    					y++;
    				}
    				i--;
    			}
    		}
    	} else {
    		for(int i=1; i<=1000; i++) {
    			if(cnt[i]%4 != 0) {
    				if(cnt[i]%2 == 1) {
    					if(ans[n/2][n/2] != 0) {
    						System.out.println("NO");
    						return;
    					}
    					cnt[i] -= 1;
    					ans[n/2][n/2] = i;
    					i--;
    				} else {
    					cnt[i] -= 2;
    					boolean flg = false;
    					for(int j=0; j<n/2; j++) {
    						if(ans[j][n/2] == 0) {
    							ans[j][n/2] = i;
    							ans[n-1-j][n/2] = i;
    							flg = true;
    							break;
    						} else if(ans[n/2][j] == 0) {
    							ans[n/2][j] = i;
    							ans[n/2][n-1-j] = i;
    							flg = true;
    							break;
    						}
    					}
    					if(!flg) {
            				System.out.println("NO");
            				return;
    					}
    					i--;
    				}
    			} else if(cnt[i] >= 4) {
    				if(y == n / 2) {
        				cnt[i] -= 2;
        				boolean flg = false;
    					for(int j=0; j<n/2; j++) {
    						if(ans[j][n/2] == 0) {
    							ans[j][n/2] = i;
    							ans[n-1-j][n/2] = i;
    							flg = true;
    							break;
    						} else if(ans[n/2][j] == 0) {
    							ans[n/2][j] = i;
    							ans[n/2][n-1-j] = i;
    							flg = true;
    							break;
    						}
    					}
    					if(!flg) {
            				System.out.println("NO");
            				return;
    					}
    					i--;
    				} else {
        				cnt[i] -= 4;
        				ans[x][y] = i;
        				ans[n-1-x][y] = i;
        				ans[x][n-1-y] = i;
        				ans[n-1-x][n-1-y] = i;
        				x++;
        				if(x == n / 2) {
        					x = 0;
        					y++;
        				}
        				i--;
    				}
    			}
    		}
    	}

    	System.out.println("YES");
    	for(int i=0; i<n; i++) {
    		for(int j=0; j<n; j++) {
    			if(j != 0) {
    				System.out.print(" ");
    			}
    			System.out.print(ans[i][j]);
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