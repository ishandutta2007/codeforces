import java.util.Scanner;


public class A121 {
	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(System.in);
		String next = in.next();
		int length = next.length();
		long start = Long.parseLong(next);
		next = in.next();
		int length2=next.length();
		long end = Long.parseLong(next);
		long lim = 1<<(length2+2);
		long add = 1<<length;
		long sum = 0;
		for(long x = add;x<lim;x++) {
			long l = Long.parseLong(Long.toBinaryString(x).substring(1).replaceAll("0","4").replaceAll("1","7"));
			if(l<start) continue;
			long times = l-start+1;
			if(l>end) times =end-start+1;
			sum+=times*l;
			if(l>end) break;
			start = l+1;
		}
		System.out.println(sum);
	}
}