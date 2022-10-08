import java.util.Scanner;
import java.util.TreeSet;

public class B {

	public static void main(String[] args) {
		Scanner fs=new Scanner(System.in);
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			TreeSet<Integer> s=new TreeSet<>();
			int n=fs.nextInt(), k=fs.nextInt();
			for (int i=0; i<n; i++) s.add(fs.nextInt());
			if (s.size()>k) {
				System.out.println(-1);
			}
			else {
				System.out.println(n*k);
				for (int t=0; t<n; t++) {
					for (int i:s) {
						System.out.print(i+" ");
					}
					for (int i=0; i<k-s.size(); i++) System.out.print("1 ");
				}
				System.out.println();
			}
		}
	}

}