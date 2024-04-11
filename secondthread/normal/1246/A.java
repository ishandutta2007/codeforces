import java.util.Scanner;

public class A {

	public static void main(String[] args) {
		Scanner fs = new Scanner(System.in);
		long n = fs.nextInt();
		long subEach=fs.nextLong();
		long ans=Integer.MAX_VALUE;
		for (int times=0; times<100000; times++) {
			long target=n-subEach*times;
			if (Long.bitCount(target)<=times && target>=times) {
				ans=Math.min(ans, times);
			}
		}
		if (ans<Integer.MAX_VALUE) {
			System.out.println(ans);
		}
		else {
			System.out.println(-1);
		}

	}

}