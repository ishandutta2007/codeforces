import java.io.IOException;
import java.io.InputStream;
import java.util.ArrayList;
import java.util.NoSuchElementException;
 
public class Main {
	private static FastScanner sc = new FastScanner();
	
	public static void main(String[] args) {
		int n = sc.nextInt();
		if(n >= 12) {
			System.out.println("0");
			return;
		}
		
		int[][] a = new int[n][5];
		for(int i=0; i<n; i++) {
			for(int j=0; j<5; j++) {
				a[i][j] = sc.nextInt();
			}
		}
		
		ArrayList<Integer> ans = new ArrayList<>();
		for(int i=0; i<n; i++) {
			boolean flag = true;
			loop:
			for(int j=0; j<n; j++) {
				for(int k=0; k<n; k++) {
					if(i == j || j == k || k == i) continue;
					int sum = 0;
					for(int l=0; l<5; l++) {
						sum += (a[j][l] - a[i][l]) * (a[k][l] - a[i][l]);
					}
					if(sum > 0) {
						flag = false;
						break loop;
					}
				}
			}
			
			if(flag) {
				ans.add(i + 1);
			}
		}
		
		System.out.println(ans.size());
		for(int i=0; i<ans.size(); i++) {
			System.out.println(ans.get(i));
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