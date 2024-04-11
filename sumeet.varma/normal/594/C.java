import java.io.*;
import java.util.*;

public class R330qC {

	static TreeMap<Pair,Integer> x,y;
	
	public static void main(String args[]) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);
		
		int n = in.nextInt();
		int k = in.nextInt();
		
		x = new TreeMap<Pair,Integer>();
		y = new TreeMap<Pair,Integer>();
		
		for(int i=1;i<=n;i++){
			int x1 = in.nextInt();
			int y1 = in.nextInt();
			int x2 = in.nextInt();
			int y2 = in.nextInt();
			add(new Pair((x1 + x2) / 2.0,(y1 + y2) / 2.0));
		}
		
		//System.out.println(x.size() + " " + x);
		//System.out.println(y.size() + " " + y);
		long ans = Long.MAX_VALUE;
		
		for(int i=0;i<=k;i++){
			
			Pair pI[] = new Pair[i + 1];
			for(int z=1;z<=i;z++){
				pI[z] = x.firstKey();
				remove(pI[z]);
			}
			
			for(int j=0;j<=k-i;j++){
				
				Pair pJ[] = new Pair[j + 1];
				for(int z=1;z<=j;z++){
					pJ[z] = x.lastKey();
					remove(pJ[z]);
				}
				
				for(int l=0;l<=k-(i+j);l++){
	
					Pair pL[] = new Pair[l + 1];
					for(int z=1;z<=l;z++){
						pL[z] = t(y.firstKey());
						remove(pL[z]);
					}
					
					for(int m=0;m<=k-(i+j+l);m++){

						Pair pM[] = new Pair[m + 1];
						for(int z=1;z<=m;z++){
							pM[z] = t(y.lastKey());
							remove(pM[z]);
						}
						
						
						double x1 = x.firstKey().x;
						double x2 = x.lastKey().x;
						double y1 = y.firstKey().x;
						double y2 = y.lastKey().x;
						
						long len = (long)Math.ceil(x2 - x1 - 0.1);
						if(len == 0)	len = 1;
						long wid = (long)Math.ceil(y2 - y1 - 0.1);
						if(wid == 0)	wid = 1;
						
						ans = Math.min(ans,len * wid);
						
						add(pM);
					}
					
					add(pL);
				}
				
				add(pJ);
			}
			
			add(pI);
		}
		
		w.println(ans);
		w.close();
	}
	
	static Pair t(Pair a){
		return new Pair(a.y,a.x);
	}
	
	static void add(Pair P[]){
		for(int i=1;i<P.length;i++)
			add(P[i]);
	}
	
	static void remove(Pair P[]){
		//System.out.println(Arrays.deepToString(P));
		for(int i=1;i<P.length;i++)
			remove(P[i]);
	}
	
	static void addX(Pair p){
		if(x.containsKey(p))
			x.put(p, x.get(p) + 1);
		else
			x.put(p, 1);
	}
	
	static void addY(Pair p){
		if(y.containsKey(p))
			y.put(p, y.get(p) + 1);
		else
			y.put(p, 1);

	}
	
	static void add(Pair p){
		addX(p);
		addY(t(p));
	}
	
	static void removeX(Pair p){
		int freq = x.get(p);
		if(freq == 1)
			x.remove(p);
		else
			x.put(p, freq - 1);
	}
	
	static void removeY(Pair p){
		int freq = y.get(p);
		if(freq == 1)
			y.remove(p);
		else
			y.put(p, freq - 1);
	}
	
	static void remove(Pair p){
		removeX(p);
		removeY(t(p));
	}
	
	static class Pair implements Comparable<Pair>{
		double x,y;
		Pair(double x,double y){
			this.x = x;
			this.y = y;
		}
		public int compareTo(Pair o){
			if(x != o.x)
				return Double.compare(x, o.x);
			return Double.compare(y, o.y);
		}
		public String toString(){
			return x + " " + y;
		}
	}
	
	static class InputReader {

		private InputStream stream;
		private byte[] buf = new byte[8192];
		private int curChar;
		private int snumChars;
		private SpaceCharFilter filter;

		public InputReader(InputStream stream) {
			this.stream = stream;
		}

		public int snext() {
			if (snumChars == -1)
				throw new InputMismatchException();
			if (curChar >= snumChars) {
				curChar = 0;
				try {
					snumChars = stream.read(buf);
				} catch (IOException e) {
					throw new InputMismatchException();
				}
				if (snumChars <= 0)
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
		
		public long nextLong() {
			int c = snext();
			while (isSpaceChar(c))
				c = snext();
			int sgn = 1;
			if (c == '-') {
				sgn = -1;
				c = snext();
			}

			long res = 0;

			do {
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res *= 10;
				res += c - '0';
				c = snext();
			} while (!isSpaceChar(c));

			return res * sgn;
		}
		
		public String readString() {
			int c = snext();
			while (isSpaceChar(c))
				c = snext();
			StringBuilder res = new StringBuilder();
			do {
				res.appendCodePoint(c);
				c = snext();
			} while (!isSpaceChar(c));
			return res.toString();
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