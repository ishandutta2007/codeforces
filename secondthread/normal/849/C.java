import java.util.Scanner;

public class ProblemC {

	
	public static long[] cost=new long[1001];
	
	public static void main(String[] args) {
		Scanner s=new Scanner(System.in);
		int n=s.nextInt();
		
		for (int i=0; i<1000; i++) {
			calcCost(i);
		}
		StringBuilder sb=new StringBuilder("z");
		char l='a';
		while (n>0) {
			int k=0;
			while (calcCost(k)<=n) {
				k++;
			}
			k--;
			n-=calcCost(k);
			for (int i=0; i<k; i++) {
				sb.append(""+l);
			}
			l++;
			//System.out.println(n);
		}
		System.out.print(sb);
	}
	
	public static long calcCost(int i) {
		return i*(i-1)/2;
	}

}