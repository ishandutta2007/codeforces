import java.io.IOException;
import java.io.InputStream;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.NoSuchElementException;

public class Main {
    private static FastScanner sc = new FastScanner();
    static Node[] V;
    static long clusterSize = 0;
    private static long mod = 1000000007;

    public static void main(String[] args) {
    	int n = sc.nextInt();
    	int k = sc.nextInt();
    	V = new Node[n];
    	for(int i=0; i<n; i++) {
    		V[i] = new Node();
    	}
    	for(int i=0; i<n-1; i++) {
    		int a = sc.nextInt() - 1;
    		int b = sc.nextInt() - 1;
    		int x = sc.nextInt();
    		if(x == 1) continue;
    		V[a].nbr.add(b);
    		V[b].nbr.add(a);
    	}
    	ArrayList<Long> redCluster = new ArrayList<>();
    	for(int i=0; i<n; i++) {
    		if(!V[i].vst) {
    			clusterSize = 0;
    			V[i].dfs();
    			redCluster.add(clusterSize);
    		}
    	}
    	long ans = power(n, k);
    	for(long x : redCluster) {
    		ans = (ans - power(x, k) + mod) % mod;
    	}
    	System.out.println(ans);
    }

    static class Node {
        HashSet<Integer> nbr = new HashSet<>();
        boolean vst = false;
        void dfs() {
        	vst = true;
        	clusterSize++;
        	for(int x : nbr) {
        		if(!V[x].vst) V[x].dfs();
        	}
        }
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