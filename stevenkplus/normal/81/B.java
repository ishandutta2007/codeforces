import java.util.Scanner;

public class B081 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		String line = in.nextLine();
		line = line.replaceAll("\\s*(\\d+)\\s+(?=\\d)","$1 ");
		line = line.replaceAll("\\s*\\.{3}\\s*"," ...");
		line = line.replaceAll("\\s*,\\s*",", ");
		System.out.println(line.trim());
		
	}
}