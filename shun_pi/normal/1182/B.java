import java.io.IOException;
import java.io.InputStream;
import java.util.NoSuchElementException;
import java.util.Random;

public class Main {
    private static FastScanner sc = new FastScanner();
    private static boolean DEBUG_FLG = false;

    public static void main(String[] args) {
    	int h = sc.nextInt();
    	int w = sc.nextInt();
    	boolean[][] p = new boolean[h][w];
    	int[] tate = new int[w];
    	int[] yoko = new int[h];
    	for(int i=0; i<h; i++) {
    		char[] s = sc.next().toCharArray();
    		for(int j=0; j<w; j++) {
    			if(s[j] == '*') {
    				p[i][j] = true;
    				tate[j]++;
    				yoko[i]++;
    			}
    		}
    	}
    	int px = -1;
    	int py = -1;
    	for(int i=0; i<h; i++) {
    		if(yoko[i] > 1) {
    			if(px != -1) {
    				System.out.println("NO");
    				return;
    			}
    			px = i;
    		}
    	}
    	for(int i=0; i<w; i++) {
    		if(tate[i] > 1) {
    			if(py != -1) {
    				System.out.println("NO");
    				return;
    			}
    			py = i;
    		}
    	}

    	if(px == -1 || py == -1) {
    		System.out.println("NO");
    		return;
    	}

    	if(!p[px][py]) {
    		System.out.println("NO");
    		return;
    	}
    	p[px][py] = false;

    	int tmppx = px-1;
    	boolean flg = false;
    	while(tmppx >= 0 && tmppx < h) {
    		if(p[tmppx][py]) {
    			p[tmppx][py] = false;
    			tmppx--;
    			flg = true;
    		} else {
    			break;
    		}
    	}
    	if(!flg) {
    		System.out.println("NO");
    		return;
    	}
    	flg = false;
    	tmppx = px+1;
    	while(tmppx >= 0 && tmppx < h) {
    		if(p[tmppx][py]) {
    			p[tmppx][py] = false;
    			tmppx++;
    			flg = true;
    		} else {
    			break;
    		}
    	}
    	if(!flg) {
    		System.out.println("NO");
    		return;
    	}
    	flg = false;
    	int tmppy = py-1;
    	while(tmppy >= 0 && tmppy < w) {
    		if(p[px][tmppy]) {
    			p[px][tmppy] = false;
    			tmppy--;
    			flg = true;
    		} else {
    			break;
    		}
    	}
    	if(!flg) {
    		System.out.println("NO");
    		return;
    	}
    	flg = false;
    	tmppy = py+1;
    	while(tmppy >= 0 && tmppy < w) {
    		if(p[px][tmppy]) {
    			p[px][tmppy] = false;
    			tmppy++;
    			flg = true;
    		} else {
    			break;
    		}
    	}
    	if(!flg) {
    		System.out.println("NO");
    		return;
    	}
    	for(int i=0; i<h; i++) {
    		for(int j=0; j<w; j++) {
    			if(p[i][j]) {
    				System.out.println("NO");
    				return;
    			}
    		}
    	}
    	System.out.println("YES");
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