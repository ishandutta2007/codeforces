import java.io.IOException;
import java.io.InputStream;
import java.util.Arrays;
import java.util.NoSuchElementException;

public class Main {
    private static FastScanner sc = new FastScanner();

    public static void main(String[] args) {
    	int n = sc.nextInt();
    	int m = sc.nextInt();
    	int[][] a = new int[n][m];
    	for(int i=0; i<n; i++) {
    		for(int j=0; j<m; j++) {
    			a[i][j] = sc.nextInt();
    		}
    	}
    	int[][] xl = new int[n][m];
    	int[][] xh = new int[n][m];
    	for(int i=0; i<n; i++) {
    		Pair[] p = new Pair[m];
    		for(int j=0; j<m; j++) {
    			p[j] = new Pair(j, a[i][j]);
    		}
    		Arrays.sort(p, (a1, b1) -> a1.value - b1.value);
    		int tmp = -1;
    		for(int j=0; j<m; j++) {
    			if(!(j != 0 && p[j].value == p[j-1].value)) tmp++;
    			xl[i][p[j].idx] = tmp;
    		}
    		tmp = -1;
    		for(int j=m-1; j>=0; j--) {
    			if(!(j != m-1 && p[j].value == p[j+1].value)) tmp++;
    			xh[i][p[j].idx] = tmp;
    		}
    	}
    	int[][] yl = new int[n][m];
    	int[][] yh = new int[n][m];
    	for(int j=0; j<m; j++) {
    		Pair[] p = new Pair[n];
    		for(int i=0; i<n; i++) {
    			p[i] = new Pair(i, a[i][j]);
    		}
    		Arrays.sort(p, (a1, b1) -> a1.value - b1.value);
    		int tmp = -1;
    		for(int i=0; i<n; i++) {
    			if(!(i != 0 && p[i].value == p[i-1].value)) tmp++;
    			yl[p[i].idx][j] = tmp;
    		}
    		tmp = -1;
    		for(int i=n-1; i>=0; i--) {
    			if(!(i != n-1 && p[i].value == p[i+1].value)) tmp++;
    			yh[p[i].idx][j] = tmp;
    		}
    	}
    	StringBuilder sb = new StringBuilder();
    	for(int i=0; i<n; i++) {
    		for(int j=0; j<m; j++) {
    			if(j != 0) sb.append(" ");
    			//System.out.println(i + " " + j + " " + xl[i][j] + " " + yl[i][j] + " " + xh[i][j] + " " + yh[i][j]);
    			sb.append(Math.max(xl[i][j], yl[i][j])+1+Math.max(xh[i][j], yh[i][j]));
    		}
    		sb.append("\n");
    	}
    	System.out.print(sb);
    }

    static class Pair {
    	int idx;
    	int value;
    	Pair(int idx, int value) {
    		this.idx = idx;
    		this.value = value;
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