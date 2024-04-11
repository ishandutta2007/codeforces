import java.util.HashMap;
import java.util.Scanner;

public class C {

	
	public static void main(String[] args) {
		HashMap<Integer, Integer> map=new HashMap<>();
		Scanner s=new Scanner(System.in);
		int n=s.nextInt();
		for (int i=0; i<n; i++) {
			int next=s.nextInt();
			if (map.containsKey(next))
				map.put(next, map.get(next)+1);
			else
				map.put(next, 1);
		}
		int max=0;
		for (int i:map.values())
			max=Math.max(max, i);
		System.out.println(max);

	}

}