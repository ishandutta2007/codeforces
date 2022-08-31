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
	
	int N,K;
	String[] lines;
	
	boolean aaaa,aabb,abab,abba;
	
	boolean isv(char c)
	{
		return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
	}
	
	boolean rhymes(String s,String t)
	{
		int ls=s.length();
		int lt=t.length();
		int li=ls-1;
		int cnt=0;
		for(;li>=0;li--)
		{
			if(isv(s.charAt(li)))
				cnt++;
			if(cnt==K)
				break;
		}
		
		int lj=lt-1;
		cnt=0;
		for(;lj>=0;lj--)
		{
			if(isv(t.charAt(lj)))
				cnt++;
			if(cnt==K)
				break;
		}
		
		if(li<0 || lj<0) return false;
		return s.substring(li,ls).equals(t.substring(lj,lt));
	}
	
	void doit(int base)
	{
		boolean[][] is=new boolean[4][4];
		for(int i=0;i<4;i++)
			for(int j=0;j<4;j++)
			{
				is[i][j] = rhymes(lines[base+i],lines[base+j]);
				if(!is[i][j])
					aaaa=false;
			}
		
		if(!is[0][1] || !is[2][3]) aabb=false;
		if(!is[0][3] || !is[1][2]) abba=false;
		if(!is[0][2] || !is[1][3]) abab=false;
	}
	
	

	void solve() throws IOException
	{
		aaaa=true;
		aabb=true;
		abba=true;
		abab=true;
		
		for(int i=0;i<N;i++)
			doit(4*i);
			
		if(aaaa)
			System.out.println("aaaa");
		else if(aabb)
			System.out.println("aabb");
		else if(abba)
			System.out.println("abba");
		else if(abab)
			System.out.println("abab");
		else
			System.out.println("NO");
	}

	boolean input() throws IOException
	{
		N=ni(); K=ni();
		lines=new String[4*N];
		for(int i=0;i<4*N;i++)
			lines[i]=ns();
		return true;
	}


}