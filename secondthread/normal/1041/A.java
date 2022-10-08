import java.util.Scanner;

public class A2 {

	public static void main(String[] args) {
		Scanner s=new Scanner(System.in);
		int n=s.nextInt();
		int min=Integer.MAX_VALUE, max=Integer.MIN_VALUE;
		for (int i=0; i<n; i++) {
			int a=s.nextInt();
			min=Math.min(min, a);
			max=Math.max(max, a);
		}
		System.out.println(max-min-n+1);

	}

}