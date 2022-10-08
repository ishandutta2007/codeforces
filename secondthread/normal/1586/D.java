import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;
import java.util.StringTokenizer;

public class D {
	
	static Scanner fs;

	public static void main(String[] args) {
		fs=new Scanner(System.in);
		int n=fs.nextInt();
		//first ask about things bigger
		int[] realArray=new int[n];
		for (int targetVal=1; true; targetVal++) {
			int index=searchFor(targetVal, n);
			if (index==-1) break;
			realArray[index]=targetVal;
		}
		for (int targetVal=-1; true; targetVal--) {
			int index=searchFor(targetVal, n);
			if (index==-1) break;
			realArray[index]=targetVal;
		}
		int min=0;
		for (int i:realArray) min=Math.min(min, i);
		System.out.print("! ");
		for (int i:realArray) System.out.print(i-min+1+" ");
		System.out.println();
	}
	
	//returns the index, or -1 otherwise
	static int searchFor(int x, int n) {
		if (x==n) return -1;
		if (x==-n) return -1;
		if (x==0) throw null;
		if (x>0) {
			StringBuilder sb=new StringBuilder();
			sb.append("? ");
			for (int i=1; i<n; i++) sb.append("1 ");
			sb.append(x+1);
			System.out.println(sb.toString());
		}
		else {
			StringBuilder sb=new StringBuilder();
			sb.append("? ");
//			sb.append(x+1);
			for (int i=1; i<n; i++) sb.append((-x+1)+" ");
			sb.append(1);
			System.out.println(sb.toString());
		}
		int ans=fs.nextInt()-1;
		return ans;
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