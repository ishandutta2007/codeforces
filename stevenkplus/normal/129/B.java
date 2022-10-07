import java.util.ArrayList;
import java.util.Scanner;

public class B129 {
	static class lol {
		ArrayList<lol> c;

		public lol() {
			c = new ArrayList<lol>();
		}

		public boolean o() {
			return c.size() == 1;
		}

		public void r() {
			for (lol lol : c) {
				lol.c.remove(this);
			}
			c.clear();
		}

		public void conn(lol lol) {
			lol.c.add(this);
			c.add(lol);
		}
	}

	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt(), m = in.nextInt();
		ArrayList<lol> lol = new ArrayList<lol>();
		for (int x = 0; x < n; x++) {
			lol.add(new lol());
		}
		for (int x = 0; x < m; x++) {
			lol.get(in.nextInt() - 1).conn(lol.get(in.nextInt() - 1));
		}
		int x;
		for (x = 0; true; x++) {
			ArrayList<lol> ha = new ArrayList<lol>();
			for (lol lo : lol) {
				if (lo.o()) {
					ha.add(lo);
				}
			}
			if (ha.isEmpty())
				break;
			for (lol lo : ha) {
				lo.r();
			}
		}
		System.out.println(x);
	}
}