import java.util.Arrays;
import java.util.Scanner;

public class A063 {
	static class guy implements Comparable<guy> {
		String name, rank;
		int pos;

		public guy(String a, String b, int aa) {
			name = a;
			rank = b;
			pos = aa;
		}

		public int compareTo(guy o) {
			int p = priority(), po = o.priority();
			if (p == po) {
				return pos - o.pos;
			}
			return p - po;
		}
		public int priority() {
			String s = rank;
			if (s.equals("rat"))
				return 0;
			if (s.equals("man"))
				return 2;
			if (s.equals("captain"))
				return 3;
			return 1;
		}
	}

	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		guy[] g = new guy[n];
		for(int x = 0;x<n;x++) {
			g[x] = new guy(in.next(),in.next(),x);
		}
		Arrays.sort(g);
		for(guy gg:g) System.out.println(gg.name);
	}
}