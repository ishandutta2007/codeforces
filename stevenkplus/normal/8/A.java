import java.io.BufferedReader;
import java.io.InputStreamReader;

public class A008 {
	public static void main(String[] args) throws Exception {
		BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
		String a = r.readLine();
		String x = r.readLine(), y = r.readLine();
		int ix = a.indexOf(x), iy = a.lastIndexOf(y);
		boolean b = ix >= 0 && iy >= 0 && ix + x.length() <= iy;
		a = new StringBuffer(a).reverse().toString();
		ix = a.indexOf(x);
		iy = a.lastIndexOf(y);
		boolean c = ix >= 0 && iy >= 0 && ix + x.length() <= iy;
		if (b && c) {
			System.out.println("both");
		} else if (b) {
			System.out.println("forward");
		} else if (c) {
			System.out.println("backward");
		} else {
			System.out.println("fantasy");
		}
	}
}