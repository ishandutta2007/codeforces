import java.util.Scanner;

public class Compote {

	public static void main(String[] args) {
		Scanner s=new Scanner(System.in);
		int a=s.nextInt(), b=s.nextInt()/2, c=s.nextInt()/4;
		System.out.println(Math.min(a, Math.min(b, c))*7);
		

	}

}