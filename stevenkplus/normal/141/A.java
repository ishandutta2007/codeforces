import java.util.Arrays;
import java.util.Scanner;


public class A141 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		char[] a = (in.next()+in.next()).toCharArray(),b=in.next().toCharArray();
		Arrays.sort(a);
		Arrays.sort(b);
		System.out.println(Arrays.equals(a,b)?"YES":"NO");
	}
}