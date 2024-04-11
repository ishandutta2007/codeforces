import java.util.Scanner;

public class BeautifulMatrix {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		for (int i = 1; i <= 5; i++) {
			for (int j  = 1; j <= 5; j++) {
				int cur = s.nextInt();
				if (cur ==1) {
					System.out.println(Math.abs(3-i)+Math.abs(3-j));
				}
			}
		}

	}

}