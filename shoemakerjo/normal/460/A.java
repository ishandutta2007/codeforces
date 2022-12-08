import java.util.Scanner;

public class VasyaSocks {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		int n = s.nextInt();
		int m = s.nextInt();
		int day = 1;
		while (n > 0) {
			n--;
			if (day%m==0) n++;
			day++;
		}
		System.out.println(day-1);

	}

}