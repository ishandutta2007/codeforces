
import java.io.*;
import java.math.*;
import java.util.*;

public class CF_18_B 
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        String s = "";
        int n = sc.nextInt(), x = 0;
        
        int[] last = new int[2005];
        //int[] profit = new int[n+1];
        BigInteger[] big_profit = new BigInteger[n+1];
        
        Arrays.fill(last,-1);
        big_profit[0] = BigInteger.ZERO;
        BigInteger newprofit;
        
        for(int i=1;i<=n;i++)
        {
            s = sc.next(); x = sc.nextInt();
            //System.out.print(" --> "+s+" : "+x+"  ==>  ");
            //profit[i] = profit[i-1];
            big_profit[i] = big_profit[i-1].add(BigInteger.ZERO);
            
            if(s.charAt(0)=='s' && last[x]!=-1)
            {
                //System.out.println("   ...last["+x+"] = "+last[x]+"...   ");
                newprofit = big_profit[last[x]-1].add(BigInteger.ONE.shiftLeft(x));
                
                big_profit[i] = big_profit[i].max(newprofit);
            }
            else
            {
                last[x] = i;
            }
            
            //System.out.println(profit[i]+" , ");
        }
        
        //System.out.println();
        //BigInteger two = new BigInteger("2");
        //System.out.println( two.pow(profit[n]) );
        System.out.println(big_profit[n]);
    }
}