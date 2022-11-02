import java.io.*;
import java.util.*;

public class Main {
	static final int N = 121;
	public static void main(String args[]) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt(), k = in.nextInt();
		int[] a = new int[N];
		for(int i = 1; i <= n; i ++)
			a[i] = in.nextInt();

		Arrays.sort(a, 1, n + 1);
		for(int i = 1; i <= n / 2; i ++) {
			int t = a[i]; a[i] = a[n - i + 1]; a[n - i + 1] = t;
		}
		int cnt = 0;
		for(int i = 1; i <= n; i ++)
			if(a[i] > 0 && a[i] >= a[k])
				cnt ++;
		System.out.println(cnt);
	}
}