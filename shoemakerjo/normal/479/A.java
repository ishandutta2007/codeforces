import java.util.Scanner;

public class Expression {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		int a = s.nextInt();
		int b = s.nextInt();
		int c = s.nextInt();
		int max = 0;
		max = Math.max(max, a+b+c);
		max = Math.max(max, a*b*c);
		max = Math.max(max, a+b*c);
		max = Math.max(max, a*b+c);
		max = Math.max(max, (a+b)*c);
		max = Math.max(max, a*(b+c));
		System.out.println(max);

	}

}