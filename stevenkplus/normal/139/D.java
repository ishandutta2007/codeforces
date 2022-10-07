import java.io.BufferedReader;
import java.io.InputStreamReader;

public class D139 {
	public static void main(String[] args) throws Exception {
		BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
		String line = r.readLine();
		int[] counts = new int[10];
		for (char c : line.toCharArray()) {
			counts[c - '0']++;
		}
		String best1 = null, best2 = null;
		int max = -1;
		for (int x = 1; x < 10; x++) {
			StringBuffer strb1 = new StringBuffer(), strb2 = new StringBuffer();
			int[] clone1 = counts.clone(), clone2 = counts.clone();
			int zeros = 0;
			if (counts[x] > 0 && counts[10 - x] > 0) {
				zeros++;
				clone1[x]--;
				clone2[10 - x]--;
				strb1.append(x);
				strb2.append(10 - x);

				for (int i = 0; i < 10; i++) {
					int min = clone1[i];
					int b = clone2[9 - i];
					if (min > b)
						min = b;
					clone1[i] -= min;
					clone2[9 - i] -= min;
					for (int j = 0; j < min; j++) {
						strb1.append(i);
						strb2.append(9 - i);
					}
					zeros += min;
				}
			}
			strb1.reverse();
			strb2.reverse();
			int min = clone1[0], b = clone2[0];
			if (min > b)
				min = b;
			zeros += min;
			clone1[0] -= min;
			clone2[0] -= min;
			for (int i = 0; i < min; i++) {
				strb1.append(0);
				strb2.append(0);
			}
			strb1.reverse();
			strb2.reverse();
			for (int y = 0; y < 10; y++) {
				for (int i = 0; i < clone1[y]; i++) {
					strb1.append(y);
				}
				for (int i = 0; i < clone2[y]; i++) {
					strb2.append(y);
				}
			}
			if (zeros > max) {
				max = zeros;
				best1 = strb1.reverse().toString();
				best2 = strb2.reverse().toString();
			}
		}
		System.out.println(best1);
		System.out.println(best2);
	}
}