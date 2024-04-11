import java.util.Scanner;

public class ProblemA {

	public static void main(String[] args) {
		Scanner s=new Scanner(System.in);
		int n=s.nextInt();
		int m=s.nextInt();
		int z=s.nextInt();
		int counter=0;
		for (int i=1; i<=z; i++) {
			if (i%n==0&&i%m==0) {
				counter++;
			}
		}
		System.out.println(counter);
	}

}