import java.util.*;
import java.math.BigInteger; 
public class Solution {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine());
        String[] s = new String[n+1];
        int[] x = new int[n+1];
        boolean[] vis = new boolean[n+1];
        boolean[] ok = new boolean[2001];

        for (int i=0;i<n;i++)
        {
        	String in = sc.nextLine();
        	s[i] = in.split(" ")[0];
        	x[i] = Integer.parseInt(in.split(" ")[1]);
        }
        for (int val=2000;val>=0;val--)
        {
        	int last = -1;
        	boolean has = false;
        	for (int i=0;i<n;i++)
        	{
        		if (vis[i])has=true;
        		if (s[i].equals("win"))
        		{
        			if (x[i]==val && vis[i]==false) {has=false;last=i;}
        		}
        		else if (x[i]==val)
        		{
        			if (last!=-1 && vis[i]==false && !has)
        			{
        				ok[val]=true;
        				for (int j=last;j<=i;j++)
        					vis[j]=true;
        				break;
        			}
        				
        		}
        	}
        }
        BigInteger ret = new BigInteger("0");
        BigInteger p = new BigInteger("1");
        for (int i=0;i<=2000;i++)
        {
        	if (ok[i])ret = ret.add(p);
        	p = p.multiply(new BigInteger("2"));
        }
        System.out.println(ret);
    }
}