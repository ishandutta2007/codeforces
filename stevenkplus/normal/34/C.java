import java.util.Scanner;

public class C034 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		boolean[] lol = new boolean[1001];
		String[] s = in.nextLine().split(",");
		for (String ss : s) {
			lol[Integer.parseInt(ss)] = true;
		}
		int[] starts = new int[1001], ends = new int[1001];
		starts[0] = -1;
		ends[0] = -1;
		int i = 1;
		for (int x = 1; x < lol.length; x++) {
			if (lol[x]) {
				if (ends[i - 1] == x - 1) {
					ends[i - 1]++;
				} else {
					starts[i] = x;
					ends[i] = x;
					i++;
				}
			}
		}
		String sep = "";
		for (int x = 1; x < i; x++) {
			System.out.print(sep);
			sep = ",";
			if (ends[x] == starts[x]) {
				System.out.print(ends[x]);
			} else {
				System.out.printf("%d-%d", starts[x], ends[x]);
			}
		}
		System.out.println();
	}
}