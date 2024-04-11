import java.util.ArrayList;
import java.util.Collections;
import java.util.Hashtable;
import java.util.Scanner;

public class B075 {
	static class f implements Comparable<f> {
		String a;
		int b;

		public f(String a) {
			this(a, 0);
		}

		public f(String x, int y) {
			a = x;
			b = y;
		}

		public void add(int p) {
			b += p * 5;
		}

		public int compareTo(f o) {
			int d = o.b - b;
			if (d == 0) {
				return a.compareTo(o.a);
			}
			return d;
		}
	}

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		Hashtable<String, Integer> ht = new Hashtable<String, Integer>();
		ArrayList<f> points = new ArrayList<f>();
		String myname = in.next();
		int k = in.nextInt();
		in.nextLine();
		for (int x = 0; x < k; x++) {
			String line = in.nextLine();
			String name1 = line.substring(0, line.indexOf(" "));
			String name2 = line.substring(
					line.lastIndexOf(" ", line.length() - 6) + 1,
					line.length()-7);
			int p = 0;
			if (line.contains("'s post")) {
				p++;
			}
			if (line.contains("commented on"))
				p++;
			if (line.contains("posted on"))
				p += 3;
			String friend = null;
			if (name1.equals(myname)) {
				friend = name2;
			} else if (name2.equals(myname))
				friend = name1;
			if(friend==null) {
				if (!ht.containsKey(name1)) {
					ht.put(name1, points.size());
					points.add(new f(name1));
				}if (!ht.containsKey(name2)) {
					ht.put(name2, points.size());
					points.add(new f(name2));
				}
				continue;
			}
			if (friend.equals(myname))
				continue;
			if (!ht.containsKey(friend)) {
				ht.put(friend, points.size());
				points.add(new f(friend));
			}
			int d = ht.get(friend);
			points.get(d).add(p);
		}
		Collections.sort(points);
		for (int x = 0; x < points.size(); x++) {
			System.out.println(points.get(x).a);
		}
	}
}