import java.util.HashSet;
import java.util.Scanner;

public class HorshoeOtherHoof {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		HashSet<Integer> ans = new HashSet<Integer>();
		ans.add(s.nextInt());
		ans.add(s.nextInt());
		ans.add(s.nextInt());
		ans.add(s.nextInt());
		System.out.println(4-ans.size());
	}

}