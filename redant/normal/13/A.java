
import java.util.Scanner;

public class CF13_A
{
    public static void main(String[] args)
    {
        int i,j,k,A,n,num=0,den=0;
        Scanner sc = new Scanner(System.in);
        A = sc.nextInt();

        for(int base = 2;  base <A;base++)
        {
            n = A;
            while(n>0)
            {
                num+=n%base; n/=base;
            }
        }

        den = A - 2;

        int g = gcd(num,den);

        System.out.println((num/g)+"/"+(den/g));
    }

    static int gcd(int a,int b){ return b==0?a:gcd(b,a%b); }

    static int ival(String s){  return Integer.parseInt(s);  }
}