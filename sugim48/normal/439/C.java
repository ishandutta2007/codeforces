import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int k = in.nextInt();
		int p = in.nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = in.nextInt();
		}
		
		ArrayDeque<Integer> even = new ArrayDeque<Integer>();
		ArrayDeque<Integer> odd = new ArrayDeque<Integer>();
		for (int i = 0; i < n; i++) {
			if (a[i] % 2 == 0) {
				even.add(a[i]);
			} else {
				odd.add(a[i]);
			}
		}
		
		int ne = even.size();
		int no = odd.size();
		if ((no - k + p >= 0) && ((no - k + p) % 2 == 0) && (ne + (no - k + p) / 2 >= p)) {
			System.out.println("YES");
			
			ArrayList<ArrayList<Integer>> lists = new ArrayList<ArrayList<Integer>>();
			for (int i = 0; i < k - p; i++) {
				ArrayList<Integer> list = new ArrayList<Integer>();
				list.add(odd.remove());
				lists.add(list);
			}
			for (int i = 0; i < p; i++) {
				ArrayList<Integer> list = new ArrayList<Integer>();
				if (even.size() > 0) {
					list.add(even.remove());
				} else {
					list.add(odd.remove());
					list.add(odd.remove());
				}
				lists.add(list);
			}
			lists.get(0).addAll(even);
			lists.get(0).addAll(odd);
			
			StringBuilder s = new StringBuilder();
			for (ArrayList<Integer> list: lists) {
				s.append(list.size());
				for (int e: list) {
					s.append(" ");
					s.append(e);
				}
				s.append("\n");
			}
			System.out.print(s);
		} else {
			System.out.println("NO");
		}
	}
}