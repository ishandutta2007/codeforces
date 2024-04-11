import java.util.Scanner;

public class A057 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt(), x0 = in.nextInt(), y0 = in.nextInt(), x1 = in
				.nextInt(), y1 = in.nextInt();
		int dist = 0;
		int[] px = { 0, n, n, 0 }, py = { 0, 0, n, n };
		int i = 0;
		if(x0==0) i = 0;
		else if (y0==0) i = 1;
		else if (x0==n) i = 2;
		else i = 3;
		while (!(x0 == x1 && (x0 == 0 || x0 == n) || (y0 == y1 && (y1 == 0 || y1 == n))))
		{
			int dx = px[i] - x0;
			if (dx < 0)
				dx = -dx;
			int dy = py[i] - y0;
			if (dy < 0)
				dy = -dy;
			dist += dx + dy;
			x0 = px[i];
			y0 = py[i];
			i++;
			i%=4;
		}
		int dx = x1 - x0;
		if (dx < 0)
			dx = -dx;
		int dy = y1 - y0;
		if (dy < 0)
			dy = -dy;
		dist += dx + dy;
		int o = 4 * n - dist;
		System.out.println(o < dist ? o : dist);
	}
}