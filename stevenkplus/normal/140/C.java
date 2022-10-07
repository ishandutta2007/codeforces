import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Hashtable;
import java.util.LinkedList;
import java.util.PriorityQueue;

public class C140 {
	static class Pair implements Comparable<Pair> {
		public int compareTo(Pair o) {
			int d = o.count - count;
			if (d == 0) {
				return o.num - num;
			}
			return d;
		}

		int count;
		int num;

		public Pair(int n) {
			count = 0;
			num = n;
		}
	}

	public static void main(String[] args) throws Exception {
		BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(r.readLine());
		String[] s = r.readLine().split(" ");
		PriorityQueue<Pair> pq = new PriorityQueue<Pair>();
		LinkedList<Pair> ll = new LinkedList<Pair>();
		Hashtable<Integer, Pair> ht = new Hashtable<Integer, Pair>();
		for (String ss : s) {
			int k = Integer.parseInt(ss);
			if (!ht.containsKey(k)) {
				ht.put(k, new Pair(k));
				ll.add(ht.get(k));
			}
			ht.get(k).count++;

		}
		for (Pair p : ll) {
			pq.add(p);
		}
		StringBuffer out = new StringBuffer();
		int num = 0;
		while (pq.size() >= 3) {
			Pair a = pq.poll(), b = pq.poll(), c = pq.poll();
			a.count--;
			b.count--;
			c.count--;
			int[] ar = { a.num, b.num, c.num };
			Arrays.sort(ar);
			out.append(ar[2] + " " + ar[1] + " " + ar[0] + "\n");
			if (a.count > 0)
				pq.add(a);
			if (b.count > 0)
				pq.add(b);
			if (c.count > 0)
				pq.add(c);
			num++;
		}
		System.out.println(num);
		System.out.print(out.toString());
	}
}