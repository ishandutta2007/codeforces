import java.util.Scanner;

public class A122 {
	public static void main(String[] args) throws Exception {
		System.out.println(b() ? "YES" : "NO");
	}

	static boolean b() throws Exception {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		for (int x = 2; x < 32; x++) {
			int k = Integer.parseInt(Integer.toBinaryString(x).substring(1).replaceAll("0", "4")
					.replaceAll("1", "7"));
			if (n % k == 0)
				return true;
		}
		return false;
	}
}