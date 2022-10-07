import java.util.Scanner;

public class A114 {
	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(System.in);
		int k = in.nextInt(), m = in.nextInt();
		int x = 0;
		while (m % k == 0) {
			m /= k;
			x++;
		}
		if(m==1) {
			System.out.println("YES");
			System.out.println(x-1);
		}
		else System.out.println("NO");
	}
}