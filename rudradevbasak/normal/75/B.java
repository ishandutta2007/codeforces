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

	String my;
	int n;
	int top=0;
	String[] names;
	int[] points;
	
	
	void solve()
	{
		//debug(top);
		//debug(names);
		//debug(points);
		
		for(int i=1;i<top;i++)
		{
			for(int j=i+1;j<top;j++)
			{
				if(points[j]>points[i] || (points[j]==points[i] && names[j].compareTo(names[i])<0))
				{
					int temp=points[i];
					points[i]=points[j];
					points[j]=temp;
					
					String t=names[i];
					names[i]=names[j];
					names[j]=t;
				}
			}
		}
		
		for(int i=1;i<top;i++)
			System.out.println(names[i]);
	}

	
	int add(String s)
	{
			int found=-1;
			int x=0;
			for(int i=0;i<top;i++)
			{
				if(names[i].equals(s))
				{
					found=i;
					break;
				}
			}
			if(found<0)
			{
				x=top;
				names[top++]=s;
			}
			else
				x=found;
			return x;
	}
	
	
	
	boolean input() throws IOException
	{
		my=ns();
		n=ni();
		top=0;
		names=new String[111];
		points=new int[111];
		names[top++]=my;
		String X,Y,word,temp;
		int x,y;
		for(int i=0;i<n;i++)
		{
			X=ns();
			x=add(X);
				
			
			word=ns();
			if(word.equals("posted"))
			{
				temp=ns();
				Y=ns();
				Y=Y.substring(0,Y.length()-2);
				temp=ns();
				y=add(Y);
				if(x==0) points[y]+=15;
				if(y==0) points[x]+=15;
				//debug(x,y);
			}
			else if(word.equals("commented"))
			{
				temp=ns();
				Y=ns();
				Y=Y.substring(0,Y.length()-2);
				temp=ns();
				y=add(Y);				
				if(x==0) points[y]+=10;
				if(y==0) points[x]+=10;		
		
			}
			else if(word.equals("likes"))
			{
				Y=ns();
				Y=Y.substring(0,Y.length()-2);
				temp=ns();
				y=add(Y);
				if(x==0) points[y]+=5;
				if(y==0) points[x]+=5;
			
			}
		}
		return true;
	}


}