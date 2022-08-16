import java.io.*;
import java.util.*;


public class cf42a
{
       
 
    public static void main(String[] args)
    throws Exception
    {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		String s,t="",z;
		int n,flag,nums=0,numt=0,i;
		n=Integer.parseInt(br.readLine());
		s=br.readLine();
		flag=1;
		nums=1;
		for(i=1;i<n;i++)
		{
			if(flag==1)
			{
				z=br.readLine();
				if(z.equals(s))
					nums++;
				else
				{
					t=z;
					numt=1;
					flag=2;
				}
			}
			else
			{
				z=br.readLine();
				if(z.equals(s))
					nums++;
				else
					numt++;
			}
		}
		if(nums>numt)
			System.out.println(s);
		else
			System.out.println(t);
		
       
	   
    }

}