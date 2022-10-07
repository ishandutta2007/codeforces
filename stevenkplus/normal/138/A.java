import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Hashtable;
import java.util.StringTokenizer;

public class C139 {
	public static void main(String[] args) throws Exception {

		System.out.println(res());
	}

	public static String res() throws Exception {
		BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(r.readLine());
		int n = Integer.parseInt(st.nextToken()), k = Integer.parseInt(st
				.nextToken());
		String prev = null;
		for (int x = 0; x < n; x++) {
			Hashtable<String, Character> ht = new Hashtable<String, Character>();
			char[] ar = new char[4];
			char p = 'a';
			for (int i = 0; i < 4; i++) {
				String line = r.readLine();
				int dex = line.length() - 1;
				int count = 0;
				while (count != k) {
					if (dex == -1) {
						return "NO";
					}
					if (line.substring(dex, dex + 1).matches("[aeiou]")) {
						count++;
					}
					dex--;
				}
				String suffix = line.substring(dex + 1);
				if (ht.containsKey(suffix)) {
					ar[i] = ht.get(suffix);
				} else {
					ht.put(suffix, p++);
					ar[i] = ht.get(suffix);
				}
			}
			String pattern = new String(ar);
			if (pattern.equals("aaaa"))
				continue;
			else if (prev == null) {
				prev = pattern;
			} else if (!prev.equals(pattern)) {
				return "NO";
			}
		}
		if (prev == null) {
			return "aaaa";
		}
		if (prev.equals("aabb") || prev.equals("abab") || prev.equals("abba")) {
			return prev;
		}
		return "NO";
	}
}