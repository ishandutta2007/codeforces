import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;


public class B120 {
	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(new File("input.txt"));
		PrintWriter out = new PrintWriter("output.txt");
		int n = in.nextInt();
		int k = in.nextInt()-1;
		int[] ar = new int[n];
		for(int x = 0;x<n;x++) {
			ar[x] = in.nextInt();
		}
		while(ar[k]==0) {
			k++;
			k%=n;
		}
		out.println(k+1);
		out.close();
	}
}