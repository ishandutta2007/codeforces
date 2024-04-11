import java.io.IOException;
import java.io.InputStream;
import java.util.NoSuchElementException;
import java.util.Random;

public class Main {
    private static FastScanner sc = new FastScanner();
    private static boolean DEBUG_FLG = false;

    public static void main(String[] args) {
    	int t = sc.nextInt();
    	StringBuilder sb = new StringBuilder();
    	a:
    	for(int q=0; q<t; q++) {
    		int n = sc.nextInt();
    		int m = sc.nextInt();
    		char[][] s = new char[n][m];
    		for(int i=0; i<n; i++) {
    			s[i] = sc.next().toCharArray();
    		}
    		Snake[] snake = new Snake[26];
    		for(int k=0; k<26; k++) {
				snake[k] = new Snake();
			}

    		for(int i=0; i<n; i++) {
    			for(int j=0; j<m; j++) {
    				if(s[i][j] != '.') {
    					int num = s[i][j] - 'a';
    					if(snake[num].flg) {
    						if(snake[num].r1 != i+1) {
    							sb.append("NO\n");
    							continue a;
    						} else {
    							if(snake[num].single) {
    								sb.append("NO\n");
        							continue a;
    							}
    							snake[num].c2 = j+1;
    						}
    					} else {
    						snake[num].r1 = i+1;
    						snake[num].r2 = i+1;
    						snake[num].c1 = j+1;
    						snake[num].c2 = j+1;
    						snake[num].flg = true;
    					}
    				}
    			}

    			for(int k=0; k<26; k++) {
    				if(snake[k].flg && snake[k].c1 == snake[k].c2) {
    					snake[k].flg = false;
    					snake[k].single = true;
    				}
    			}
    			for(int k=0; k<26; k++) {
    				if(snake[k].r1 == i+1 && snake[k].flg) {
    					for(int j=snake[k].c1-1; j<=snake[k].c2-1; j++) {
    						if(s[i][j] == '.' || s[i][j] - 'a' < k) {
    							sb.append("NO\n");
    							continue a;
    						}
    					}
    				}
    			}
    		}

    		for(int k=0; k<26; k++) {
				if(snake[k].flg) {
					snake[k].comp = true;
				}
			}

    		for(int j=0; j<m; j++) {
    			for(int i=0; i<n; i++) {
    				if(s[i][j] != '.') {
    					int num = s[i][j] - 'a';
    					if(!snake[num].comp) {
    						if(snake[num].flg) {
        						if(snake[num].c1 != j+1) {
        							sb.append("NO\n");
        							continue a;
        						} else {
        							snake[num].r2 = i+1;
        						}
        					} else {
        						snake[num].r1 = i+1;
        						snake[num].r2 = i+1;
        						snake[num].c1 = j+1;
        						snake[num].c2 = j+1;
        						snake[num].flg = true;
        					}
    					}
    				}
    			}

    			for(int k=0; k<26; k++) {
    				if(!snake[k].comp && snake[k].c1 == j+1 && snake[k].flg) {
    					for(int i=snake[k].r1-1; i<=snake[k].r2-1; i++) {
    						if(s[i][j] == '.' || s[i][j] - 'a' < k) {
    							sb.append("NO\n");
    							continue a;
    						}
    					}
    				}
    			}
    		}

    		int num = 0;
    		for(int k=25; k>=0; k--) {
    			if(k != 25 && !snake[k].flg && snake[k+1].flg) {
    				snake[k].r1 = snake[k+1].r1;
    				snake[k].r2 = snake[k+1].r2;
    				snake[k].c1 = snake[k+1].c1;
    				snake[k].c2 = snake[k+1].c2;
    				snake[k].flg = true;
    			}
    			if(snake[k].flg && k+1 > num) {
    				num = k+1;
    			}
    		}
    		sb.append("YES\n");
    		sb.append(num + "\n");
    		for(int k=0; k<num; k++) {
				sb.append(snake[k].r1 + " " + snake[k].c1 + " " + snake[k].r2 + " " + snake[k].c2 + "\n");
			}
    	}
    	System.out.print(sb);
    }

    static class Snake {
    	int r1 = -1;
    	int r2;
    	int c1;
    	int c2;
    	boolean flg = false;
    	boolean comp = false;
    	boolean single = false;
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

    static void shuffleArray(long[] arr){
        int n = arr.length;
        Random rnd = new Random();
        for(int i=0; i<n; ++i){
            long tmp = arr[i];
            int randomPos = i + rnd.nextInt(n-i);
            arr[i] = arr[randomPos];
            arr[randomPos] = tmp;
        }
    }
}