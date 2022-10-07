import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.StringTokenizer;

public class B098 {
	public static void main(String[] args) throws Exception {
		BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer token;
		int n = Integer.parseInt(r.readLine());
		token = new StringTokenizer(r.readLine());
		boolean[] taken = new boolean[n];
		int extra = 0;
		for(int x = 0;x<n;x++) {
			int k = Integer.parseInt(token.nextToken()); 
			if(k>n||taken[k-1]) {
				extra++;
			}
			else taken[k-1] = true;
		}
		System.out.println(extra);
	}
}