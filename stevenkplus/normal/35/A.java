import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;

public class A035 {
	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(new File("input.txt"));
		int a = in.nextInt();
		for (int x = 0; x < 3; x++) {
			int d = in.nextInt(), e = in.nextInt();
			if (a == d)
				a = e;
			else if (a == e)
				a = d;
		}
		PrintWriter out = new PrintWriter("output.txt");
		out.println(a);
		out.close();
	}
}