//package si.contest4;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class CFHelper {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int t=fs.nextInt();
		while (t-->0) {
			int n=fs.nextInt();
			char[] bin=fs.next().toCharArray();
			char[] match=fs.next().toCharArray();
			ArrayList<Integer> a1=convert(bin);
			ArrayList<Integer> a2=convert(match);
			System.out.print(a1.size()+a2.size()+" ");
			if (!a1.isEmpty()) {
				for (int i=0; i<a1.size(); i++) {
					System.out.print(a1.get(i)+1+" ");
				}
			}
			if (!a2.isEmpty()) {
				for (int i=a2.size()-1; i>=0; i--) {
					System.out.print(a2.get(i)+1+" ");
				}
			}
			System.out.println();

		}

	}
	static ArrayList<Integer> convert(char[] bin) {
		ArrayList<Integer> ans=new ArrayList<>();
		for (int i=1; i<bin.length; i++) {
			if (bin[i]!=bin[i-1]) {
				if (bin[i-1]=='1')
					ans.add(i-1);
				else
					ans.add(i-1);
			}
		}
		if (bin[bin.length-1]=='1') {
			ans.add(bin.length-1);
		}
		return ans;
	}

	static void sort(int[] a) {
		ArrayList<Integer> l=new ArrayList<>();
		for (int i:a)
			l.add(i);
		Collections.sort(l);
		for (int i=0; i<a.length; i++)
			a[i]=l.get(i);
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
			for (int i=0; i<n; i++)
				a[i]=nextInt();
			return a;
		}
		long nextLong() {
			return Long.parseLong(next());
		}
	}

}