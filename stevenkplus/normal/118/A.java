import java.util.Scanner;

public class A118 {
	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(System.in);
		String line = in.nextLine().toLowerCase();
		line = line.replaceAll("[aeioyu]", "");
		line = line.replaceAll("([a-z])","\\.$1");
		System.out.println(line);
	}
}