import java.io.IOException;
import java.io.InputStream;
import java.util.Arrays;
import java.util.Collections;
import java.util.NoSuchElementException;
 
public class Main {
	private static FastScanner sc = new FastScanner();
	
	public static void main(String[] args) {
		int n = sc.nextInt();
		int k = sc.nextInt();
		Flight[] f = new Flight[n];
		for(int i=0; i<n; i++) {
			f[i] = new Flight();
			f[i].id = i;
			f[i].c = sc.nextInt();
		}
		
		Arrays.sort(f, (a, b) -> b.c - a.c);
		
		Flight[] a = new Flight[n];
		int[] t = new int[n];
		int pos = 0;
		long sum = 0;
		for(int i=0; i<n; i++) {
			if(f[i].id > k) {
				if((f[i].id - k) <= pos) {
					for(; pos<n; pos++) {
						if(a[pos] == null) {
							a[pos] = f[i];
							sum += (long)(pos + k - f[i].id) * (long)f[i].c;
							t[f[i].id] = pos + k + 1;
							pos++;
							break;
						}
					}
				} else {
					int j = f[i].id - k;
					a[j] = f[i];
					sum += (j + k - f[i].id) * f[i].c;
					t[f[i].id] = j + k + 1;
				}
			} else {
				for(; pos<n; pos++) {
					if(a[pos] == null) {
						a[pos] = f[i];
						sum += (long)(pos + k - f[i].id) * (long)f[i].c;
						t[f[i].id] = pos + k + 1;
						pos++;
						break;
					}
				}
			}
		}
		
		System.out.println(sum);
		StringBuilder ans = new StringBuilder();
		for(int i=0; i<n; i++) {
			ans.append(t[i]);
			if(i != n-1) ans.append(" ");
		}
		System.out.println(ans);
	}
	
	static class Flight {
		int id;
		int c;
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