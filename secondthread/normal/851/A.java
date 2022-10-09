import java.util.Scanner;

public class A {

	public static void main(String[] args) {
		Scanner s=new Scanner(System.in);
		int n=s.nextInt();
		int k=s.nextInt();
		int t=s.nextInt();
		int fromStart=Math.max(0, Math.min(t, n+k-t));
		System.out.println(Math.min(fromStart, k));

	}

}