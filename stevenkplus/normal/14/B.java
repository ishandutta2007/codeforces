import java.util.Arrays;
import java.util.Scanner;

public class B014 {
	static class end implements Comparable<end> {
		boolean start;
		int x;

		public end(int a, boolean b) {
			x = a;
			start = b;
		}

		public int compareTo(end o) {
			int d = x - o.x;
			if (d == 0) {
				return start ? -1 : 1;
			}
			return d;
		}
	}

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt(), xx = in.nextInt();
		end[] e = new end[n * 2];
		for (int x = 0; x < n; x++) {
			int a = in.nextInt(), b = in.nextInt();
			if (a > b) {
				int c = a;
				a = b;
				b = c;
			}
			e[2 * x] = new end(a, true);
			e[2 * x+1] = new end(b, false);
		}
		end[] or = e.clone();
		Arrays.sort(e);
		int count = 0;
		boolean pos = false;
		for (end ee : e) {
			if (ee.start) {
				count++;
			} else
				count--;
			if (count == n) {
				pos = true;
				break;
			}
		}
		if (!pos) {
			System.out.println(-1);
			return;
		}
		int max = 0;
		for (int x = 0; x < n; x++) {
			int a = or[2 * x].x, b = or[2 * x + 1].x;
			if (a <= xx && b >= xx)
				continue;
			else {
				int d = a > xx ? (a - xx) : xx - b;
				if (d > max)
					max = d;
			}
		}
		System.out.println(max);
	}
}