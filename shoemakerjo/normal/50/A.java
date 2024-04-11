import java.util.Scanner;

public class DominoPiling {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		int M = s.nextInt();
		int N = s.nextInt();
		if(M%2==0) {
			System.out.println(N*M/2);
		}
		else System.out.println(N*(M-1)/2+N/2);

	}

}