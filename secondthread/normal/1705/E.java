import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Random;
import java.util.StringTokenizer;
/*



0010110111101011
+      1
0010110111101011
       00001
       

0010110111101011
-        1
         0
         
         
00101101111000001011
-            1
00101101111000001011
             1110
             
(range sum, and a traversal)
first 1 to somethings right
first 0 to somethings right
range set to 1
range set to 0



 */
public class E {

	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		PrintWriter out=new PrintWriter(System.out);
		ST st=new ST(0, 3_00_000);
		int n=fs.nextInt(), q=fs.nextInt();
		int[] a=fs.readArray(n);
		for (int i:a) add(i, st);
		for (int qq=0; qq<q; qq++) {
			int index=fs.nextInt()-1, value=fs.nextInt();
			sub(a[index], st);
			a[index]=value;
			add(a[index], st);
			out.println(st.rightmost1());
		}
		out.close();
	}
	
	static void add(int x, ST st) {
		int nextZero=st.indexOfFirst0(x);
		st.rangeSet(x, nextZero, 0);
		st.rangeSet(nextZero, nextZero, 1);
	}
	static void sub(int x, ST st) {
		int nextOne=st.indexOfFirst1(x);
		st.rangeSet(x, nextOne, 1);
		st.rangeSet(nextOne, nextOne, 0);
	}
	
	static class ST {
		int leftmost, rightmost;
		int toProp=-1;
		int count=0;
		ST lChild, rChild;
		
		public ST(int l, int r) {
			leftmost=l;
			rightmost=r;
			if (l!=r) {
				int mid=(l+r)>>1;
				lChild=new ST(l, mid);
				rChild=new ST(mid+1, r);
			}
		}
		
		void recalc() {
			if (leftmost==rightmost) {
				return;
			}
			count=lChild.count()+rChild.count();
		}
		
		void prop() {
			if (toProp==-1) return;
			lChild.rangeSet(leftmost, rightmost, toProp);
			rChild.rangeSet(leftmost, rightmost, toProp);
			toProp=-1;
			recalc();
		}
		
		void rangeSet(int l, int r, int to) {
			if (l<=leftmost && r>=rightmost) {
				toProp=to;
				return;
			}
			if (l>rightmost || r<leftmost) return;
			prop();
			lChild.rangeSet(l, r, to);
			rChild.rangeSet(l, r, to);
			recalc();
		}
		
		int count() {
			if (toProp==-1) return count;
			if (toProp==0) return 0;
			if (toProp==1) return rightmost-leftmost+1;
			throw null;
		}
		
		//returns -1 if not there
		int indexOfFirst0(int leftBound) {
			if (leftmost==rightmost) {
				if (count()==0) {
					return leftmost;
				}
				else {
					return -1;
				}
			}
			prop();
			if (leftBound <= leftmost) {
				//then we can ignore leftBound
				if (lChild.count() != lChild.rightmost-lChild.leftmost+1) {
					return lChild.indexOfFirst0(leftBound);
				}
				else {
					return rChild.indexOfFirst0(leftBound);
				}
			}
			else {
				if (lChild.rightmost>=leftBound) {
					//answer might be in left
					int ans1=lChild.indexOfFirst0(leftBound);
					if (ans1!=-1) return ans1;
					if (rChild.count()!=rChild.rightmost-rChild.leftmost+1)
						return rChild.indexOfFirst0(leftBound);
					else return -1;
				}
				return rChild.indexOfFirst0(leftBound);
			}
		}
		int indexOfFirst1(int leftBound) {
			if (leftmost==rightmost) {
				if (count()==1) {
					return leftmost;
				}
				else {
					return -1;
				}
			}
			prop();
			if (leftBound <= leftmost) {
				//then we can ignore leftBound
				if (lChild.count() != 0) {
					return lChild.indexOfFirst1(leftBound);
				}
				else {
					return rChild.indexOfFirst1(leftBound);
				}
			}
			else {
				if (lChild.rightmost>=leftBound) {
					//answer might be in left
					int ans1=lChild.indexOfFirst1(leftBound);
					if (ans1!=-1) return ans1;
					if (rChild.count()!=0)
						return rChild.indexOfFirst1(leftBound);
					else return -1;
				}
				return rChild.indexOfFirst1(leftBound);
			}
		}
		
		int rightmost1() {
			if (leftmost==rightmost) {
				return leftmost;
			}
			prop();
			if (rChild.count()>0) {
				return rChild.rightmost1();
			}
			else {
				return lChild.rightmost1();
			}
		}
	}
	
	static final Random random=new Random();
	static final int mod=1_000_000_007;
	
	static void ruffleSort(int[] a) {
		int n=a.length;//shuffle, then sort 
		for (int i=0; i<n; i++) {
			int oi=random.nextInt(n), temp=a[oi];
			a[oi]=a[i]; a[i]=temp;
		}
		Arrays.sort(a);
	}
	static long add(long a, long b) {
		return (a+b)%mod;
	}
	static long sub(long a, long b) {
		return ((a-b)%mod+mod)%mod;
	}
	static long mul(long a, long b) {
		return (a*b)%mod;
	}
	static long exp(long base, long exp) {
		if (exp==0) return 1;
		long half=exp(base, exp/2);
		if (exp%2==0) return mul(half, half);
		return mul(half, mul(half, base));
	}
	static long[] factorials=new long[2_000_001];
	static long[] invFactorials=new long[2_000_001];
	static void precompFacts() {
		factorials[0]=invFactorials[0]=1;
		for (int i=1; i<factorials.length; i++) factorials[i]=mul(factorials[i-1], i);
		invFactorials[factorials.length-1]=exp(factorials[factorials.length-1], mod-2);
		for (int i=invFactorials.length-2; i>=0; i--)
			invFactorials[i]=mul(invFactorials[i+1], i+1);
	}
	
	static long nCk(int n, int k) {
		return mul(factorials[n], mul(invFactorials[k], invFactorials[n-k]));
	}
	
	static void sort(int[] a) {
		ArrayList<Integer> l=new ArrayList<>();
		for (int i:a) l.add(i);
		Collections.sort(l);
		for (int i=0; i<a.length; i++) a[i]=l.get(i);
	}
	
	
	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");
		String next() {
			while (!st.hasMoreTokens())
				try {
					st=new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			return st.nextToken();
		}
		
		int nextInt() {
			return Integer.parseInt(next());
		}
		int[] readArray(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++) a[i]=nextInt();
			return a;
		}
		long nextLong() {
			return Long.parseLong(next());
		}
	}

	
}