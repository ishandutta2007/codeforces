import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		StringBuilder a = new StringBuilder(in.next());
		int k = in.nextInt();
		
		for (int i = 0; i < a.length(); i++) {
			int j = -1;
			char c = 0;
			for (int _j = i; (_j <= i + k) && (_j < a.length()); _j++) {
				if (a.charAt(_j) > c) {
					c = a.charAt(_j);
					j = _j;
				}
			}
			a.deleteCharAt(j);
			a.insert(i, c);
			k -= (j - i);
		}
		
		System.out.println(a);
	}
}