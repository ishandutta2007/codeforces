import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;
/*
4
11 3
01000000001
10 2
0110100101
5 2
10101
3 100
000

4
11 3
01000000001
 */
public class A {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt(), m=fs.nextInt();
			char[] line=fs.next().toCharArray();
			for (int t=0; t<m; t++) {
				boolean changed=false;
				char[] newLine=new char[n];
				for (int i=0; i<newLine.length; i++) {
					int count=0;
					if (i>0) count+=line[i-1]-'0';
					if (i+1<n) count+=line[i+1]-'0';
					if (line[i]=='1' || count==1) {
						newLine[i]='1';
					}
					else {
						newLine[i]='0';
					}
				}
//				System.out.println(newLine);
				for (int i=0; i<n; i++) if (line[i]!=newLine[i]) changed=true;
				line=newLine;
				if (!changed) break;
			}
			System.out.println(line);
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