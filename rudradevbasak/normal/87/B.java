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
	
	HashMap<String,Integer> map;

	void solve() throws IOException
	{
		map=new HashMap();
		map.put("void",0);
		String cmd,A,B;
		for(int i=0;i<n;i++)
		{
			cmd=ns();
			A=ns();
			if(cmd.equals("typedef"))
			{
				B=ns();
				
				try
				{
				int len=A.length();
				int minus=A.lastIndexOf("&");
				int plus=A.indexOf("*");
				
				if(plus<0) plus=len;
				A=A.substring(minus+1,plus);
				
				minus++;
				plus=len-plus;
				
				int z;
				
				//debug(A);
				z=map.get(A);
				if(z<0)
					map.put(B,-1);
				else
				{
					z+=plus;
					z-=minus;
					map.put(B,z);
				}
				}
				catch(Exception e)
				{
					map.put(B,-1);
				}
			}
			else
			{
				int len=A.length();
				int minus=A.lastIndexOf("&");
				int plus=A.indexOf("*");
				
				if(plus<0) plus=len;
				A=A.substring(minus+1,plus);
				
				minus++;
				plus=len-plus;
				
				try
				{
				int z=map.get(A);
				if(z>=0)
					z=z+plus-minus;
				
				if(z<0)
					System.out.println("errtype");
				else
				{
					
					System.out.print("void");
					for(int j=0;j<z;j++)
						System.out.print("*");
					System.out.println();
				}
				}
				catch(Exception e)
				{
					System.out.println("errtype");
				}
			}
		}
		
	}
	
	int n;

	boolean input() throws IOException
	{
		n=ni();
		return true;
	}


}