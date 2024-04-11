import java.util.Scanner;

public class B141 {
	static class square {
		int x1, x2, y1, y2;

		public boolean contains(int x, int y) {
			return x > x1 && x < x2 && y < y2 && y > y1;
		}

		public square(int a, int b, int c, int d) {
			x1 = a;
			y1 = b;
			x2 = c;
			y2 = d;
		}

		public square shift(int x, int y) {
			return new square(x1 + x, y1 + y, x2 + x, y2 + y);
		}
	}

	public static void main(String[] ars) {
		Scanner in = new Scanner(System.in);
		int a = in.nextInt(), x = in.nextInt(), y = in.nextInt();
		square s = new square(-a, 0, a, 2 * a), t = s.shift(-a, 0), u = s
				.shift(a, 0);
		square[] sq = new square[1000000];
		sq[0] = s;
		int j = 1;
		for(int i=1;j<sq.length;i++) {
			if(i%2==1) {
				sq[j++] = s.shift(0,2*i*a);
			}
			else {
				sq[j++] = t.shift(0,2*i*a);
				if(j<sq.length)
					sq[j++] = u.shift(0,2*i*a);
			}
		}
		for(int i = 0;i<sq.length;i++) {
			if(sq[i].contains(2*x,2*y)) {
				System.out.println(i+1);
				return;
			}
		}
		System.out.println(-1);
	}
}