import java.util.Arrays;
import java.util.Scanner;

public class B {

	public static void main(String[] args) {
		Scanner fs=new Scanner(System.in);
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			int[] c=new int[2];
			char[] a=fs.next().toCharArray();
			for (char cc:a) c[cc-'0']++;
			if (Math.min(c[0], c[1])==0) {
				System.out.println(a);
			}
			else {
				for (int i=0; i<a.length; i++) {
					System.out.print(10);
				}
				System.out.println();
			}
		}
	}

}