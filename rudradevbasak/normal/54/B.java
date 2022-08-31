/** Team Proof
Java template
*/

import java.io.*;
import java.util.*;
import java.math.*;

public class Main
{
	BufferedReader br=new BufferedReader(new InputStreamReader(System.in));

	void debug(Object...os)
	{
		System.out.println(Arrays.deepToString(os));
	}


	void execute() throws IOException
	{
		totalCases = 1;
		for(testNum = 1; testNum <= totalCases; testNum++)
		{
			if(!input())
				break;
			solve();
		}
	}

	int totalCases, testNum;
	String[] grid;
	int A,B;

	String[] rotate(String[] s)
	{
		int r=s.length;
		int c=s[0].length();

		String[] ans=new String[c];
		for(int i=0;i<c;i++)
		{
			ans[i]="";
			for(int j=0;j<r;j++)
			{
				ans[i]+=s[j].charAt(c-1-i);
			}
		}
		return ans;
	}

	boolean same(String[] a,String[] b)
	{
		for(int i=0;i<a.length;i++)
		{
			if(!a[i].equals(b[i]))
				return false;
		}
		return true;
	}

	boolean samerotate(String[] a,String[] b)
	{
		if(same(a,b)) return true;

		int r=a.length,cc=a[0].length();

		if(r==cc)
		{
			String[] c=rotate(b);
			if(same(a,c)) return true;

			String[] d=rotate(c);
			if(same(a,d)) return true;

			String[] e=rotate(d);
			if(same(a,e)) return true;
		}
		else
		{
			String[] c=rotate(rotate(b));
			if(same(a,c)) return true;
		}
		return false;
	}

	boolean valid(int x,int y)
	{
		if(A%x!=0 || B%y!=0) return false;

		String[][][] pcs=new String[A/x][B/y][x];
		for(int i=0;i<A/x;i++)
			for(int j=0;j<B/y;j++)
				for(int k=0;k<x;k++)
					pcs[i][j][k]=grid[i*x + k].substring(j*y,j*y+y);

		for(int i=0;i<A/x;i++)
			for(int j=0;j<B/y;j++)
				for(int k=0;k<A/x;k++)
					for(int l=0;l<B/y;l++)
					{
						if(k==i && l==j) continue;
						if(samerotate(pcs[i][j],pcs[k][l])) return false;
					}

		return true;
	}
			

	

	void solve()
	{	
		int cnt=0;
		int besti=1000,bestj=1000;
		for(int i=1;i<=A;i++)
			for(int j=1;j<=B;j++)
			{
				if(valid(i,j))
				{
					cnt++;
					if(i*j<besti*bestj)
					{
						besti=i;
						bestj=j;
					}
					else if(i*j == besti*bestj && i<besti)
					{
						besti=i;
						bestj=j;
					}
				}
			}
		System.out.println(cnt);
		System.out.println(besti+" "+bestj);
			
	}

	boolean input() throws IOException
	{
		String[] ss=br.readLine().split(" ");
		A=Integer.parseInt(ss[0]);
		B=Integer.parseInt(ss[1]);
		grid=new String[A];
		for(int i=0;i<A;i++)
			grid[i]=br.readLine();
		return true;
	}

	public static void main(String[] args) throws IOException
	{
		new Main().execute();
	}
}