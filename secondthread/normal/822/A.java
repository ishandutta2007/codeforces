import java.util.Scanner;

public class Factorials {

	public static void main(String[] args) {
		Scanner s=new Scanner(System.in);
		int a=s.nextInt();
		int b=s.nextInt();
		long total=1;
		for (int i=1; i<=Math.min(a, b); i++) {
			total*=i;
		}
		System.out.println(total);

	}

}