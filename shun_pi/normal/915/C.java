import java.io.IOException;
import java.io.InputStream;
import java.util.NoSuchElementException;
 
public class Main {
	private static FastScanner sc = new FastScanner();
	
	public static void main(String[] args) {
		char[] a = sc.next().toCharArray();
		char[] b = sc.next().toCharArray();
		int[] num = new int[10];
		for(int i=0; i<a.length; i++) {
			num[a[i] - '0']++;
		}
		char[] ans = new char[a.length];
		int i = 0;
		int j = 9;
		if(a.length < b.length) {
			while(i < a.length) {
				if(num[j] > 0) {
					ans[i] = (char)(j + '0');
					num[j]--;
					i++;
				} else {
					j--;
				}
			}
		} else {
			char[] temp = new char[a.length];
			a:
			for(int k = 0; k <= a.length; k++) {
				i = 0;
				int[] numtemp = new int[10];
				for(int t=0; t<10; t++) {
					numtemp[t] = num[t];
				}
				while(i < k) {
					if(numtemp[b[i] - '0'] > 0) {
						temp[i] = b[i];
						numtemp[b[i] - '0']--;
						i++;
					} else {
						continue a;
					}
				}
				if(i != a.length) j = b[i] - '0' - 1;
				boolean flag = false;
				while(i < a.length) {
					if(j == -1) continue a;
					if(numtemp[j] > 0) {
						temp[i] = (char)(j + '0');
						numtemp[j]--;
						i++;
						if(!flag) {
							j = 9;
							flag = true;
						}
					} else {
						j--;
					}
				}
				for(int t=0; t<a.length; t++) {
					ans[t] = temp[t];
				}
//				System.out.println(k);
//				System.out.println(ans);
			}
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