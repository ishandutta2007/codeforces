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
	
	int n,m;
	int lo,hi;

	void solve()
	{
	
	}

	boolean input() throws IOException
	{
		n=ni(); m=ni();
		lo=1;
		hi=n;
		for(int i=0;i<m;i++)
		{
			ns();
			ns();
			String s=ns();
			ns();
			int x=ni();
			if(s.equals("left"))
				hi=Math.min(hi,x-1);
			else
				lo=Math.max(lo,x+1);
		}
		
		if(lo<=hi)
			System.out.println((hi-lo+1));
		else
			System.out.println("-1");
		return true;
	}


}