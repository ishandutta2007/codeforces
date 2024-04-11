import java.io.IOException;
import java.io.InputStream;
import java.util.NoSuchElementException;

public class Main {
    private static FastScanner sc = new FastScanner();
    private static long mod = 998244353;

    public static void main(String[] args) {
    	int n = sc.nextInt();
    	int k = sc.nextInt();
    	int[] a = new int[n];
    	for(int i=0; i<n; i++) {
    		a[i] = sc.nextInt();
    	}

    	long[] x = new long[n+1];
    	long[] y = new long[n+1];
    	x[0] = 1;
    	y[0] = 1;
    	x[1] = k-1;
    	y[1] = k-2;
    	for(int i=2; i<=n; i++) {
    		x[i] = ((long)(k-1) * y[i-1]) % mod;
    		y[i] = (x[i-1] + ((long)(k-2) * y[i-1])) % mod;
    	}
    	for(int i=2; i<n; i+=2) {
    		if(a[i] == a[i-2] && a[i] != -1) {
    			System.out.println(0);
    			return;
    		}
    	}
    	for(int i=3; i<n; i+=2) {
    		if(a[i] == a[i-2] && a[i] != -1) {
    			System.out.println(0);
    			return;
    		}
    	}

    	long ans = 1;
    	int leftidx = 0;
    	int rightidx = n%2==0?n-2:n-1;
    	int minusOne = 0;
    	boolean flg = false;
    	for(int i=0; i<n; i+=2) {
    		if(a[i] == -1) {
    			minusOne++;
    		} else {
    			ans = (ans * power(k-1, minusOne)) % mod;
    			flg = true;
    			leftidx = i;
    			break;
    		}
    	}
    	if(!flg) {
    		ans = (ans * (long)k) % mod;
    		if(minusOne > 0) ans = (ans * (power(k-1, minusOne-1))) % mod;
    	} else {
    		minusOne = 0;
    		for(int i=rightidx; i>=0; i-=2) {
        		if(a[i] == -1) {
        			minusOne++;
        		} else {
        			ans = (ans * power(k-1, minusOne)) % mod;
        			flg = true;
        			rightidx = i;
        			break;
        		}
        	}
    		minusOne = 0;
    		if(leftidx != rightidx) {
    			for(int i=leftidx; i<=rightidx; i+=2) {
    	    		if(a[i] == -1) {
    	    			minusOne++;
    	    		} else {
    	    			if(a[leftidx] == a[i]) {
    	    				ans = (ans * x[minusOne]) % mod;
    	    			} else {
    	    				ans = (ans * y[minusOne]) % mod;
    	    			}
    	    			leftidx = i;
    	    			minusOne = 0;
    	    		}
    	    	}
    		}
    	}

    	if(ans == 0) {
    		System.out.println(0);
    		return;
    	}

    	leftidx = 1;
    	rightidx = n%2==0?n-1:n-2;
    	minusOne = 0;
    	flg = false;
    	for(int i=1; i<n; i+=2) {
    		if(a[i] == -1) {
    			minusOne++;
    		} else {
    			ans = (ans * power(k-1, minusOne)) % mod;
    			flg = true;
    			leftidx = i;
    			break;
    		}
    	}
    	if(!flg) {
    		ans = (ans * k) % mod;
    		if(minusOne > 0) ans = (ans * (power(k-1, minusOne-1))) % mod;
    	} else {
    		minusOne = 0;
    		for(int i=rightidx; i>=0; i-=2) {
        		if(a[i] == -1) {
        			minusOne++;
        		} else {
        			ans = (ans * power(k-1, minusOne)) % mod;
        			flg = true;
        			rightidx = i;
        			break;
        		}
        	}
    		minusOne = 0;
    		if(leftidx != rightidx) {
    			for(int i=leftidx; i<=rightidx; i+=2) {
    	    		if(a[i] == -1) {
    	    			minusOne++;
    	    		} else {
    	    			if(a[leftidx] == a[i]) {
    	    				ans = (ans * x[minusOne]) % mod;
    	    			} else {
    	    				ans = (ans * y[minusOne]) % mod;
    	    			}
    	    			leftidx = i;
    	    			minusOne = 0;
    	    		}
    	    	}
    		}
    	}
    	System.out.println(ans);
    }

    static long power(long m , long n){
    	if(n == 0) {
    		return 1;
    	}else if(n == 1){
            return m;
        }else if(n % 2 == 0){
            long s = power(m, n/2);
            return ( (s % mod) * (s % mod) ) % mod;
        }else{
            return ( (m % mod) * (power(m, n-1) % mod) ) % mod;
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