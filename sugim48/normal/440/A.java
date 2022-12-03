import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		long n = in.nextLong();
		long ans = n * (n + 1) / 2;
		for (int i = 0; i < n - 1; i++) {
			long a = in.nextLong();
			ans -= a;
		}
		System.out.println(ans);
	}
}