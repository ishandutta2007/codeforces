import java.util.ArrayList;
import java.util.Scanner;

public class KFactors {

	public static void main(String[] args) {
		Scanner s=new Scanner(System.in);
		int n=s.nextInt();
		int k=s.nextInt();
		ArrayList<Integer> factors=new ArrayList<>();
		for (int i=2; i<=n; i++) {
			if (n%i==0) {
				factors.add(i);
				n/=i;
				i--;
			}
		}

		if (factors.size()<k) {
			System.out.println(-1);
		}
		else {
			while (factors.size()>k) {
				factors.add(factors.remove(factors.size()-1)*factors.remove(factors.size()-1));
			}
			for (int i:factors) {
				System.out.print(i+" ");
			}
		}
	}

}