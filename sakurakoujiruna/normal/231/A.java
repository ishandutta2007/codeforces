import java.io.*;
import java.util.*;

public class Main {
	public static void main(String args[]) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int ans = 0;
		while(n -- > 0) {
			int cnt = 0;
			for(int i = 0; i < 3; i ++) {
				int x = in.nextInt();
				cnt += x;
			}
			if(cnt >= 2) ans ++;
		}
		System.out.println(ans);
	}
}