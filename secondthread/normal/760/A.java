import java.util.Scanner;

public class Calendar {
	public final static int[] days={0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, };

	public static void main(String[] args) {
		Scanner s=new Scanner(System.in);
		int n=days[s.nextInt()]+s.nextInt()-1;
		if (n%7!=0) {
			System.out.println(n/7+1);
		}
		else {
			System.out.println(n/7);
		}
	}

}