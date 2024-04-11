import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;
/*
1
3 5
1 2
3 4

0111
0111
0111
010101
 */
public class D {
	
	public static void main(String[] args) throws InterruptedException {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			int nSegments=fs.nextInt();
			long targetTotal=fs.nextInt();
			int l1=fs.nextInt(), r1=fs.nextInt(), 
					l2=fs.nextInt(), r2=fs.nextInt();
			int lMin=Math.min(l1, l2), rMax=Math.max(r2, r1);
			int unionArea=rMax-lMin;
			long intersectionArea=(r1-l1 + r2-l2)-unionArea;
//			System.out.println("union area: "+unionArea+" intersectArea: "+intersectionArea);
			
			long zPre=Math.max(0, -intersectionArea);
			long oneLength=unionArea-Math.max(0, intersectionArea);
			
			if (intersectionArea>0) {
				targetTotal-=nSegments*intersectionArea;
				if (targetTotal<=0) {
					System.out.println(0);
					continue;
				}
			}
//			System.out.println(zPre+" "+oneLength);
			
			//way 1: 
			//0000, 1111, 010101
			long bestAns=Long.MAX_VALUE;
			for (long nToTake=1; nToTake<=nSegments; nToTake++) {
				long curLeft=targetTotal;
				long ans=0;
				ans=zPre*nToTake;
				if (targetTotal<=oneLength*nToTake) {
					ans+=curLeft;
				}
				else {
					ans+=oneLength*nToTake;
					curLeft-=oneLength*nToTake;
					ans+=2*(curLeft);
				}
//				System.out.println("With nTake: "+nToTake+" got ans: "+ans);
				bestAns=Math.min(bestAns, ans);
			}
			
			System.out.println(bestAns);
			
		}
	}
	
	void sort(int[] a) {
		ArrayList<Integer> list=new ArrayList<>();
		for (int i:a) list.add(i);
		Collections.sort(list);
		for (int i=0; i<a.length; i++) a[i]=list.get(i);
	}
	
	
	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");
		
		public String next() {
			while (!st.hasMoreTokens())
				try {
					st=new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			return st.nextToken();
			
		}
		
		public int nextInt() {
			return Integer.parseInt(next());
		}
		
		public int[] readArray(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++) a[i]=nextInt();
			return a;
		}
		
		public long nextLong() {
			return Long.parseLong(next());
		}
		
		public long[] readLongArray(int n) {
			long[] a=new long[n];
			for (int i=0; i<n; i++) a[i]=nextLong();
			return a;
		}
	}

}