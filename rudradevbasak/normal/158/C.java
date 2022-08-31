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

	String[] stk;
	int top;
	
	void print()
	{
		System.out.print("/");
		for(int i=0;i<top;i++)
			System.out.print(stk[i]+"/");
		System.out.println();
	}
	
	
	void solve() throws IOException
	{
		stk=new String[100000];
		top=0;
		
		int n=ni();
		for(int i=0;i<n;i++)
		{
			String s=ns();
			if(s.equals("pwd"))
				print();
			else
			{
				s=ns();
				String[] arr=s.split("/");
				for(String z:arr)
				{
					if(z.length()==0) top=0;
					else if(z.equals("..")) top--;
					else stk[top++]=z;
				}
			}
		}
	}

	boolean input() throws IOException
	{
		
		return true;
	}
}