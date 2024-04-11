import java.util.Scanner;

public class B063 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int m = in.nextInt();
		int[] ar = new int[m];
		for (int x = 0; x < n; x++) {
			ar[in.nextInt()-1]++;
		}
		int x = 0;
		for(x= 0;!done(ar);x++) {
			for(int i = m-2;i>=0;i--) {
				if(ar[i]>0) {
					ar[i]--;
					ar[i+1]++;
				}
			}
		}
		System.out.println(x);
	}

	static boolean done(int[] ar) {
		for (int x = 0; x < ar.length - 1; x++)
			if (ar[x] != 0)
				return false;
		return true;
	}
}