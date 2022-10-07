import java.util.Scanner;


public class B069 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n= in.nextInt(),m=in.nextInt();
		int[] times = new int[n];
		int[] prof = new int[n];
		for(int x = 0;x<m;x++) {
			int a = in.nextInt()-1,b=in.nextInt(),t=in.nextInt(),c=in.nextInt();
			for(int y = a;y<b;y++) {
				if(times[y]>t || times[y]==0) {
					times[y] = t;
					prof[y] = c;
				}
			}
		}
		int sum = 0;
		for(int x:prof) {
			sum+=x;
		}
		System.out.println(sum);
	
	}
}