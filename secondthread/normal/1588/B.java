import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;
import java.util.StringTokenizer;

public class B {
	
	static Scanner fs=new Scanner(System.in);
	
	public static void main(String[] args) {
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt();
			long totalInversions=query(0, n-1);
			
			//TODO: need to get last
			//bs last index that is the same
			int min=0, max=n-1;
			while (min!=max) {
				int mid=(min+max)/2;
				if (query(0, mid)==totalInversions) {
					max=mid;
				}
				else {
					min=mid+1;
				}
			}
			long withoutLast=query(0, min-1);
			long secondSize=totalInversions-withoutLast+1;
			long secondTotal=secondSize*(secondSize-1)/2;
			long firstTotal=totalInversions-secondTotal;
			long firstSize=nCkInv(firstTotal);
			long k=min;
			long j=min-secondSize+1;
			long i=j-firstSize;
			printAns(i, j, k);
		}
	}
	
	static long nCkInv(long total) {
		//TODO: bs this
		long min=0, max=2_000_000_000l;
		while (true) {
			long mid=(min+max)/2;
			if ((mid*(mid-1))/2==total) return mid;
			if ((mid*(mid-1))/2>total) max=mid-1;
			else min=mid+1;
		}
	}
	
	static long query(int l, int r) {
		l++;
		r++;
		System.out.println("? "+l+" "+r);
		return fs.nextLong();
	}
	static void printAns(long i, long j, long k) {
		i++;
		j++;
		k++;
		System.out.println("! "+i+" "+j+" "+k);
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