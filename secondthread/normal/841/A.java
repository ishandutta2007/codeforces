import java.util.Scanner;

public class Balloons {

	public static void main(String[] args) {
		Scanner s=new Scanner(System.in);
		s.nextInt();
		int friends=s.nextInt();
		s.nextLine();
		String line=s.nextLine();
		String alpha="abcdefghijklmnopqrstuvwxyz";
		int[] countingSort=new int[26];
		for (int i=0; i<line.length(); i++) {
			countingSort[alpha.indexOf(line.charAt(i))]++;
		}
		for (int i=0; i<26; i++) {
			if (countingSort[i]>friends) {
				System.out.println("NO");
				return;
			}
		}
		System.out.println("YES");
		return;

	}

}