import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int v = in.nextInt();
		int[] arr = new int[3002];
		for (int i = 0; i < n; i++) {
			int a = in.nextInt();
			int b = in.nextInt();
			arr[a] += b;
		}
		
		int ans = 0;
		for (int j = 1; j <= 3001; j++) {
			int _v = v;
			int k;
			
			k = Math.min(_v, arr[j - 1]);
			arr[j - 1] -= k;
			ans += k;
			_v -= k;
			
			k = Math.min(_v, arr[j]);
			arr[j] -= k;
			ans += k;
			_v -= k;
		}
		
		System.out.println(ans);
	}
}