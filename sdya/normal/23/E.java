import java.io.*;
import java.util.*;
import java.math.*;

public class CF23E{
	BigInteger dp[][] = new BigInteger [701][701];
	boolean used[] = new boolean [701];
	int cnt[] = new int [701];
	int n;
	Scanner in = new Scanner(System.in);
	PrintWriter out = new PrintWriter(System.out);
	
	ArrayList <Integer> g [] = new ArrayList [701];
	
	public void dfs(int v)
	{
		if (used[v]) return;
		used[v] = true;
		int adds = 0;
		cnt[v] = 0;
		ArrayList < Integer > ver = new ArrayList < Integer > ();
		for (int i = 0; i < g[v].size(); i ++)
			if (!used[g[v].get(i)])
			{
				adds ++;
				dfs(g[v].get(i));
				cnt[v] += cnt[g[v].get(i)];	
				ver.add(g[v].get(i));
			}
		if (adds == 0)
		{
			for (int i = 0; i <= n; i ++)
				dp[v][i] = BigInteger.ZERO;
			cnt[v] = 1;
			dp[v][0] = BigInteger.ONE;
			dp[v][1] = BigInteger.ONE;
			return;
		}
		BigInteger buf[][] = new BigInteger[adds + 1][cnt[v] + 1];
		for (int i = 0; i <= adds; i ++)
			for (int j = 0; j <= cnt[v]; j ++)
				buf[i][j] = BigInteger.ZERO;
		
		buf[0][0] = BigInteger.ONE;	
		for (int i = 1; i <= adds; i ++)
			for (int j = 0; j <= cnt[v]; j ++)
				for (int k = 0; k <= cnt[ver.get(i - 1)] && k <= j; k ++)
				{
					BigInteger cur = buf[i - 1][j - k].multiply(dp[ver.get(i - 1)][k]);
					if (cur.compareTo(buf[i][j]) > 0)
						buf[i][j] = cur;
				}
		for (int j = 0; j <= cnt[v]; j ++)
		{
			dp[v][j + 1] = buf[adds][j];
			int tek = j + 1;
			BigInteger cur = dp[v][j + 1].multiply(new BigInteger("" + tek));
			if (cur.compareTo(dp[v][0]) > 0)
				dp[v][0] = cur;
		}

		cnt[v] ++;
	}
	
	
	public static void main(String args[]) throws IOException
	{
		new CF23E().run();
	}
	
	void run(){
		
		//Scanner in = new Scanner(new File("input.txt"));
		//PrintWriter out = new PrintWriter(new File("output.txt"));
		n = in.nextInt();
		for (int i = 0; i <= n; i ++)
			g[i] = new ArrayList < Integer > ();
		for (int i = 1; i < n; i ++)
		{
			int a, b;
			a = in.nextInt();
			b = in.nextInt();
			g[a].add(b);
			g[b].add(a);
		}
		
		for (int i = 1; i <= n; i ++)
			for (int j = 0; j <= n; j ++)
				dp[i][j] = BigInteger.ZERO;
		
		dfs(1);
		out.println(dp[1][0]);
		
		out.close();
	}
}