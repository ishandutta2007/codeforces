import java.util.Scanner;

public class Tram {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		int n = s.nextInt();
		int total = 0;
		int max = 0;
		for (int i = 0; i < n; i++) {
			total -= s.nextInt();
			total += s.nextInt();
			max = Math.max(total, max);
		}
		System.out.println(max);

	}

}