import java.util.Arrays;
import java.util.Scanner;

public class MultiJudge {

	public static void main(String[] args) {
		Scanner s=new Scanner(System.in);
		int n=s.nextInt();
		int hardest=s.nextInt();
		int[] problems=new int[n];
		for (int i=0; i<n; i++) {
			problems[i]=s.nextInt();
		}
		
		Arrays.sort(problems);
		
		int extras=0;
		for (int i=0; i<n; i++) {
			if (problems[i]<hardest) {
				continue;
			}
			while (problems[i]>hardest*2) {
				hardest*=2;
				extras++;
			}
			hardest=Math.max(hardest, problems[i]);
		}
		System.out.println(extras);

	}

}