import java.util.*;

public class R280D2TaskDVanyaAndComputerGame {

	public static void main(String[] args)
	{
		Scanner input = new Scanner(System.in);
		long n = input.nextInt(), x = input.nextInt(), y = input.nextInt();
		long Q = n;
		for(int q = 0; q<Q; q++)
		{
			n = input.nextInt();
			long lcm = lcm(x, y);
			long period = (lcm/x + lcm/y);
			n %= period;
			if(n == 0 || n == period - 1) System.out.println("Both");
			else
			{
				long lo = 0, hi = (long)1e9;
				while(lo < hi - 1)
				{
					long mid = (lo+hi)>>1;
					if(get(x, y, mid) <= n) lo = mid;
					else hi = mid;
				}
				if(get(x, y, lo) == n) System.out.println("Vanya");
				else System.out.println("Vova");
			}
		}
	}
	static long get(long a, long b, long x)
	{
		return x*b / a + x;
	}
	static long gcd(long a, long b)
	{
		return b == 0 ? a : gcd(b, a%b);
	}
	static long lcm(long a, long b)
	{
		return a / gcd(a, b) * b;
	}

}