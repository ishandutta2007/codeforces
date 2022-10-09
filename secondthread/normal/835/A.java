import java.util.Scanner;

public class KeyRaces {

	public static void main(String[] args) {
		Scanner s=new Scanner(System.in);
		int length=s.nextInt();
		int firstSpeed=s.nextInt();
		int secondSpeed=s.nextInt();
		int firstPing=s.nextInt(), secondPing=s.nextInt();

		int firstTime=2*firstPing+length*firstSpeed;
		int secondTime=2*secondPing+length*secondSpeed;
		if (firstTime<secondTime) {
			System.out.println("First");
		}
		if (secondTime<firstTime) {
			System.out.println("Second");
		}
		if (firstTime==secondTime) {
			System.out.println("Friendship");
		}
	}

}