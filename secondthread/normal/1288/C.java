import java.util.Arrays;
import java.util.Scanner;
public class C {
	
	static long mod=1_000_000_007;

	public static void main(String[] args) {
		Scanner fs=new Scanner(System.in);
		int n=fs.nextInt(), m=fs.nextInt();
		long[] waysOfGap=new long[n];
		Arrays.fill(waysOfGap, 1);
		for (int times=0; times<m; times++) {
			long[] newWays=new long[n+1];
			for (int newGap=0; newGap<n; newGap++) {
				for (int oldGap=0; oldGap<=newGap; oldGap++) {
					newWays[newGap]=(waysOfGap[oldGap]*(newGap-oldGap+1) + newWays[newGap])%mod;
				}
			}
			waysOfGap=newWays;
		}
		System.out.println(waysOfGap[n-1]);
		
	}
	
	
}