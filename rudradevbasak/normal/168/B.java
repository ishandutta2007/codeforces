import java.io.*;
import java.util.*;
import java.math.*;

public class Main
{
	BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
	
	public static void main(String[] args) throws IOException
	{
		new Main().execute();
	}

	Vector<String> lines;
	int n;
	boolean[] hash;
	
	boolean hasHash(String s)
	{
		int len=s.length();
		for(int i=0;i<len;i++)
		{
			char c = s.charAt(i);
			if(c=='#') return true;
			if(c!=' ') return false;
		}
		return false;
	}
	
	
	
	void execute() throws IOException
	{
		lines=new Vector<String>();
		int k=0;
		while(true)
		{
			String s=br.readLine();
			if(s==null)
				break;
			lines.add(s);
		}
		n=lines.size();
		hash=new boolean[n];
		for(int i=0;i<n;i++)
			hash[i] = hasHash(lines.get(i));
			
		StringBuffer ans=new StringBuffer();
		for(int i=0;i<n;i++)
		{
			if(hash[i])
			{
				ans.append(lines.get(i));
				ans.append("\r\n");
			}
			else
			{
				for(int j=i;j<=n;j++)
				{
					if(j==n || hash[j])
					{
						ans.append("\r\n");
						i=j-1;
						break;
					}
					else
					{
						String t=lines.get(j).replace(" ","");
						ans.append(t);
					}
				}
			}
		}
		System.out.print(ans);
	}


}