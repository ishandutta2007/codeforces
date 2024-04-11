import java.io.BufferedReader;
import java.io.InputStreamReader;

public class B121 {
	public static void main(String[] args) throws Exception {
		BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
		String[] s = r.readLine().split(" ");
		char[] line = r.readLine().toCharArray();
		int n = line.length, k = Integer.parseInt(s[1]);
		int i = 0;
		for (int x = 0; i < k && x + 1 < n;) {
			if (line[x] == '4' && line[x + 1] == '7') {
				if (x % 2 == 0) {
					line[x + 1] = '4';
					if (x + 2 < n) {
						if (line[x + 2] == '7') {
							i += 2 * ((k - i-1) / 2);
						}
					}
					x++;
				} else {
					line[x] = '7';
					if(x>0)
						x--;
				}
				i++;
			} else
				x++;
		}
		System.out.println(new String(line));

	}
}