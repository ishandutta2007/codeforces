import java.util.Scanner;

public class Main{
	public static void main(String args[])
	{
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt();
		int[] a = new int[n];
		for(int i = 0; i < n; i++)
			a[i] = scan.nextInt();
		int ans = 0x3f3f3f3f, t = 0;
		for(int x = 1; x <= 100; x++)
		{
			int nowans = 0;
			for(int i = 0; i < n; i++)
				if(a[i] > x + 1)nowans += a[i] - (x + 1);
				else if(a[i] < x - 1)nowans += x - 1 - a[i];
			if(nowans < ans)
			{
				ans = nowans;
				t = x;
			}
		}
		System.out.println(t + " " + ans);
	}
}