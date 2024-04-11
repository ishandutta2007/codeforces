import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class E139 {
	static boolean REVERSE = false;
	static boolean TREEFIRST = false;

	public static void main(String[] args) throws Exception {
		BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(r.readLine());
		int t = Integer.parseInt(st.nextToken()), m = Integer.parseInt(st
				.nextToken());
		LinkedList<mush> mushrooms = new LinkedList<mush>();
		ArrayList<plant> flora = new ArrayList<plant>();
		for (int x = 0; x < t; x++) {
			st = new StringTokenizer(r.readLine());
			int a = Integer.parseInt(st.nextToken()), b = Integer.parseInt(st
					.nextToken()), c = Integer.parseInt(st.nextToken()), d = Integer
					.parseInt(st.nextToken());
			double pow1 = 1 - c / 100., pow2 = 1 - d / 100.;
			endpoint e1 = new endpoint(1, a - b, pow1), e2 = new endpoint(2, a,
					pow1), e3 = new endpoint(3, a, pow2), e4 = new endpoint(4,
					a + b, pow2);
			flora.add(e1);
			flora.add(e2);
			flora.add(e3);
			flora.add(e4);
		}
		for (int x = 0; x < m; x++) {
			st = new StringTokenizer(r.readLine());
			int a = Integer.parseInt(st.nextToken()), b = Integer.parseInt(st
					.nextToken());
			mush lol = new mush(a, b);
			mushrooms.add(lol);
			flora.add(lol);
		}
		Collections.sort(flora);
		double log = 0;
		int z = 0;
		for (plant p : flora) {
			if (p instanceof mush) {
				if (z == 0)
					((mush) p).power *= Math.exp(log);
				else
					((mush) p).power = 0;
			} else {
				endpoint e = (endpoint) p;
				if (e.type == 1 || e.type == 3) {
					if (e.fac == 0) {
						z++;
					} else {

						log += Math.log(e.fac);
					}

				} else {
					if (e.fac == 0) {
						z--;
					} else
						log -= Math.log(e.fac);
				}
			}
		}
		double sum = 0;
		for (mush mm : mushrooms) {
			sum += mm.power;
		}
		System.out.println(sum);

	}

	static class endpoint extends plant {
		int type;
		double fac;

		public endpoint(int t, int num, double factor) {
			super(num);
			fac = factor;
			type = t;
		}

		@Override
		public int compareTo(plant o) {
			int d = num - o.num;
			if (d != 0)
				return d;
			if (type == 1 || type == 2)
				return -1;
			else
				return 1;
		}
	}

	static class plant implements Comparable<plant> {
		boolean isTree;
		int num;

		public plant(int n) {
			num = n;
			isTree = false;
		}

		public int compareTo(plant o) {
			int diff = num - o.num;
			if (diff == 0) {
				if (isTree)
					return 1;
				else
					return -1;
			}
			if (REVERSE)
				return -diff;
			else
				return diff;
		}
	}

	static class mush extends plant {
		double power;

		public mush(int num, int pow) {
			super(num);
			power = pow;
		}

		public int compareTo(plant o) {
			if (o instanceof endpoint) {
				return -((endpoint) o).compareTo(this);
			} else
				return super.compareTo(o);
		}
	}

}