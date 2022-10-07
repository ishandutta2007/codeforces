import java.util.Hashtable;
import java.util.Scanner;

public class A094 {
	public static void main(String[] args) throws Exception {
		Hashtable<String, Integer> ht = new Hashtable<String, Integer>();
		Scanner in = new Scanner(System.in);
		String l = in.nextLine();
		for (int x = 0; x < 10; x++) {
			ht.put(in.nextLine(), x);
		}
		for (int x = 0; x < 80; x += 10) {
			System.out.print(ht.get(l.substring(x, x + 10)));
		}
		System.out.println();
	}
}