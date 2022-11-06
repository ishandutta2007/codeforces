import java.io.IOException;
import java.io.InputStream;
import java.util.NoSuchElementException;
 
public class Main {
	private static FastScanner sc = new FastScanner();
	
	public static void main(String[] args) {
		int n = sc.nextInt();
		int q = sc.nextInt();
		int c = sc.nextInt();
		
		Star[] stars = new Star[n];
		for(int i=0; i<n; i++) {
			stars[i] = new Star();
			stars[i].x = sc.nextInt();
			stars[i].y = sc.nextInt();
			stars[i].s = sc.nextInt();
		}
		
		int[][][] starmap = new int[101][101][c+1];
		for(int i=0; i<c+1; i++) {
			for(int j=0; j<n; j++) {
				starmap[stars[j].x][stars[j].y][i] += (stars[j].s + i) % (c+1);
			}
		}
		for(int i=0; i<c+1; i++) {
			for(int j=0; j<101; j++) {
				for(int k=1; k<101; k++) {
					starmap[j][k][i] += starmap[j][k-1][i];
				}
			}
		}
		
		StringBuilder ans = new StringBuilder();
		for(int i=0; i<q; i++) {
			int t = sc.nextInt();
			int x1 = sc.nextInt();
			int y1 = sc.nextInt();
			int x2 = sc.nextInt();
			int y2 = sc.nextInt();
			
			int sum = 0;
			for(int j=x1; j<=x2; j++) {
				sum += starmap[j][y2][t%(c+1)] - starmap[j][y1-1][t%(c+1)];
			}
			
			ans.append(sum);
			ans.append("\n");
		}
		
		System.out.print(ans);
	}
	
	static class Star {
		int x;
		int y;
		int s;
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