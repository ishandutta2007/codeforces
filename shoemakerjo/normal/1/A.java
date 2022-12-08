import java.util.Scanner;

public class TheatreSquare {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		double n = (double) s.nextLong();
		double m = (double) s.nextLong();
		double a = (double) s.nextLong();
		System.out.printf("%.0f", (Math.ceil(n/a)*Math.ceil(m/a)));

	}

}