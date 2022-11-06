import java.io.IOException;
import java.io.InputStream;
import java.util.ArrayList;
import java.util.NoSuchElementException;
 
public class Main {
	private static FastScanner sc = new FastScanner();
	
	public static void main(String[] args) {
		int Q = sc.nextInt();
		ArrayList<Long> S = new ArrayList<>();
		StringBuilder sb = new  StringBuilder();
		long lowersum = 0;
		int lowern = 0;
		long max = 0;
		for(int q=0; q<Q; q++) {
			int type = sc.nextInt();
			if(type == 1) {
				max = sc.nextLong();
				S.add(max);
				for(int i=lowern; i<S.size()-1; i++) {
					if(S.get(i) * (lowern + 1) >= (max + lowersum)) break;
					lowersum += S.get(i);
					lowern++;
				}
			} else {
				double mean = (double)(max + lowersum) / (double)(lowern + 1);
				sb.append((double)max - mean);
				sb.append("\n");
			}
		}
		System.out.print(sb);
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