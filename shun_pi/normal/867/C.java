import java.io.IOException;
import java.io.InputStream;
import java.util.Arrays;
import java.util.Collections;
import java.util.NoSuchElementException;
 
public class Main {
	private static FastScanner sc = new FastScanner();
	
	public static void main(String[] args) {
		int N = sc.nextInt();
		int S = sc.nextInt();
		Contestant[] ct = new Contestant[N];
		for(int i=0; i<N; i++) {
			ct[i] = new Contestant();
			ct[i].s = sc.nextInt();
			ct[i].a = sc.nextInt();
			ct[i].b = sc.nextInt();
		}
		Arrays.sort(ct, (x, y) -> (y.a - y.b) - (x.a - x.b));
		long hap = 0;
		long suma = 0;
		long sumb = 0;
		long sumeq = 0;
		boolean flag = false;
		int pos = N;
		for(int i=0; i<N; i++) {
			if(ct[i].a - ct[i].b > 0) {
				suma += (long)ct[i].s;
				hap += (long)ct[i].a * ct[i].s;
			} else if(ct[i].a - ct[i].b < 0) {
				if(!flag) {
					pos = i;
					flag = true;
				}
				sumb += (long)ct[i].s;
				hap += (long)ct[i].b * ct[i].s;
			} else {
				sumeq += (long)ct[i].s;
				hap += (long)ct[i].a * ct[i].s;
			}
		}
		
//		System.out.println(suma + " " + sumb + " " + sumeq);
		
		if(suma == 0 || sumb == 0 || ((suma - 1) / S) + 1 + ((sumb - 1) / S) + 1 <= (suma + sumb + sumeq - 1) / S + 1) {
			System.out.println(hap);
			return;
		}
		long rest = suma - ((suma - 1) / S) * S;
		long dec1 = 0;
		flag = false;
		for(int i=pos-1; i>=0; i--) {
			if(ct[i].a - ct[i].b <= 0) continue;
			if(ct[i].s >= rest) {
				dec1 += rest * ((long)ct[i].a - ct[i].b);
				flag = true;
				break;
			} else {
				dec1 += (long)ct[i].s * ((long)ct[i].a - ct[i].b);
				rest -= (long)ct[i].s;
			}
		}
		if(!flag) dec1 = -1;
		
		rest = sumb - ((sumb - 1) / S) * S;
		long dec2 = 0;
		flag = false;
		for(int i=pos; i<N; i++) {
			if(ct[i].s >= rest) {
				dec2 += rest * ((long)ct[i].b - ct[i].a);
				flag = true;
				break;
			} else {
				dec2 += (long)ct[i].s * ((long)ct[i].b - ct[i].a);
				rest -= (long)ct[i].s;
			}
		}
		if(!flag) dec2 = -1;
		
		if(dec1 == -1) {
			System.out.println(hap - dec2);
		} else if(dec2 == -1) {
			System.out.println(hap - dec1);
		} else {
			System.out.println(Math.max(hap - dec1, hap - dec2));
		}
	}
	
	static class Contestant {
		int s;
		int a;
		int b;
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