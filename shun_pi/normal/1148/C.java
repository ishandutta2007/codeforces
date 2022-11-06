import java.io.IOException;
import java.io.InputStream;
import java.util.NoSuchElementException;

public class Main {
    private static FastScanner sc = new FastScanner();
    private static boolean DEBUG_FLG = false;
    static int[] p;
    static int[] id;
    static int swapnum = 0;

    public static void main(String[] args) {
    	int n = sc.nextInt();
    	p = new int[n+1];
    	id = new int[n+1];
    	for(int i=1; i<=n; i++) {
    		p[i] = sc.nextInt();
    		id[p[i]] = i;
    	}
    	StringBuilder sb = new StringBuilder();
    	for(int i=1; i<=n/2; i++) {
    		int idx = n/2 + 1 - i;
    		if(id[idx] < idx) {
    			sb.append(id[idx] + " " + n + "\n");
    			swap(p[id[idx]], p[n]);
    			sb.append(idx + " " + n + "\n");
    			swap(p[idx], p[n]);
    		} else if(id[idx] > idx) {
    			if(id[idx] - idx >= n/2) {
    				sb.append(id[idx] + " " + idx + "\n");
        			swap(p[idx], p[id[idx]]);
    			} else {
    				sb.append(1 + " " + id[idx] + "\n");
        			swap(p[id[idx]], p[1]);
        			sb.append(1 + " " + n + "\n");
        			swap(p[1], p[n]);
        			sb.append(idx + " " + n + "\n");
        			swap(p[idx], p[n]);
    			}
    		}

    		idx += i*2 - 1;
    		if(id[idx] > idx) {
    			sb.append(id[idx] + " " + 1 + "\n");
    			swap(p[id[idx]], p[1]);
    			sb.append(idx + " " + 1 + "\n");
    			swap(p[idx], p[1]);
    		} else if(id[idx] < idx) {
    			if(idx - id[idx] >= n/2) {
    				sb.append(id[idx] + " " + idx + "\n");
        			swap(p[idx], p[id[idx]]);
    			} else {
    				sb.append(n + " " + id[idx] + "\n");
        			swap(p[id[idx]], p[n]);
        			sb.append(1 + " " + n + "\n");
        			swap(p[1], p[n]);
        			sb.append(idx + " " + 1 + "\n");
        			swap(p[idx], p[1]);
    			}
    		}
    	}
    	System.out.println(swapnum);
    	System.out.print(sb);
    }

    static void swap(int x1, int x2) {
    	p[id[x1]] = x2;
		p[id[x2]] = x1;
		int tmp = id[x1];
		id[x1] = id[x2];
		id[x2] = tmp;
		swapnum++;
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
}