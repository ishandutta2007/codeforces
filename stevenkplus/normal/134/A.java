import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class A134 {
	public static void main(String[] args) throws Exception {
		LinkedList<Integer>[] ll = new LinkedList[1001];
		for (int x = 0; x < ll.length; x++) {
			ll[x] = new LinkedList<Integer>();
		}
		BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(r.readLine());
		StringTokenizer st = new StringTokenizer(r.readLine());
		long sum = 0;
		for (int x = 0; x < n; x++) {
			int k;
			ll[k = Integer.parseInt(st.nextToken())].add(x + 1);
			sum += k;
		}
		if (sum % n == 0) {
			int av = (int) (sum / n);
			int count = ll[av].size();
			System.out.println(count);
			String sep = "";
			for (int k : ll[av]) {
				System.out.print(sep + k);
				sep = " ";
			}
			System.out.println();
		} else
			System.out.println("0");
	}
}