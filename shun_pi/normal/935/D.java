import java.io.IOException;
import java.io.InputStream;
import java.util.NoSuchElementException;
 
public class Main {
	private static FastScanner sc = new FastScanner();
	private static long MOD = 1000000007;
	
	public static void main(String[] args) {
		int n = sc.nextInt();
		int m = sc.nextInt();
		int[] S1 = new int[n];
		int[] S2 = new int[n];
		for(int i=0; i<n; i++) {
			S1[i] = sc.nextInt();
		}
		for(int i=0; i<n; i++) {
			S2[i] = sc.nextInt();
		}
		long P = 0;
		long Q = 1;
		long Pt = 1;
		long Qt = 1;
		for(int i=0; i<n; i++) {
			long Pg = 0;
			long Qg = 0;
			long Pe = 0;
			long Qe = 0;
			if(S1[i] == 0 && S2[i] == 0) {
				Pg = m - 1;
				Qg = 2 * m;	
				Pe = 1;
				Qe = m;
			} else if(S1[i] == 0) {
				Pg = m - S2[i];
				Qg = m;	
				Pe = 1;
				Qe = m;
			} else if(S2[i] == 0) {
				Pg = S1[i] - 1;
				Qg = m;	
				Pe = 1;
				Qe = m;
			} else {
				if(S1[i] > S2[i]) {
					Pg = 1;
					Qg = 1;
					Pe = 0;
					Qe = 1;
				} else if(S1[i] < S2[i]) {
					Pg = 0;
					Qg = 1;
					Pe = 0;
					Qe = 1;
				} else {
					Pg = 0;
					Qg = 1;
					Pe = 1;
					Qe = 1;
				}
			}
			long Pp = (Pg * Pt) % MOD;
			long Qp = (Qg * Qt) % MOD;
			long Px = (P * Qp % MOD + Pp * Q % MOD) % MOD;
			long Qx = Q * Qp % MOD;
			P = Px;
			Q = Qx;
			Pt = (Pt * Pe) % MOD;
			Qt = (Qt * Qe) % MOD;
			if(Pt == 0) break;
		}
		System.out.println(P * pow(Q, MOD-2) % MOD);
	}
	
	static long pow(long n, long k) {
		if(k == 0) {
			return 1;
		} else if(k == 1) {
			return n;
		} else if(k%2 == 0) {
			long temp = pow(n, k/2);
			return temp * temp % MOD;
		} else {
			long temp = pow(n, k-1);
			return temp * n % MOD;
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