import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Hashtable;
import java.util.StringTokenizer;

public class D128 {
	public static void main(String[] args) throws Exception {
		System.out.println(b() ? "YES" : "NO");
	}

	static boolean b() throws Exception {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		Hashtable<Integer, Integer> ht = new Hashtable<Integer, Integer>();
		int n = Integer.parseInt(in.readLine());
		StringTokenizer st = new StringTokenizer(in.readLine());

		if (n % 2 == 1)
			return false;
		int min = Integer.MAX_VALUE;
		int max = 0;
		for (int x = 0; x < n; x++) {
			Integer next = Integer.parseInt(st.nextToken());
			if (ht.containsKey(next)) {
				ht.put(next, ht.get(next) + 1);
			} else
				ht.put(next, 1);
			if (next < min)
				min = next;
			if (next > max)
				max = next;
		}
		try {
			for (int x = min; x < max; x++) {
				int k = ht.get(x);
				int p = ht.get(x + 1);
				if(k<=0) return false;
				ht.put(x+1,p-k);
			}
			return ht.get(max)==0;
		} catch (Exception e) {
			return false;
		}
	}
}