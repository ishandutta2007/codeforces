import java.util.Scanner;

public class B {

	public static void main(String[] args) {
		Scanner s=new Scanner(System.in);
		int size=s.nextInt();
		int filled=s.nextInt();
		if (filled==0||filled==size) {
			System.out.print(0+" ");
		}
		else {
			System.out.print(1+" ");
		}
		int freeSpaces=size-filled;
		System.out.println(Math.min(freeSpaces, 2*filled));

	}

}