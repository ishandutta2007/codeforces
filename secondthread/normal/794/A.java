import java.util.Scanner;

public class Safes {

	public static void main(String[] args) {
		Scanner s=new Scanner(System.in);
		int myPosition=s.nextInt();
		int left=s.nextInt();
		int right=s.nextInt();
		int n=s.nextInt();
		int counter=0;
		for (int i=0; i<n; i++) {
			int a=s.nextInt();
			if (left<a&&a<right) {
				counter++;
			}
		}
		System.out.println(counter);

	}

}