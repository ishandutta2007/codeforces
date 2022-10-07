import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;

public class A083 {
	public static void main(String[] args) throws Exception {
		BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(r.readLine());
		String[] ar = r.readLine().split("\\s");
		int[] arr = new int[n + 1];
		arr[n] = Integer.MAX_VALUE;
		for (int x = 0; x < n; x++) {
			arr[x] = Integer.parseInt(ar[x]);
		}
		int prev = -1;
		long count  = 0;
		long sum = 0;
		for (int x : arr) {
			if (x == prev) {
				count++;
			} else {
				sum += count * (count + 1) / 2;
				count = 1;
			}
			prev = x;
		}
		System.out.println(sum);
	}
}