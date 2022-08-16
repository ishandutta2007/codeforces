/*
* Author: Nikhil Garg
* Date:   2010-10-18
*
*/
import java.io.*;
import java.util.*;
import java.math.*;






public class cf40a
{


	public static void main(String[] args) throws IOException
	{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		String s=br.readLine();
		String t=br.readLine();
		int ls,lt;
		ls=s.length();
		lt=t.length();
		if(ls!=lt)
			System.out.println("NO");
		else
		{
			boolean flag=true;
			for(int i=0;i<ls;i++)
			{
				if(s.charAt(i)!=t.charAt(ls-i-1))
				{
					flag=false;
					break;
				}
			}
			if(flag)
				System.out.println("YES");
			else
				System.out.println("NO");
		}
		
	}

	public static void input() throws IOException
	{

	}

	public static void solve() throws IOException
	{

	}
}