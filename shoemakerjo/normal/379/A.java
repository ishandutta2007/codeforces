import java.util.Scanner;

public class NewYearCandles {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s =  new Scanner(System.in);
		int a = s.nextInt();
		int b = s.nextInt();
		int ans = 0;
		int burned = 0;
		boolean first = true;
		int prev = -1;
		while (ans!=prev) {
			first = false;
			prev = ans;
			ans+=a;
			burned+=a;
			a = burned/b;
			burned -= burned/b*b;
//			System.out.println(a + " " + burned);
			
		}
		System.out.println(ans);

	}

}