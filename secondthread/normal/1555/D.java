import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class D {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		int nQueries=fs.nextInt();
		char[] line=fs.next().toCharArray();
		int[][] prefixSum=new int[3][n+3];
		for (int c=0; c<3; c++) {
			for (int i=3; i<n+3; i++) {
				prefixSum[c][i]=prefixSum[c][i-3];
				if (line[i-3]-'a'==c) prefixSum[c][i]++;
			}
		}
		
		PrintWriter out=new PrintWriter(System.out);
		for (int qq=0; qq<nQueries; qq++) {
			int l=fs.nextInt()-1, r=fs.nextInt()-1;
			int ans=0;
			ans=Math.max(ans, count(l, r, "abc", prefixSum));
			ans=Math.max(ans, count(l, r, "acb", prefixSum));
			ans=Math.max(ans, count(l, r, "bac", prefixSum));
			ans=Math.max(ans, count(l, r, "bca", prefixSum));
			ans=Math.max(ans, count(l, r, "cab", prefixSum));
			ans=Math.max(ans, count(l, r, "cba", prefixSum));
			out.println(r-l+1-ans);
		}
		out.close();
	}
	
	static int count(int l, int r, String val, int[][] prefixSum) {
		int res=0;
		for (int i=0; i<3; i++) {
			int c=val.charAt(i)-'a';
			res+=countOccsIn(l, r, c, i, prefixSum);
		}
		return res;
	}
	
	// in substring from l, r, if c first starts at offset, 
	// count num of times it appears
	static int countOccsIn(int l, int r, int c, int offset, int[][] prefixSum) {
		l+=offset;
		if (l>r) return 0;
		r-=(r-l)%3;
		return prefixSum[c][r+3]-prefixSum[c][l];
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