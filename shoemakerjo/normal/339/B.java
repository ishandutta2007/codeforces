import java.util.Scanner;

public class XeniaRingroad {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		long n = s.nextLong();
		long m = s.nextLong();
		long prev = 1;
		long ans = 0;
		for (int i = 0; i < m; i++) {
			long cur = s.nextLong();
			if (cur >= prev) ans+=cur-prev;
			else ans+= n+cur-prev;
			prev = cur;
//			System.out.println(ans);
		}
		System.out.println(ans);

	}

}