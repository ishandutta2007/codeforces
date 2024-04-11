import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;

public class B103 {
	static class guy {
		LinkedList<guy> guys;

		public guy() {
			guys = new LinkedList<guy>();
		}

		public void die() {
			guys.poll().guys.remove(this);
		}

		public void add(guy o) {
			guys.add(o);
			o.guys.add(this);
		}

		public boolean dumb() {
			return guys.size() == 1;
		}
	}

	public static void main(String[] args) throws Exception {
		BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
		String[] s = r.readLine().split(" ");
		int n = Integer.parseInt(s[0]);
		int m = Integer.parseInt(s[1]);
		if (m != n) {
			System.out.println("NO");
			return;
		}
		guy guys[] = new guy[n];
		for (int x = 0; x < n; x++) {
			guys[x] = new guy();
		}
		for (int x = 0; x < n; x++) {
			s = r.readLine().split(" ");
			int a = Integer.parseInt(s[0]) - 1, b = Integer.parseInt(s[1]) - 1;
			guys[a].add(guys[b]);
		}
		int count = n;
		for (int x = 0; x < n; x++) {
			for (int y = 0; y < n; y++) {
				if (guys[y].dumb()) {
					guys[y].die();
					count--;
				}
			}
		}
		for (int x = 0; x < n; x++) {
			if (guys[x].guys.size() == 2) {
				guy start = guys[x];
				start.guys.pollLast();
				while (start.guys.size() == 1) {
					guy next = start.guys.get(0);
					start.die();
					start = next;
					count--;
				}
				if (count == 0) {
					System.out.println("FHTAGN!");
				} else
					System.out.println("NO");
				return;
			}
		}
		System.out.println("NO");
	}
}