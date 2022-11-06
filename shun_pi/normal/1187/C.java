import java.io.IOException;
import java.io.InputStream;
import java.util.Arrays;
import java.util.NoSuchElementException;
import java.util.Random;

public class Main {
    private static FastScanner sc = new FastScanner();
    private static boolean DEBUG_FLG = false;

    public static void main(String[] args) {
    	int n = sc.nextInt();
    	int m = sc.nextInt();
    	boolean[] nextDec = new boolean[n-1];
    	for(int i=0; i<n-1; i++) {
    		nextDec[i] = true;
    	}
    	Fact[] f = new Fact[m];
    	for(int i=0; i<m; i++) {
    		f[i] = new Fact(sc.nextInt(), sc.nextInt()-1, sc.nextInt()-1);
    	}
    	shuffleArray(f);
    	Arrays.sort(f, (a,b) -> b.t - a.t);
    	a:
    	for(int i=0; i<m; i++) {
    		if(f[i].t == 1) {
    			for(int j=f[i].l; j<f[i].r; j++) {
    				nextDec[j] = false;
    			}
    		} else {
    			for(int j=f[i].l; j<f[i].r; j++) {
    				if(nextDec[j]) {
    					continue a;
    				}
    			}
    			System.out.println("NO");
    			return;
    		}
    	}
    	int[] ans = new int[n];
    	ans[0] = 1000;
    	for(int i=0; i<n-1; i++) {
    		if(nextDec[i]) {
    			ans[i+1] = ans[i] - 1;
    		} else {
    			ans[i+1] = ans[i];
    		}
    	}
    	System.out.println("YES");
    	for(int i=0; i<n; i++) {
    		if(i != 0) System.out.print(" ");
    		System.out.print(ans[i]);
    	}
    	System.out.println();

    }

    static class Fact {
    	int t;
    	int l;
    	int r;
		public Fact(int t, int l, int r) {
			this.t = t;
			this.l = l;
			this.r = r;
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

    static void shuffleArray(Fact[] arr){
        int n = arr.length;
        Random rnd = new Random();
        for(int i=0; i<n; ++i){
        	Fact tmp = arr[i];
            int randomPos = i + rnd.nextInt(n-i);
            arr[i] = arr[randomPos];
            arr[randomPos] = tmp;
        }
    }
}