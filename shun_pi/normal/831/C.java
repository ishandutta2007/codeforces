import java.io.IOException;
import java.io.InputStream;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.NoSuchElementException;
 
public class Main {
	private static FastScanner sc = new FastScanner();
	
	public static void main(String[] args) {
		int k = sc.nextInt();
		int n = sc.nextInt();
		
		ArrayList<Integer> a = new ArrayList<>();
		int bef = 0;
		for(int i=0; i<k; i++) {
			int x = sc.nextInt();
			if(x != 0) {
				a.add(x + bef);
				bef += x;
			}
		}
		
		Collections.sort(a);
		
		int[] b = new int[n];
		for(int i=0; i<n; i++) {
			b[i] = sc.nextInt();
		}
		
		Arrays.sort(b);
		
		int ans = 0;
		for(int i=0; i<a.size(); i++) {
			int l = 1;
			for(int j=i; j<a.size(); j++) {
				if(l < n && b[0] - a.get(i) + a.get(j) == b[l]) {
					l++;
				}
			}

			if(l == n) {
				ans++;
			}
		}
		
		if(a.size() == 0) {
			ans = 1;
		}
		
		System.out.println(ans);
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