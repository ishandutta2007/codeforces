import java.util.Scanner;

public class ProblemA {

	public static void main(String[] args) {
		Scanner s=new Scanner(System.in);
		String[] pos={"^", ">", "v", "<"};
		String[] line=s.nextLine().split(" ");
		int seconds=s.nextInt();
		int initial=indexOf(line[0], pos);
		int finalPos=indexOf(line[1], pos);
		if (seconds%2==0) {
			System.out.println("undefined");
			return;
		}
		if (((finalPos-initial)%4+4)%4==seconds%4) {
			System.out.println("cw");
		}
		else if (((-finalPos+initial)%4+4)%4==seconds%4) {
			System.out.println("ccw");
		}
		

	}

	public static int indexOf(String s, String[] a) {
		for (int i=0; i<4; i++) {
			if (a[i].equals(s))
				return i;
		}
		return -1;
	}
}