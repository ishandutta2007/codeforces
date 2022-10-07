import java.util.Scanner;

public class C041 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		String line = in.nextLine();
		int index = line.indexOf("at", 1);
		String newl = line.substring(0, index) + "@"
				+ line.substring(index + 2);
		String substr = newl.substring(1, newl.length() - 1);
		substr = substr.replaceAll("dot", ".");
		String fin = newl.charAt(0) + substr
				+ newl.charAt(newl.length() - 1);
		System.out.println(fin);
	}
}