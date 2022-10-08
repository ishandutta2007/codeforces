import java.util.Scanner;
/*

 */
public class C2 {

	static int happyCount=0;
	static long[] facts;
	static long m;
	
	public static void main(String[] args) {
		Scanner fs=new Scanner(System.in);
		int n=fs.nextInt();
		m=fs.nextLong();
		precomp();
		long total=0;
		for (int i=1; i<=n; i++) {
			int things=n-i+1;
			long orderings=facts[i];
			long otherOrderings=facts[n-i];
			int waysToPlace=(n-i+1);
			total+=things*orderings%m*waysToPlace%m*otherOrderings%m;
			total%=m;
		}
		System.out.println(total);
	}
	
	static void precomp() {
		facts=new long[1_000_001];
		facts[0]=1;
		for (int i=1; i<facts.length; i++)
			facts[i]=facts[i-1]*i%m;
	}
	
	
	static void allPerms(int[] cur, boolean[] used, int index) {
		int n=cur.length;
		if (index==n) {
			for (int i=0; i<n; i++) {
				int min=cur[i], max=cur[i];
				for (int j=i; j<n; j++) {
					min=Math.min(cur[j], min);
					max=Math.max(cur[j], max);
					if (max-min == j-i) {
						happyCount++;
					}
				}
			}
			return;
		}
		for (int toPlace=0; toPlace<n; toPlace++) {
			if (used[toPlace]) continue;
			cur[index]=toPlace;
			used[toPlace]=true;
			allPerms(cur, used, index+1);
			used[toPlace]=false;
		}
	}
	
}