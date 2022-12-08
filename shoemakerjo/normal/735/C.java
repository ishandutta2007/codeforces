import java.util.Scanner;

public class C {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		long n = s.nextLong();
//		System.out.println(Long.MAX_VALUE);
		long prev = 1;
		long cur = 1;
		long wins = 0;
		while (cur <= n) {
			long temp = cur;
			cur = prev+cur;
			prev = temp;
			wins++;
		}
		System.out.println(wins-1);
		

	}

}