import java.io.*;
import java.util.*;
import java.math.*;

public class Main {
	static final int N = 100011;
	public static void main(String args[]) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt(), k = in.nextInt();
		int[] id = new int[N];
		for(int i = 1; i <= n; i ++)
			id[i] = in.nextInt();
		int ptr = 1;
		while(k > ptr) {
			k -= ptr;
			ptr ++;
		}
		System.out.println(id[k]);
	}
}