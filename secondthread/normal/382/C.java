import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class C {
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		int[] a=fs.readArray(n);
		if (n==1) {
			System.out.println(-1);
			return;
		}
		sort(a);
		if (n==2) {
			int mid=a[1]-a[0];
			if (mid==0) {
				System.out.println(1);
				System.out.println(a[0]);
			}
			else if (mid%2==1) {
				System.out.println(2);
				System.out.println((a[0]-mid)+" "+(a[1]+mid));
			}
			else {
				System.out.println(3);
				System.out.println((a[0]-mid)+" "+(a[0]+(mid/2))+" "+(a[1]+mid));
			}
			return;
		}
		int[] diffs=new int[n-1];
		for (int i=0; i<diffs.length; i++)
			diffs[i]=a[i+1]-a[i];
		TreeSet<Integer> nums=new TreeSet<>();
		for (int i:diffs) nums.add(i);
		if (nums.size()==1) {
			if (nums.first()==0) {
				System.out.println(1);
				System.out.println(a[0]);
			}
			else {
				System.out.println(2);
				int diff=nums.first();
				System.out.println(a[0]-diff+" "+(a[n-1]+diff));
			}
			return;
		}
		if (nums.size()>2) {
			System.out.println(0);
		}
		else {
			//one big diff that I might need to split in half
			long diff=Math.min(a[n-1]-a[n-2], a[1]-a[0]);
			HashSet<Long> seen=new HashSet<>();
			for (int i:a) seen.add((long)i);
			long missed=0, thingMissed=-1;
			for (int i=0; i<=n; i++) {
				if (!seen.contains(a[0]+(diff)*i)) {
					missed++;
					thingMissed=a[0]+diff*i;
				}
			}
			if (missed==1) {
				System.out.println(1);
				System.out.println(thingMissed);
			}
			else {
				System.out.println(0);
			}
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