import java.io.IOException;
import java.io.InputStream;
import java.util.ArrayList;
import java.util.NoSuchElementException;
 
public class Main {
	private static FastScanner sc = new FastScanner();
	
	public static void main(String[] args) {
		int n = sc.nextInt();
		int m = sc.nextInt();
		
		char[] s = sc.next().toCharArray();
		char[] t = sc.next().toCharArray();
		
		int min = 1001;
		ArrayList<Integer> set = new ArrayList<>();
		for(int i=0; i<=m-n; i++) {
			int temp = 0;
			ArrayList<Integer> tempset = new ArrayList<>();
			
			for(int j=0; j<n; j++) {
				if(s[j] != t[i+j]) {
					temp++;
					tempset.add(j+1);
				}
			}
			
			if(temp < min) {
				min = temp;
				set = tempset;
			}
		}
		
		System.out.println(min);
		for(int i=0; i<set.size(); i++) {
			System.out.print(set.get(i));
			if(i != set.size()-1) {
				System.out.print(" ");
			}
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