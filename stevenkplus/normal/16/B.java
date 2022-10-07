import java.util.Arrays;
import java.util.Scanner;


public class B016 {
	static class pair implements Comparable<pair>{
		int a, b;
		public pair(int c,int d) {
			b = c;
			a = d;
		}
		public int compareTo(pair o) {
			return o.a-a;
		}
	}
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt(),m=in.nextInt();
		pair[] pp = new pair[m];
		
		for(int x = 0;x<m;x++) {
			pair p = new pair(in.nextInt(),in.nextInt());
			pp[x] = p;
		}
		Arrays.sort(pp);
		long sum = 0;
		for(pair p:pp) {
			if(n>0) {
				int s = p.b;
				if(s>n) s =n;
				n-=s;
				sum+=s*p.a;
			}
		}
		System.out.println(sum);
	}
}