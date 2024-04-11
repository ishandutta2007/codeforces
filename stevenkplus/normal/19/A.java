import java.util.Arrays;
import java.util.Hashtable;
import java.util.Scanner;

public class A019 {
	static class team implements Comparable<team> {
		int score;
		int score2;
		int score3;
		String name;

		public team(String a) {
			name = a;
			score = score2 = score3 = 0;
		}

		public int compareTo(team o) {
			int d1 = o.score - score, d2 = o.score2 - score2, d3 = o.score3
					- score3;
			if (d1 == 0) {
				if (d2 == 0) {
					return d3;
				}
				return d2;
			}
			return d1;
		}

	}

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		Hashtable<String, team> ht = new Hashtable<String, team>();
		int n = in.nextInt();
		team[] t = new team[n];
		for (int x = 0; x < n; x++) {
			String s = in.next();
			t[x] = new team(s);
			ht.put(s, t[x]);
		}
		for (int x = 0; x < n * (n - 1) / 2; x++) {
			String[] s = in.next().split("-");
			team a = ht.get(s[0]), b = ht.get(s[1]);
			s = in.next().split(":");
			int s1 = Integer.parseInt(s[0]), s2 = Integer.parseInt(s[1]);
			if (s1 == s2) {
				a.score++;
				b.score++;
			} else if (s1 > s2) {
				a.score += 3;
			} else
				b.score += 3;
			a.score2 += s1 - s2;
			a.score3 += s1;
			b.score2 += s2 - s1;
			b.score3 += s2;
		}
		Arrays.sort(t);
		String[] winners = new String[n / 2];
		for (int x = 0; x < n / 2; x++) {
			winners[x] = t[x].name;
		}
		Arrays.sort(winners);
		for (String s : winners) {
			System.out.println(s);
		}

	}
}