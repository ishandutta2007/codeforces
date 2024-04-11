import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.PriorityQueue;

public class B128 {
	static class pair {
		char a;
		int b;

		public pair(int c, char d) {
			b = c;
			a = d;
		}
	}

	public static void main(String[] args) throws Exception {
		BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
		String line = r.readLine();
		int n = line.length(), m = Integer.parseInt(r.readLine()) + n;
		LinkedList<Integer> ar = new LinkedList<Integer>();
		for (int x = 0; x < n; x++) {
			ar.add(x);
		}
		StringBuffer result = new StringBuffer();
		for (int x = 0; true; x++) {
			long[] count = new long[26];
			LinkedList<Integer>[] ll = new LinkedList[26];
			for(int i=0;i<26;i++) {
				ll[i] = new LinkedList<Integer>();
			}
			for (int y : ar) {
				if(y+x>=n) continue;
				int k = line.charAt(y + x) - 'a';
				count[k]+= n - x - y;
				ll[k].add(y);
			}
			long sum = ar.size();
			if (sum >= m)
				break;
			int i;
			for (i = 0; i < count.length; i++) {
				sum += count[i];
				if (sum >= m)
					break;
			}
			if (i == count.length) {
				System.out.println("No such line.");
				return;
			}
			sum -= count[i];
			result.append((char) (i + 'a'));
			m -= sum;
			ar = ll[i];
		}
	
	System.out.println(result.toString());
	}
}