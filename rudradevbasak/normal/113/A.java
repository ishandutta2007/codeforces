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
	String s;
	
	boolean isMaleAdj(String s)
	{
		return s.endsWith("lios");
	}
	
	boolean isMaleNoun(String s)
	{
		return s.endsWith("etr");
	}
	
	boolean isMaleVerb(String s)
	{
		return s.endsWith("initis");
	}
	
	boolean isfeMaleAdj(String s)
	{
		return s.endsWith("liala");
	}
	
	boolean isfeMaleNoun(String s)
	{
		return s.endsWith("etra");
	}
	
	boolean isfeMaleVerb(String s)
	{
		return s.endsWith("inites");
	}
	
	boolean isMale(String s)
	{
		return isMaleNoun(s) || isMaleAdj(s) || isMaleVerb(s);
	}
	
	boolean isfeMale(String s)
	{
		return isfeMaleNoun(s) || isfeMaleAdj(s) || isfeMaleVerb(s);
	}
	
	boolean isWord(String s)
	{
		return isMale(s) || isfeMale(s);
	}
	


	void solve()
	{	
		String[] arr=s.split(" ");
		int n=arr.length;
		
		boolean ok=true,male=false,female=false;
		
		for(int i=0;i<n;i++)
		{
			if(!isWord(arr[i]))	ok=false;
			if(isMale(arr[i]))	male=true;
			if(isfeMale(arr[i]))	female=true;
		}
		
		if(!ok || (male && female))
		{
			System.out.println("NO");
			return;
		}
		
		if(n==1)
		{
			System.out.println("YES");
			return;
		}
		
		int nn=-1;
		for(int i=0;i<n;i++)
			if(isMaleNoun(arr[i]) || isfeMaleNoun(arr[i]))
				nn=i;
				
		if(nn==-1)
		{
			System.out.println("NO");
			return;
		}		
				
		ok=true;
		for(int i=0;i<nn;i++)
			if(!isMaleAdj(arr[i]) && !isfeMaleAdj(arr[i]))
				ok=false;
				
		for(int i=nn+1;i<n;i++)
			if(!isMaleVerb(arr[i]) && !isfeMaleVerb(arr[i]))
				ok=false;
				
		if(!ok)
		{
			System.out.println("NO");
			return;
		}
		
		System.out.println("YES");
		
	}

	boolean input() throws IOException
	{
		s=br.readLine();
		return true;
	}

	public static void main(String[] args) throws IOException
	{
		new Main().execute();
	}
}