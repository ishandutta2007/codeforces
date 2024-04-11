import java.io.*;
import java.util.*;

public class Main {
	public static void main(String args[]) {
		Scanner in = new Scanner(System.in);
		String s = in.next().toLowerCase();
		for(char c : s.toCharArray()) {
			if(c != 'a' && c != 'i' && c != 'u' && c != 'e' && c != 'o' && c != 'y') {
				System.out.print('.');
				System.out.print(c);
			}
		}
		System.out.println();
	}
}