import java.util.Arrays;
import java.util.Scanner;

public class C118 {
	static class pair implements Comparable<pair> {
		int index;
		int diff;

		public pair(int a, int b) {
			index = a;
			diff = b;
		}

		public int compareTo(pair o) {
			int d = abs(diff) - abs(o.diff);
			if (d == 0) {
				if (diff == o.diff) {
					return diff * (index - o.index);
				} else {
					return -diff;
				}
			} else
				return d;
		}
	}

	public static void main(String[] args) {
		int min = Integer.MAX_VALUE;
		char best = '0';
		Scanner in = new Scanner(System.in);
		int n = in.nextInt(), k = in.nextInt();
		String line = in.next();
		String beststr = "";
		for (char c = '0'; c <= '9'; c++) {
			int d = distance(line, c, k);
			if (d < min) {
				min = d;
				best = c;
				beststr = toString(line,c,k);
			} else if (d == min) {
				String s = toString(line, c, k);
				if (beststr.compareTo(s) > 0) {
					beststr = s;
					best = c;
				}
			}
		}
		System.out.println(min);
		System.out.println(beststr);
	}

	public static int distance(String a, char c, int count) {
		int[] diffs = new int[a.length()];
		int i = 0;
		for (char cc : a.toCharArray()) {
			diffs[i++] = abs(cc - c);
		}
		int sum = 0;
		Arrays.sort(diffs);
		for (int x = 0; x < count; x++) {
			sum += diffs[x];
		}
		return sum;
	}

	public static String toString(String a, char c, int count) {
		StringBuffer st = new StringBuffer(a);
		pair[] diffs = new pair[a.length()];
		int i = 0;
		for (char cc : a.toCharArray()) {
			diffs[i] = new pair(i++, cc - c);
		}
		int sum = 0;
		Arrays.sort(diffs);
		for (int x = 0; x < count; x++) {
			st.setCharAt(diffs[x].index, c);
		}
		return st.toString();
	}

	static int abs(int k) {
		return k > 0 ? k : -k;
	}
}