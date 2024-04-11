import java.io.File;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Scanner;

public class A120 {
	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(new File("input.txt"));
		PrintWriter out = new PrintWriter(new FileWriter("output.txt"));
		out.println((in.next().charAt(0) == 'f' ^ in.nextInt() == 1) ? "R"
				: "L");
		out.close();
	}
}