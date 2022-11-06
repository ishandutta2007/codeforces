import java.io.IOException;
import java.io.InputStream;
import java.util.ArrayDeque;
import java.util.HashSet;
import java.util.NoSuchElementException;

public class Main implements Runnable{
    private static FastScanner sc = new FastScanner();
    static Node[] V;
    static ArrayDeque<Stack> stk = new ArrayDeque<>();

    public static void main(String[] args) {
        new Thread(null, new Main(), "", 16 * 1024 * 1024).start(); //16MB
    }

    public void run() {
    	int n = sc.nextInt();
    	V = new Node[n];
    	for(int i=0; i<n; i++) {
    		V[i] = new Node();
    		V[i].minmax = sc.nextInt();
    	}
    	for(int i=1; i<n; i++) {
    		int p = sc.nextInt() - 1;
    		V[i].parent = p;
    		V[p].child.add(i);
    	}
    	int ret = V[0].dfs();
    	int k = 0;
    	for(int i=0; i<n; i++) {
    		if(V[i].child.size() == 0) {
    			k++;
    		}
    	}
    	System.out.println(k - ret + 1);
    }

    static class Node {
        HashSet<Integer> child = new HashSet<>();
        int parent;
        int minmax;
        int discard;
        int dfs() {
    		this.discard = 0;
        	if(child.size() == 0) {
        		return 1;
        	}
        	if(minmax == 0) {
        		for(int x : child) {
            		int ret = V[x].dfs();
            		this.discard += ret;
            	}
        		this.discard -= 1;
        		return this.discard + 1;
        	} else {
        		int min = Integer.MAX_VALUE;
        		for(int x : child) {
            		int ret = V[x].dfs();
            		if(ret < min) {
            			min = ret;
            		}
            	}
        		this.discard = min;
        		return this.discard;
        	}
        }
    }

    static class Stack {
    	int idx;
		Stack(int idx) {
			this.idx = idx;
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