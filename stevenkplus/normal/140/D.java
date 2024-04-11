import java.util.Arrays;
import java.util.Scanner;

public class D140 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int[] ar = new int[n];
		for (int x = 0; x < n; x++) {
			ar[x] = in.nextInt();
		}
		Arrays.sort(ar);
		int maxtime = 12 * 60 - 10;// 710
		int best = -1;
		int sum = 0;
		for (int x = 0; x < n; x++) {
			sum += ar[x];
			if (sum <= maxtime)
				best = x;
		}
		best++;
		int time = 6 * 60 - 10;
		time *= -1;
		int tot = 0;
		for (int x = 0; x < best; x++) {
			time+=ar[x];
			if(time>0){
				tot+=time;
			}
		}
		System.out.println(best + " " + tot);
	}
}