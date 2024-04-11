import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Random;
import java.util.StringTokenizer;
/*
100 4 3
0111
0111
0111
0111
0111
0111
0111
0111
0111
0111
0111
0111
0111
0111
0111
0111
0111
0111
0111
0111
0111
0111
0111
0111
0111
0111
0111
0111
0111
0111
0111
0111
0111
0111
0111
0111
0111
0111
0111
0111
0111
0111
0111
0111
0111
0111
0111
0111
0111
0111
0111
0111
0111
0111
0111
0111
0111
0111
0111
0111
0111
0111
0111
0111
0111
0111
0111
0111
0111
0111
0111
0111
0111
0111
0111
0111
0111
0111
0111
0111
0111
0111
0111
0111
0111
0111
0111
0111
0111
0111
0111
0111
0111
0111
0111
0111
0111
0111
0111
0111
 */
public class D {
	
	//TODO: unseed this!
	static Random random=new Random(6);

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=1;
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt();
			long nBits=fs.nextLong();
			int maxOnBits=fs.nextInt();
//			int n=random.nextInt(1000)+1;
//			int nBits=random.nextInt(5)+1;
//			int maxOnBits=random.nextInt(nBits)+1;
//			int maxOnBits=nBits;
			
			long[] a=new long[n];
			for (int i=0; i<n; i++) {
//				char[] line=new char[nBits];
//				Arrays.fill(line, '0');
//				int nToTurnOn=Math.max(random.nextInt(maxOnBits), random.nextInt(maxOnBits))+1;
//				for (int j=0; j<nToTurnOn; j++) 
//					line[random.nextInt(nBits)]='1';
				
				char[] line=fs.next().toCharArray();
				for (int j=0; j<line.length; j++)
					if (line[j]=='1') a[i]+=1l<<j;
			}
			
			//try 50 people, odds they all miss is < 1/2^50
			long best=0;
			try {
			for (int time=0; time<50; time++) {
				int person=random.nextInt(n);
				long keepMask=a[person];
				int[] bits=new int[Long.bitCount(keepMask)];
				int bitsIndex=0;
				for (int i=0; i<nBits; i++)
					if ((keepMask&(1l<<i))!=0) bits[bitsIndex++]=i;
				int[] smallerCount=new int[1<<bits.length];
				for (long l:a) {
					int val=0;
					for (int i=0; i<bits.length; i++) {
						if ((l&(1l<<bits[i]))!=0) val+=1<<i;
					}
					smallerCount[val]++;
				}
				for(int i = 0; i < bits.length; ++i) 
					for(int mask = (1<<bits.length)-1; mask>=0; mask--)
						if((mask & (1<<i))==0)
							smallerCount[mask] += smallerCount[mask^(1<<i)];
				int bestWork=0;
				for (int i=0; i<smallerCount.length; i++)
					if (smallerCount[i]*2>=n && Integer.bitCount(i)>Integer.bitCount(bestWork))
						bestWork=i;
				if (Integer.bitCount(bestWork)>Long.bitCount(best)) {
					best=0;
					for (int i=0; i<bits.length; i++) {
						if ((bestWork&(1<<i))!=0) {
							best+=1l<<bits[i];
						}
					}
				}
			}
			}
			catch (Throwable t) {
				while (true);
			}
			//TODO: print best
			for (int i=0; i<nBits; i++) {
				System.out.print(((best&(1l<<i))!=0)?1:0);
			}
			System.out.println();
		}
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