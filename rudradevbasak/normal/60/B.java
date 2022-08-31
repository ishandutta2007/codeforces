/** Team Proof
Java template
*/

import java.io.*;
import java.util.*;
import java.math.*;

public class Main
{
	BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
	StringTokenizer tokenizer=null;
	
	public static void main(String[] args) throws IOException
	{
		new Main().execute();
	}
	
	void debug(Object...os)
	{
		System.out.println(Arrays.deepToString(os));
	}
	
	int ni() throws IOException
	{
		return Integer.parseInt(ns());
	}
	
	long nl() throws IOException 
	{
		return Long.parseLong(ns());
	}
	
	double nd() throws IOException 
	{
		return Double.parseDouble(ns());
	}
		
	String ns() throws IOException 
	{
		while (tokenizer == null || !tokenizer.hasMoreTokens()) 
			tokenizer = new StringTokenizer(br.readLine());
		return tokenizer.nextToken();
	}
	
	String nline() throws IOException
	{
		tokenizer=null;
		return br.readLine();
	}
		
	

	//Main Code starts Here
	int totalCases, testNum;	
	

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
	
	int k,n,m;
	int[] dx={-1,0,0,0,0,1};
	int[] dy={0,-1,0,0,1,0};
	int[] dz={0,0,-1,1,0,0};
	boolean[][][] grid;
	boolean[][][] done;
	int cnt;
	
	boolean isValid(int x,int y,int z)
	{
		if(x<0 || x>=k || y<0 || y>=n || z<0 || z>=m) return false;
		return grid[x][y][z] && !done[x][y][z];
	}
	
	void dfs(int a,int b,int c)
	{
		done[a][b][c]=true;
		cnt++;
		
		for(int i=0;i<6;i++)
		{
			int x=a+dx[i];
			int y=b+dy[i];
			int z=c+dz[i];
			if(isValid(x,y,z))	dfs(x,y,z);
		}
	}
		
	int begy,begz;
	

	void solve()
	{
		cnt=0;
		dfs(0,begy-1,begz-1);
		
		
		System.out.println(cnt);
	}

	boolean input() throws IOException
	{
		k=ni();
		n=ni();
		m=ni();
		grid=new boolean[k][n][m];
		done=new boolean[k][n][m];
		//debug(k,n,m);
		for(int i=0;i<k;i++)
		{
			for(int j=0;j<n;j++)
			{
				
				String s=ns();
				for(int l=0;l<m;l++)
				{
					//debug(i,j,l);
					grid[i][j][l]=s.charAt(l)=='.';
				}
			}
		}
		begy=ni();
		begz=ni();
		return true;
	}


}