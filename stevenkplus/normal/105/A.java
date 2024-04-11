import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class A105 {
	static class skill implements Comparable<skill> {
		String name;
		int level;

		public skill(String n) {
			this(n, 0);
		}

		public skill(String n, int l) {
			name = n;
			level = l;
		}

		public int compareTo(skill o) {
			return name.compareTo(o.name);
		}
	}

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		ArrayList<skill> skills = new ArrayList<skill>();
		int n = in.nextInt(), m = in.nextInt();
		double k = in.nextDouble();
		for (int x = 0; x < n; x++) {
			String na = in.next();
			int sk = in.nextInt();
			if (sk*k < 100) {
				continue;
			}
			skills.add(new skill(na, (int) (sk * k+.0001)));
		}
		b: for (int x = 0; x < m; x++) {
			String na = in.next();
			for (int i = 0; i < skills.size(); i++) {
				skill s = skills.get(i);
				if (s.name.equals(na)) {
					continue b;
				}
			}
			skills.add(new skill(na));
		}
		Collections.sort(skills);

		System.out.println(skills.size());
		for (skill s : skills) {
			System.out.println(s.name + " " + s.level);
		}
	}
}