import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;

public class A {
	
	public static void main(String[] args) throws InterruptedException {
		FastScanner fs=new FastScanner();
		int nPeople=fs.nextInt();
		double distance=fs.nextInt();
		double walkSpeed=fs.nextInt(), busSpeed=fs.nextInt();
		int seats=fs.nextInt();
		int trips=(nPeople+seats-1)/seats;
		double minTime=0, maxTime=distance/walkSpeed;
		for (int i=0; i<1000; i++) {
			double totalTime=(minTime+maxTime)/2;
//			double busDistPerGroup=totalTime*busSpeed*walkSpeed/(walkSpeed-busSpeed)-distance*busSpeed;
			double busDistPerGroup=(totalTime*walkSpeed*busSpeed-distance*busSpeed)/(walkSpeed-busSpeed);
//			System.out.println("busDist: "+busDistPerGroup);
			
			double forwardTime=busDistPerGroup/busSpeed;
			double gapLeft=(busSpeed-walkSpeed)*forwardTime;
			double closeTime=gapLeft/(busSpeed+walkSpeed);
			double realBusTime=forwardTime*trips+closeTime*(trips-1);
			if (realBusTime<totalTime) {
				maxTime=totalTime;
			}
			else {
				minTime=totalTime;
			}
		}
		System.out.println(minTime);
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