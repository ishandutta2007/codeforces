import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		long n = in.nextLong();
		System.out.println(hoge(16, n));
	}
	
	static long hoge(int i, long n) {
		if (n == 0) {
			return 0;
		} else if (i == 1) {
			return Math.abs(n);
		}
		long k;
		if (n > 0) {
			k = n1s(i);
		} else {
			k = -n1s(i);
		}
		
		long m = n / k;
		long ret1 = m * i + hoge(i - 1, n - m * k);
		long ret2 = (m + 1) * i + hoge(i - 1, n - (m + 1) * k);
		return Math.min(ret1, ret2);
	}
	
	static long n1s(int n) {
		long k = 0;
		for (int i = 0; i < n; i++) {
			k = k * 10 + 1;
		}
		return k;
	}
}