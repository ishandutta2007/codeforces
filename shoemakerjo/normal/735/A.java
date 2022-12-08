import java.io.File;
import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.Scanner;

public class A {
	
	public static boolean[] visited;
	public static char[] stuff;
	public static int n,k;
	public static boolean found;

	public static void main(String[] args) throws FileNotFoundException {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		n = s.nextInt(); //length of array
		k  =s.nextInt();
		stuff = new char[n];
		s.nextLine();
		String line = s.next();
		int index = 0;
		for (int i = 0; i < line.length(); i++) {
			char c = line.charAt(i);
			if (c=='G') index = i;
			stuff[i] = c;
		}
		visited = new boolean[n];
		found = false;
		loop(index);
	
		if (found) System.out.println("YES");
		else System.out.println("NO");

	}
	
	public static void loop(int spot) {
		if (visited[spot]) return;
		visited[spot] = true;
		char c = stuff[spot];
		if (c == '#') return;
		if (c== 'T') {
			found = true;
			return;
		}
		if (spot - k>= 0) loop(spot-k);
		if (spot + k < n) loop(spot + k);
	}

}