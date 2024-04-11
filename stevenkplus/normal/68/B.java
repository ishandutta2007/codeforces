import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;

public class B068 {
	public static void main(String[] args) throws Exception {
		BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(r.readLine());
		int n = Integer.parseInt(st.nextToken()), k = Integer.parseInt(st
				.nextToken());
		double kk = k / 100.;
		Double[] ar = new Double[n];
		st = new StringTokenizer(r.readLine());
		double tot = 0;
		for (int x = 0; x < n; x++) {
			tot += ar[x] = Double.parseDouble(st.nextToken());
		}
		double mean = tot / n;
		Arrays.sort(ar, new Comparator<Double>() {
			public int compare(Double a, Double b) {
				return -Double.compare(a, b);
			}
		});
		double max = 0;
		double sum = 0;
		for (int x = 0; x < n; x++) {
			sum+=ar[x];
			double lol = (sum * kk - mean * n) / (kk*(x+1) - n);
			if(ar[x]<lol||(x+1<n&&ar[x+1]>lol)) continue;
			System.out.println(lol);
			break;
		}
	}
}