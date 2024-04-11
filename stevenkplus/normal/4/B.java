import java.util.Scanner;

public class B004 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int d = in.nextInt(), sum = in.nextInt();
		int[] mins = new int[d], maxs = new int[d];
		int i = 0;
		int min = 0, max = 0;
		for (int x = 0; x < d; x++) {
			min += mins[i] = in.nextInt();
			max += maxs[i++] = in.nextInt();
		}
		if (sum >= min && sum <= max) {
			System.out.println("YES");
			int rem = sum-min;
			String sep = "";
			for (int x = 0; x < d; x++) {
				int diff = maxs[x]-mins[x];
				int k = diff>rem?rem:diff;
				rem-=k;
				System.out.print(sep + (mins[x] + k));
				sep = " ";
			}
			System.out.println();
		} else
			System.out.println("NO");
	}
}