import java.io.*;
import java.util.*;
import java.math.*;

public class Main {
	static final int N = 100011;
	public static void main(String args[]) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt(), k = in.nextInt();
		int[] a = new int[N];
		int[] b = new int[N];
		for(int i = 1; i <= n; i ++)
			a[i] = in.nextInt();
		for(int i = 1; i <= n; i ++)
			b[i] = in.nextInt();

		long left = 0;
		long right = 2000000007;
		while(left + 1 < right) {
			long mid = (left + right) / 2;
			int powder = k;
			boolean done = true;
			for(int i = 1; i <= n; i ++) {
				if(a[i] * mid > b[i]) {
					if(a[i] * mid > b[i] + powder) {
						done = false;
						break;
					} else {
						powder -= a[i] * mid - b[i];
					}
				}
			}
			if(done) left = mid;
			else right = mid;
		}
		System.out.println(left);
	}
}