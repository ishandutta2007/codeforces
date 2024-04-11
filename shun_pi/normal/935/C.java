import java.io.IOException;
import java.io.InputStream;
import java.util.NoSuchElementException;
 
public class Main {
	private static FastScanner sc = new FastScanner();
	
	public static void main(String[] args) {
		double R = sc.nextDouble();
		double x1 = sc.nextDouble();
		double y1 = sc.nextDouble();
		double x2 = sc.nextDouble();
		double y2 = sc.nextDouble();
		
		if(x1 == x2 && y1 == y2) {
			System.out.println((x1+(R/2))+ " " +  y1 + " " +  (R/2));
			return;
		}
		
		double xvec = x2 - x1;
		double yvec = y2 - y1;
		if(Math.sqrt(xvec*xvec + yvec*yvec) >= R) {
			System.out.println(x1 + " " + y1 + " " + R);
			return;
		}
		double xvec2 = xvec *  R / Math.sqrt(xvec*xvec + yvec*yvec);
		double yvec2 = yvec *  R / Math.sqrt(xvec*xvec + yvec*yvec);
		double x3 = x1 - xvec2;
		double y3 = y1 - yvec2;
		double x4 = (x2 + x3) / 2;
		double y4 = (y2 + y3) / 2;
		System.out.println(x4 + " " + y4 + " " + Math.sqrt((x2-x4)*(x2-x4) + (y2-y4)*(y2-y4)));
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