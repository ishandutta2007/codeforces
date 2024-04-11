import java.util.Scanner;


public class B066 {
	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int[] nums = new int[n];
		for(int x =0;x<n;x++) {
			nums[x] = in.nextInt();
		}
		int start = 0;
		int cons = 0;
		int prev = -1;
		int max = 0;
		boolean up = true;
		for(int x=0;x<=n;x++) {
			int num =(x==n)? 1 : nums[x];
			if(x<n&&num==prev) continue;
			if(x==n||up^num>prev) {
				if(x==n||!up) {
					int length = x - start;
					start = cons;
					if(length>max) max = length;
				}
				up = !up;
			}
			prev = num;
			cons = x;
		}
		System.out.println(max);
	}
}