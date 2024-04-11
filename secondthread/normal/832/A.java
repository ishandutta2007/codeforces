import java.util.Scanner;

public class ProblemA {

	public static void main(String[] args) {
		Scanner s=new Scanner(System.in);
		 long n=s.nextLong();
		 long k=s.nextLong();
		 if ((n/k)%2==1) {
			 System.out.println("YES");
		 }
		 else {
			 System.out.println("NO");
		 }
	}

}