import java.io.IOException;
import java.io.InputStream;
import java.util.ArrayList;
import java.util.NoSuchElementException;
import java.util.Random;

public class Main {
    private static FastScanner sc = new FastScanner();
    private static boolean DEBUG_FLG = false;

    public static void main(String[] args) {
    	int n = sc.nextInt();
    	int m = sc.nextInt();
    	char[][] s = new char[n][m];
    	for(int i=0; i<n; i++) {
    		s[i] = sc.next().toCharArray();
    	}
    	int[][] num = new int[n][m];
    	for(int i=0; i<n; i++) {
    		for(int j=0; j<m; j++) {
    			if(j == 0 || s[i][j] != s[i][j-1]) {
    				num[i][j] = 1;
    			} else {
    				num[i][j] = num[i][j-1] + 1;
    			}
    		}
    	}
    	long ans = 0;
    	for(int j=0; j<m; j++) {
        	int last2numh = -2;
        	ArrayList<Integer> w2list = new ArrayList<>();
        	int lastnumh = -1;
        	int lastnumw = -1;
        	ArrayList<Integer> wlist = new ArrayList<>();
        	char nowchar = s[0][j];
        	int nownumh = 1;
        	int nownumw = num[0][j];
    		for(int i=1; i<n; i++) {
    			if(s[i][j] != nowchar) {
    				last2numh = lastnumh;
    				w2list = wlist;
    				lastnumh = nownumh;
    				lastnumw = nownumw;

    				wlist = new ArrayList<>();
    				wlist.add(num[i-1][j]);
    				for(int k=2; k<=nownumh; k++) {
    					if(num[i-k][j] < wlist.get(k-2)) {
    						wlist.add(num[i-k][j]);
    					} else {
    						wlist.add(wlist.get(k-2));
    					}
    				}

    				nowchar = s[i][j];
    				nownumh = 1;
    				nownumw = num[i][j];
    			} else {
    				nownumh++;
    				if(num[i][j] < nownumw) {
    					nownumw = num[i][j];
    				}
    			}
    			if(last2numh >= lastnumh && lastnumh == nownumh) {
					ans += Math.min(Math.min(w2list.get(lastnumh-1), lastnumw), nownumw);
				}
    		}
    	}
    	System.out.println(ans);
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