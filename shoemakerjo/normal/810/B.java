import java.io.*;
import java.util.*;

public class SummerSellOff {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub\
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(bf.readLine());
		long n = Integer.parseInt(st.nextToken());
		long f = Integer.parseInt(st.nextToken());
		long sum = 0;
		
		ArrayList<Long> ben = new ArrayList<Long>();
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(bf.readLine());
			long k = Long.parseLong(st.nextToken());
			long l = Long.parseLong(st.nextToken());
			long add = Math.min(l, k);
			sum+=add;
			long cben = Math.min(k, l-k);
			cben = Math.max(cben, 0);
			ben.add(cben);
			
		}
		Collections.sort(ben);
		Collections.reverse(ben);
		for (int i = 0; i < f; i++) {
			sum += ben.get(i);
		}
		System.out.println(sum);

	}

}