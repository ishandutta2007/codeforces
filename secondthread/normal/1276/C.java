

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Map;
import java.util.StringTokenizer;
import java.util.TreeMap;

public class C {

	public static void solve(FastScanner fs) {	
		int n=fs.nextInt();
		TreeMap<Integer, Integer> map=new TreeMap<>();
		for (int i=0; i<n; i++) {
			int v=fs.nextInt();
			map.put(v, map.getOrDefault(v, 0)+1);
		}
		Number[] numbers=new Number[map.size()];
		int index=0;
		for (Map.Entry<Integer, Integer> e:map.entrySet()) {
			numbers[index++]=new Number(e.getKey(), e.getValue());
		}
		Arrays.sort(numbers);
		int width=n;
		int numberIndex=numbers.length-1;
		int[] prefixSums=new int[numbers.length+1];
		for (int i=0; i<numbers.length; i++) prefixSums[i+1]=prefixSums[i]+numbers[i].count;
		
		int bestAnswer=-1;
		int bestWidth=0, bestHeight=0;
		while (width!=0) {
			while (numberIndex>=0 && numbers[numberIndex].count>=width) numberIndex--;
			
			int fullRows=numbers.length-1-numberIndex;
			int extraRoom=prefixSums[numberIndex+1];
			int additionalHeight=extraRoom/width;
			int curHeight=additionalHeight+fullRows;
			if (curHeight>=width) {
				int curSquares=width*curHeight;
				if (curSquares>bestAnswer) {
					bestAnswer=curSquares;
					bestWidth=width;
					bestHeight=curHeight;
				}
			}
			
			width--;
		}
		PrintWriter out=new PrintWriter(System.out);
		out.println(bestAnswer);
		out.println(bestHeight+" "+bestWidth);
		//TODO: extract answer
		int w=bestWidth, h=bestHeight;
		int[][] ans=new int[w][h];
		int curX=0, curY=0;
		for (int num=numbers.length-1; num>=0; num--) {
			Number curNum=numbers[num];
			for (int x=0; x<Math.min(w, curNum.count) && curY<h; x++) {
				ans[curX][curY]=curNum.value;
				curX++;
				if (curX>=w) {
					curX=0;
					curY++;
				}
			}
			
		}
		for (int y=0; y<h; y++) {
			for (int x=0; x<w; x++) {
				out.print(ans[x][(y-x+h)%h]+" ");
			}
			out.println();
		}
		out.close();
	}

	static class Number implements Comparable<Number> {
		int value, count;
		
		Number(int value, int count) {
			this.value=value;
			this.count=count;
		}
		
		public int compareTo(Number o) {
			return Integer.compare(count, o.count);
		}
	}
	
	
	
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		FastScanner scanner = new FastScanner(System.in);
		solve(scanner);
	}
	

	private static class FastScanner {
		BufferedReader br;
		StringTokenizer st;
		public FastScanner(InputStream in) {
			br = new BufferedReader(new InputStreamReader(in));
		}
		String next() {
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}
		int nextInt() {
			return Integer.parseInt(next());
		}
		long nextLong() {
			return Long.parseLong(next());
		}
		double nextDouble() {
			return Double.parseDouble(next());
		}
		String nextLine() {
			String str = "";
			try {
				str = br.readLine();
			} catch (IOException e) {
				e.printStackTrace();
			}
			return str;
		}
		int[] readArray(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++)
				a[i]=nextInt();
			return a;
		}
		long[] readLongArray(int n) {
			long[] a=new long[n];
			for (int i=0; i<n; i++)
				a[i]=nextLong();
			return a;
		}
	}
}