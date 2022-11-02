import java.io.*;
import java.util.*;
import java.math.*;

public class Main {
	static final int N = 500011;
	public static void main (String args[]) throws Exception {
		Scanner in = new Scanner(new BufferedInputStream(System.in));
		int n = in.nextInt();
		int m = in.nextInt();
		int p = in.nextInt();
		String s = " " + in.next();

		int[] b = new int[N];
		Stack <Integer> stack = new Stack <Integer>();
		for(int i = 1; i <= n; i ++) {
			if(s.charAt(i) == '(')
				stack.push(i);
			else {
				b[stack.peek()] = i;
				b[i] = stack.peek();
				stack.pop();
			}
		}
		stack = null;
		int[] l_link = new int[N];
		int[] r_link = new int[N];
		for(int i = 1; i <= n + 1; i ++)
			l_link[i] = i - 1;
		for(int i = 0; i <= n; i ++)
			r_link[i] = i + 1;

		String ops = in.next();
		for(char op : ops.toCharArray()) {
			if(op == 'L') p = l_link[p];
			else if(op == 'R') p = r_link[p];
			else {
				int l = l_link[Math.min(p, b[p])];
				int r = r_link[Math.max(p, b[p])];
				r_link[l] = r; l_link[r] = l;
				p = r;
				if(p == n + 1) p = l_link[p];
			}
		}
		ops = null;
		List <Character> ans = new ArrayList <Character>();
		for(int i = r_link[0]; i != n + 1; i = r_link[i]) {
			// if(i >= r_link[i]) throw new Exception();
			ans.add(s.charAt(i));
		}
		StringBuilder as = new StringBuilder();
		for(Character c : ans) as.append(c);
		ans = null;
		System.out.println(as.toString());
	}
}