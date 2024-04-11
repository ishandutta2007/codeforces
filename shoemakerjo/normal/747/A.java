import java.util.Scanner;

public class Display {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		long n = s.nextLong();
		long w = 1;
		long l = n;
		long aw = 0;
		long al = 0;
		while (l >= w) {
			if (n%w == 0 && w <= n/w) {
				aw = w;
				al = n/w;
			}
			w++;
			l = n/w;
		}
		System.out.println(aw + " " + al);

	}

}