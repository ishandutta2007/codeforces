import java.io.*;
import java.util.*;

public class R305qCMikeAndFoam {

	@SuppressWarnings("unchecked")
	public static void main(String args[] ) throws Exception {
		   
		InputReader in = new InputReader(System.in);
	    PrintWriter w = new PrintWriter(System.out);
	    
	    int MAX = 5*100000;
	    ArrayList<Integer> primeDivisors[] = new ArrayList[MAX + 1];
	    for(int i=0;i<=MAX;i++)
	    	primeDivisors[i] = new ArrayList<Integer>();
	    
	    for(int i=2;i<=MAX;i++)
	    	if(primeDivisors[i].isEmpty())
	    		for(int j=i;j<=MAX;j+=i)
	    			primeDivisors[j].add(i);
	    
	    /*int max = 0;
	    for(ArrayList<Integer> x : primeDivisors)
	    	max = Math.max(max, x.size());
	    System.out.println(max);*/
	    
	    int n = in.nextInt();
	    int Q = in.nextInt();
	          
	    int a[] = new int[n + 1];
	    for(int i=1;i<=n;i++)
	    	a[i] = in.nextInt();
	        
	    boolean inShelf[] = new boolean[n + 1];
	    int total = 0;
	    long ans = 0;
	    int d[] = new int[MAX + 1];
	    
	    while(Q-- > 0){
	    	int x = in.nextInt();
	    	int magic = primeDivisors[a[x]].size();
	    	
	    	
	    	if(!inShelf[x]){
	    		int count = 0;
	    		
	    		for(int i=1;i<(1<<magic);i++){
	    			int val = 1,c = 0;
	    			for(int j=0;j<magic;j++){
	    				if((i & (1<<j)) != 0){
	    					c++;
	    					val *= primeDivisors[a[x]].get(j); 
	    				}
	    			}
	    			if((c & 1) == 0)	count -= d[val];
	    			else	count += d[val];
	    			d[val]++;
	    		}
	    		
	    		ans += total - count;
	    		total++;
	    		
	    		inShelf[x] = true;
	    	}
	    	
	    	else{
	    		int count = 0;
	    		
	    		for(int i=1;i<(1<<magic);i++){
	    			int val = 1,c = 0;
	    			for(int j=0;j<magic;j++){
	    				if((i & (1<<j)) != 0){
	    					c++;
	    					val *= primeDivisors[a[x]].get(j); 
	    				}
	    			}
	    			d[val]--;
	    			if((c & 1) == 0)	count -= d[val];
	    			else	count += d[val];
	    		}
	    		
	    		total--;
	    		ans -= total - count;
	    		
	    		inShelf[x] = false;
	    	}
	    	
	    	w.println(ans);
	    }
	    
	    w.close(); 
	}
	
	static public class InputReader {

		private InputStream stream;
		private byte[] buf = new byte[1024];
		private int curChar;
		private int numChars;
		private SpaceCharFilter filter;
		public InputReader(InputStream stream) {
			this.stream = stream;
		}
		
		public int snext() {
			if (numChars == -1)
				throw new InputMismatchException();
			if (curChar >= numChars) {
				curChar = 0;
				try {
					numChars = stream.read(buf);
				} catch (IOException e) {
					throw new InputMismatchException();
				}
				if (numChars <= 0)
					return -1;
			}
			return buf[curChar++];
		}

		public int nextInt() {
			int c = snext();
			while (isSpaceChar(c))
				c = snext();
			int sgn = 1;
			if (c == '-') {
				sgn = -1;
				c = snext();
			}

			int res = 0;

			do {
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res *= 10;
				res += c - '0';
				c = snext();
			} while (!isSpaceChar(c));

			return res * sgn;
		}

		public boolean isSpaceChar(int c) {
			if (filter != null)
				return filter.isSpaceChar(c);
			return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
		}

		public interface SpaceCharFilter {
			public boolean isSpaceChar(int ch);
		}
	}
	
}