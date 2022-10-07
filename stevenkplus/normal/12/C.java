import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Hashtable;
import java.util.Scanner;

public class C012 {
	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt(), k = in.nextInt();
		int[] ar = new int[n];
		for (int x = 0; x < n; x++) {
			ar[x] = in.nextInt();
		}
		Hashtable<String, Integer> ht = new Hashtable<String, Integer>();
		ArrayList<Integer> counts = new ArrayList<Integer>(k);
		int c = 0;
		for (int x = 0; x < k; x++) {
			String fruit = in.next();
			if (!ht.containsKey(fruit)) {
				ht.put(fruit, c++);
				counts.add(0);
			}
			int index = ht.get(fruit);
			counts.set(index, counts.get(index) + 1);
		}
		Arrays.sort(ar);
		Collections.sort(counts);
		int min = 0;
		for (int x = 0; x < counts.size(); x++) {
			min += counts.get(c-x-1) * ar[x];
		}
		int max = 0;
		for (int x = 0; x < counts.size(); x++) {
			max += counts.get(c-x-1) * ar[n-x-1];
		}
		System.out.printf("%d %d\n",min,max);
	}
}