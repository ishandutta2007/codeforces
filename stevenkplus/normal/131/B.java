import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;


public class B131 {
	public static void main(String[] args) throws Exception {
		long[] lol = new long[21];
		BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(r.readLine());
		StringTokenizer t = new StringTokenizer(r.readLine());
		for(int x=0;x<n;x++) {
			int k = Integer.parseInt(t.nextToken());
			lol[k+10]++;
		}
		long sum = 0;
		for(int x=1;x<=10;x++) {
			sum+=lol[-x+10]*lol[x+10];
		}
		sum+=lol[10]*(lol[10]-1)/2;
		System.out.println(sum);
	}
}