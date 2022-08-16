import java.io.*;
import java.util.*;


public class cf42c
{
       
 
    public static void main(String[] args)
    throws Exception
    {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int i,z,n;
		String[] s;
		n=Integer.parseInt(br.readLine());
		s=(br.readLine()).split(" ");
		int s0=0,s1=0,s2=0;
		for(i=0;i<n;i++)
		{
			z=Integer.parseInt(s[i])%3;
			if(z==0)
				s0++;
			if(z==1)
				s1++;
			if(z==2)
				s2++;
		}
		
		int ans=s0/2+Math.min(s1,s2);
		System.out.println(ans);
		
		

       
	   
    }

}