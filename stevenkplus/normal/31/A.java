import java.util.Scanner;


public class A031 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int[] ar = new int[n];
		for(int x = 0;x<n;x++) {
			ar[x] = in.nextInt();
		}
		for(int x = 0;x<n;x++ ){
			for(int y = x+1;y<n;y++) {
				int k = ar[x]+ar[y];
				int a =0;
				for(a=0;a<n;a++) {
					if(ar[a]==k) break;
				}
				if(a<n) {
					System.out.printf("%d %d %d\n",a+1,x+1,y+1);
					return;
				}
			}
		}
		System.out.println("-1");
	}
}