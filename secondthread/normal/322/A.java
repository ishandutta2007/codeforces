import java.util.Scanner;

public class Duel1 {

	public static void main(String[] args) {
		Scanner fs=new Scanner(System.in);
		int n=fs.nextInt(), m=fs.nextInt();
		System.out.println(n+m-1);
		for (int i=1; i<=n; i++) {
			System.out.println(i+" "+1);
		}
		for (int j=2; j<=m; j++) {
			System.out.println(1+" "+j);
		}
	}

}