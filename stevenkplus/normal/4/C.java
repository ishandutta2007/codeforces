import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Hashtable;

public class C004 {
	public static void main(String[] args) throws Exception {
		Hashtable<String, Integer> ht = new Hashtable<String, Integer>();
		BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(r.readLine());
		for (int x = 0; x < n; x++) {
			String line = r.readLine();
			if (ht.containsKey(line)) {
				int num = ht.get(line) + 1;
				ht.put(line, num);
				System.out.println(line + num);
			} else {
				ht.put(line, 0);
				System.out.println("OK");
			}
		}
	}
}