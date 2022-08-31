import java.io.*;
import java.util.*;


public class cf42b
{
       
 
    public static void main(String[] args)
    throws Exception
    {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		String s=br.readLine();
		String t=br.readLine();
		int i;
		int[] a=new int[128];
		int[] b=new int[128];
		for(i=0;i<s.length();i++)
			a[s.charAt(i)]++;
		for(i=0;i<t.length();i++)
			b[t.charAt(i)]++;
			
		boolean flag=true;
		for(i='A';i<='Z';i++)
			if(b[i]>a[i])
				flag=false;
				
		for(i='a';i<='z';i++)
			if(b[i]>a[i])
				flag=false;
			
		if(flag)
			System.out.println("YES");
		else
			System.out.println("NO");
		

       
	   
    }

}