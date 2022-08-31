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
	

	//Main Code starts Here
	int totalCases, testNum;
	int n,m;
	String[] grid;
	int[] stkx;
	int[] stky;
	
	int[] barx;
	int[] bary;
	int top;
	

	void execute() throws IOException
	{
		input();
		solve();
		
	}
	
	long rect(long a,long b)
	{
		//debug("in rect",a,b);
		return a*b*(a+b)/2;
	}

	void solve()
	{
		long total=0;
		long den=0;
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
			{
				long sum=0;
				sum+=rect(n-i,m-j-1);
				sum+=rect(n-i-1,j+1);
				sum+=rect(i+1,j);
				sum+=rect(i,m-j);
				if(grid[i].charAt(j)=='.')
				{
					total+=sum;
					den++;
				}
				else
					total-=sum;
				//debug(sum);
				
				//total+=sum;
				//debug(total);
			}
			
		for(int i=0;i<top;i++)
		for(int j=0;j<top;j++)
		{
			int x1,x2,y1,y2;
			x1=stkx[i];
			y1=stky[i];
			
			x2=stkx[j];
			y2=stky[j];
			
			total+=Math.abs(x2-x1)+Math.abs(y2-y1);
		}
				
		//debug(total,den);		
		int[] left=new int[n];
		int[] down=new int[m];
		
		int curr;
		for(int i=0;i<n;i++)
		{
			if(barx[i]==-1) continue;
			//debug("left",i);
			curr=barx[i];
			left[i]=m-curr-1;
			
			for(int j=i-1;j>=0;j--)
				if(barx[j]>=0 && barx[j]>curr)
				{
					curr=barx[j];
					left[i]+=m-curr-1;
				}
				else
					break;
					
			curr=barx[i];
			for(int j=i+1;j<n;j++)
				if(barx[j]>=0 && barx[j]>curr)
				{
					curr=barx[j];
					left[i]+=m-curr-1;
				}
				else
					break;
		}
		
		for(int i=0;i<m;i++)
		{
			if(bary[i]==-1) continue;
			//debug("down",i);
			curr=bary[i];
			down[i]=n-curr-1;
			
			for(int j=i-1;j>=0;j--)
				if(bary[j]>=0 && bary[j]>curr)
				{
					curr=bary[j];
					down[i]+=n-curr-1;
				}
				else
					break;
					
			curr=bary[i];
			for(int j=i+1;j<m;j++)
				if(bary[j]>=0 && bary[j]>curr)
				{
					curr=bary[j];
					down[i]+=n-curr-1;
				}
				else
					break;
		}

		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				if(grid[i].charAt(j)=='.')
				{
					if(barx[i]>j)
						total+=4*left[i];
					if(bary[j]>i)
						total+=4*down[j];
				}
		
		//debug("left :");
		//debug(left);
		//debug("down :");
		//debug(down);
		//debug();
		//debug(total,den);
		System.out.println(((double)total)/(den*den));
		
		
	}

	boolean input() throws IOException
	{
		n=ni();
		m=ni();
		grid=new String[n];
		stkx=new int[n];
		stky=new int[m];
		barx=new int[n];
		bary=new int[m];
		Arrays.fill(barx,-1);
		Arrays.fill(bary,-1);
		top=0;
		
		for(int i=0;i<n;i++)
		{
			grid[i]=ns();
			int z=grid[i].indexOf("X");
			if(z>=0)
			{
				stkx[top]=i;
				stky[top]=z;
				barx[i]=z;
				bary[z]=i;
				
				top++;
			}
		}
		
		
		return true;
	}


}