import java.util.Scanner;

public class A125 {
	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(System.in);
		int c = in.nextInt();
		int i = (int) (c / 3. + .5);
		int f = i/12,inn = i%12;
		System.out.printf("%d %d\n",f,inn);
	}
}