import java.util.Scanner;


public class A009 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int a = in.nextInt(),b=in.nextInt();
		String[] arr = {"0/1","1/6","1/3","1/2","2/3","5/6","1/1"};
		int max = a>b?a:b;
		int chance = 7-max;
		System.out.println(arr[chance]);
	}
}