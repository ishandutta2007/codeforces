import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class OddSubsequence {

	public static void main(String[] args) {
		Scanner s=new Scanner(System.in);
		int length=s.nextInt();
		long total=0;
		ArrayList<Integer> odds=new ArrayList<>();
		for (int i=0; i<length; i++) {
			int next=s.nextInt();
			if (next%2==0) {
				total+=Math.max(next, 0);
			}
			else {
				odds.add(next);
			}
		}
		
		Collections.sort(odds);
		total+=odds.remove(odds.size()-1);
		while (odds.size()>=2&&odds.get(odds.size()-1)+odds.get(odds.size()-2)>0) {
			total+=odds.remove(odds.size()-1)+odds.remove(odds.size()-1);
		}
		System.out.println(total);

	}

}