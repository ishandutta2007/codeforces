import java.util.Scanner;

public class DoubleCola {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		int n = s.nextInt();
		String[] people = new String[5];
		people[0] = "Sheldon";
		people[1] = "Leonard";
		people[2] = "Penny";
		people[3] = "Rajesh";
		people[4] = "Howard";
		int nums = 1;
		while (n > 0) {
			for (int i = 0; i < 5; i++) {
				n-=nums;
				if (n <= 0) {
					System.out.println(people[i]);
					break;
				}
			}
			nums*=2;
		}

	}

}