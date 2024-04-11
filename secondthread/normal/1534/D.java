import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class D {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		System.out.println("? 1");
		boolean[][] isEdge=new boolean[n][n];
		int[] distances=fs.readArray(n);
		int evenCount=0, oddCount=0;
		ArrayList<Integer> even=new ArrayList<>(), odd=new ArrayList<>();
		for (int i=0; i<n; i++) {
			if (distances[i]%2==0) {
				evenCount++;
				if (i!=0)
					even.add(i);
			}
			else {
				oddCount++;
				odd.add(i);
			}
			if (distances[i]==1) {
				isEdge[0][i]=isEdge[i][0]=true;
			}
		}
		ArrayList<Integer> toCheck;
		if (evenCount<=(n+1)/2) {
			toCheck=even;
		}
		else {
			toCheck=odd;
		}
		for (int i:toCheck) {
			System.out.println("? "+(i+1));
			int[] dist=fs.readArray(n);
			for (int j=0;j<n; j++) {
				if (dist[j]==1) isEdge[j][i]=isEdge[i][j]=true;
			}
		}
		System.out.println("!");
		for (int i=0; i<n; i++) {
			for (int j=i+1; j<n; j++) {
				if (isEdge[i][j]) {
					System.out.println(i+1+" "+(j+1));
				}
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