import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class B061 {
	public static void main(String[] args) throws Exception {
		BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
		String[] ar = new String[3];
		for (int x = 0; x < 3; x++) {
			ar[x] = f(r.readLine());
		}
		int n = Integer.parseInt(r.readLine());
		ArrayList<String> pos = new ArrayList<String>(6);
		for (int x = 0; x < 3; x++) {
			for (int y = 0; y < 3; y++) {
				if (x == y)
					continue;
				for (int z = 0; z < 3; z++) {
					if (x == z || y == z)
						continue;
					pos.add(ar[x] + ar[y] + ar[z]);
				}
			}
		}

		for (int x = 0; x < n; x++) {
			String line = f(r.readLine());
			if (pos.contains(line))
				System.out.println("ACC");
			else
				System.out.println("WA");
		}
	}

	static String f(String a) {
		return a.toLowerCase().replaceAll("[_;-]", "");
	}
}