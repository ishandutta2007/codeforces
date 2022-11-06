import java.io.IOException;
import java.io.InputStream;
import java.util.Arrays;
import java.util.HashSet;
import java.util.NoSuchElementException;
import java.util.Random;

public class Main {
    private static FastScanner sc = new FastScanner();
    private static boolean DEBUG_FLG = false;

    public static void main(String[] args) {
    	int n = sc.nextInt();
    	int[] b = new int[n];
    	int[] btmp = new int[n];
    	for(int i=0; i<n; i++) {
    		b[i] = sc.nextInt();
    		btmp[i] = b[i];
    	}
    	shuffleArray(b);
    	Arrays.sort(b);
    	int[] d = new int[n-1];
    	HashSet<Integer> set = new HashSet<>();
    	for(int i=0; i<n-1; i++) {
    		d[i] = b[i+1] - b[i];
    		set.add(d[i]);
    	}
    	if(set.size() >= 4) {
    		System.out.println(-1);
    	} else if(set.size() == 1) {
    		for(int i=0; i<n; i++) {
				if(b[0] == btmp[i]) {
					System.out.println(i+1);
    				return;
				}
			}
    	} else {
    		a:
    		for(int c : set) {
    			int mode = 0;
    			int tmp = 0;
    			int num = Integer.MAX_VALUE;
    			if(d[0] != c) {
    				boolean flg = true;
    				for(int i=1; i<n-1; i++) {
        				if(d[i] != c) {
        					flg = false;
        					break;
        				}
        			}
    				if(flg) {
    					for(int i=0; i<n; i++) {
    						if(b[0] == btmp[i]) {
    							System.out.println(i+1);
    		    				return;
    						}
    					}
    				}
    			}
    			if(d[n-2] != c) {
    				boolean flg = true;
    				for(int i=0; i<n-2; i++) {
        				if(d[i] != c) {
        					flg = false;
        					break;
        				}
        			}
    				if(flg) {
    					for(int i=0; i<n; i++) {
    						if(b[n-1] == btmp[i]) {
    							System.out.println(i+1);
    		    				return;
    						}
    					}
    				}
    			}

    			for(int i=0; i<n-1; i++) {
    				if(mode == 0) {
    					if(d[i] != c) {
    						tmp = d[i];
        	    			mode = 1;
        	    		}
    				} else if(mode == 1) {
    					if(d[i] + tmp != c) {
    						continue a;
    					}
    					num = b[i];
    					mode = 2;
    				} else {
    					if(d[i] != c) {
    						continue a;
        	    		}
    				}
    	    	}
    			if(num != Integer.MAX_VALUE) {
    				for(int i=0; i<n; i++) {
    					if(num == btmp[i]) {
    						System.out.println(i+1);
    	    				return;
    					}
    				}
    			}
    		}
    		System.out.println(-1);
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

    static void shuffleArray(int[] arr){
        int n = arr.length;
        Random rnd = new Random();
        for(int i=0; i<n; ++i){
        	int tmp = arr[i];
            int randomPos = i + rnd.nextInt(n-i);
            arr[i] = arr[randomPos];
            arr[randomPos] = tmp;
        }
    }
}