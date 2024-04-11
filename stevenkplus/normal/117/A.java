import java.util.Scanner;


public class A117 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt(),m=in.nextInt();
		for(int x = 0;x<n;x++) {
			int a = in.nextInt(),b=in.nextInt(),t=in.nextInt();
			int sum = t;
			sum+=blah(t,a,m);
			sum+=blah(sum,b,m);
			if(a==b) sum = t;
			System.out.println(sum);
		}
	}
	static int blah(int time,int floor,int tot) {
		int k = time%(2*tot-2);
		if(k<tot) {
			int cur = k+1;
			int diff = floor-cur;
			if(diff<0) {
				int t = tot-cur;
				return t*2-diff;
			}
			else return diff;
		}
		else {
			int cur = 2*tot-1-k;
			int diff = cur - floor;
			if(diff<0) {
				return cur+floor-2;
			}
			else return diff;
		}
	}
}