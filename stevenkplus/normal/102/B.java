import java.io.BufferedReader;
import java.io.InputStreamReader;

public class B102 {
	public static void main(String[] ags) throws Exception {
		System.out.println(ans());
	}

	static int ans() throws Exception {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		String line = in.readLine();
		if (line.length() == 1)
			return 0;
		int sum = 0;
		for (int x = 0; x < line.length(); x++) {
			sum += line.charAt(x) - '0';
		}
		int count = 1;
		while (sum >= 10) {
			int t = 0;
			for (int p : ("" + sum).toCharArray())
				t += p - '0';
			sum=t;
			count++;
		}
		return count;
	}
}