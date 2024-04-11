import java.util.Arrays;
import java.util.Scanner;

public class C141 {
	static class pair implements Comparable<pair> {
		String s;
		int see;
		public int compareTo(pair o) {
			return see - o.see;
		}

		public pair(String a, int b) {
			s = a;
			see = b;
		}
	}

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		pair[] p = new pair[n];
		for (int x = 0; x < n; x++) {
			p[x] = new pair(in.next(), in.nextInt());
		}
		Arrays.sort(p);
		for (int x = 0; x < n; x++) {
			if(p[x].see>x) {
				System.out.println("-1"); return;
			}
		}
		int[] nums = new int[n];
		for(int x = 0;x<n;x++) {
			int k = x-p[x].see;
			nums[x] = k;
			for(int i = 0;i<x;i++) {
				if(nums[i]>=k) nums[i]++;
			}
		}
		for(int x = 0;x<n;x++) {
			System.out.println(p[x].s+" "+(nums[x]+1));
		}
	}
}