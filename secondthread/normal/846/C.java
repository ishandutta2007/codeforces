import java.util.Scanner;

public class C {

	public static void main(String[] args) {
		Scanner s=new Scanner(System.in);
		int n=s.nextInt();
		long[] array=new long[n];
		for (int i=0; i<n; i++) {
			array[i]=s.nextInt();
		}
		long[][] dp=new long[n][4];
		for (int leftIndex=0; leftIndex<n; leftIndex++) {
			for (int movesUsed=0; movesUsed<4; movesUsed++) {
				if (leftIndex==0) {
					if (movesUsed==0) {
						dp[leftIndex][movesUsed]=array[0];
					}
					else {
						dp[leftIndex][movesUsed]=Math.abs(array[0]);
					}
					continue;
				}
				if (movesUsed==0) {
					dp[leftIndex][movesUsed]=dp[leftIndex-1][movesUsed]+array[leftIndex];
					continue;
				}
				if (movesUsed%2==1) {
					dp[leftIndex][movesUsed]=Math.max(dp[leftIndex][movesUsed-1], dp[leftIndex-1][movesUsed]-array[leftIndex]);
				}
				else {
					dp[leftIndex][movesUsed]=Math.max(dp[leftIndex][movesUsed-1], dp[leftIndex-1][movesUsed]+array[leftIndex]);
				}
			}
		}
		
		/*for (int leftIndex=0; leftIndex<n; leftIndex++) {
			for (int i=0; i<4; i++) {
				System.out.print(dp[leftIndex][i]+" ");
			}
			System.out.println();
		}*/
		
		int lastPick=n-1;
		while (lastPick>=0&&dp[lastPick][3]!=dp[lastPick][2]) {
			lastPick--;
		}
		int secondLastPick=lastPick;
		while (secondLastPick>=0&&dp[secondLastPick][2]!=dp[secondLastPick][1]) {
			secondLastPick--;
		}
		int thirdLastPick=secondLastPick;
		while (thirdLastPick>=0&&dp[thirdLastPick][1]!=dp[thirdLastPick][0]) {
			thirdLastPick--;
		}
		lastPick++;
		secondLastPick++;
		thirdLastPick++;
		System.out.println(thirdLastPick+" "+secondLastPick+" "+lastPick);

	}

}