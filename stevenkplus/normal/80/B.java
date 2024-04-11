import java.util.Scanner;


public class B080 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		String[] l = in.nextLine().split(":");
		int a = Integer.parseInt(l[0]),b=Integer.parseInt(l[1]);
		a%=12;
		double ang1 = a*30+b*(.5);
		double ang2 = b*6;
		System.out.printf("%f %f\n",ang1,ang2);
	}
}