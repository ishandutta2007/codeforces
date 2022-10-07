import java.io.BufferedReader;
import java.io.InputStreamReader;


public class B050 {
	public static void main(String[] args) throws Exception {
		BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
		long[] count = new long[9001];
		String s = r.readLine();
		for(int x = 0;x<s.length();x++) {
			count[s.charAt(x)]++;
		}
		long sum = 0;
		for(long x:count) {
			sum+=x*x;
		}
		System.out.println(sum);
	}
}