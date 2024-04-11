import java.io.IOException;
import java.io.InputStream;
import java.util.NoSuchElementException;
 
public class Main {
	private static FastScanner sc = new FastScanner();
	
	public static void main(String[] args) {
		int n = sc.nextInt();
		int k = sc.nextInt();
		char[] str = sc.next().toCharArray();
		
		int[] open = new int[n+1];
		
		boolean[] checked = new boolean[26];
		int cnt = 0;
		for(int i=0; i<n; i++) {
			if(!checked[str[i] - 'A']) {
				checked[str[i] - 'A'] = true;
				open[i]++;
				cnt++;
			}
			if(cnt == 26) break;
		}
		
		checked = new boolean[26];
		cnt = 0;
		for(int i=n-1; i>=0; i--) {
			if(!checked[str[i] - 'A']) {
				checked[str[i] - 'A'] = true;
				open[i+1]--;
				cnt++;
			}
			if(cnt == 26) break;
		}

//		System.out.println(open[0]);
		for(int i=1; i<n; i++) {
			open[i] += open[i-1];
//			System.out.println(open[i]);
		}
		
		for(int i=0; i<n; i++) {
			if(open[i] > k) {
				System.out.println("YES");
				return;
			}
		}
		
		System.out.println("NO");

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