import java.io.*;
import java.math.*;
import java.util.*;
public class Main
{
    class Fraction
    {
        private BigInteger numerator,denominator;
        Fraction()
        {
            numerator=BigInteger.ZERO;
            denominator=BigInteger.ONE;
        }
        Fraction(BigInteger x)
        {
            numerator=x;
            denominator=BigInteger.ONE;
        }
        Fraction(int x)
        {
            numerator=BigInteger.valueOf(x);
            denominator=BigInteger.ONE;
        }
        Fraction(BigInteger x,BigInteger y)
        {
            numerator=x;
            denominator=y;
        }
        Fraction(int x,int y)
        {
            numerator=BigInteger.valueOf(x);
            denominator=BigInteger.valueOf(y);
        }
        Fraction(Fraction x)
        {
            numerator=x.numerator;
            denominator=x.denominator;
        }
        public Fraction add(Fraction x)
        {
            return new Fraction(numerator.multiply(x.denominator).add(x.numerator.multiply(denominator)),denominator.multiply(x.denominator));
        }
        public Fraction subtract(Fraction x)
        {
            return new Fraction(numerator.multiply(x.denominator).subtract(x.numerator.multiply(denominator)),denominator.multiply(x.denominator));
        }
        public Fraction multiply(Fraction x)
        {
            return new Fraction(numerator.multiply(x.numerator),denominator.multiply(x.denominator));
        }
        public Fraction divide(Fraction x)
        {
            return new Fraction(numerator.multiply(x.denominator),denominator.multiply(x.numerator));
        }
        public void write()
        {
            BigInteger g=numerator.gcd(denominator);
            Main.writer.println(numerator.divide(g).toString()+"/"+denominator.divide(g).toString());
        }
    }
    static BufferedReader reader;
    static StringTokenizer tokenizer;
    static PrintWriter writer;
    Fraction f[];
    int g[];
    int n;
    Fraction ff(int x,Fraction m)
    {
        if(g[x]==1)
        {
            g[x]=2;
            f[x]=m;
            return new Fraction();
        }
        g[x]=1;
        int k=0;
        int t=x;
        while(t<n)
        {
            t*=2;
            k++;
        }
        Fraction r=new Fraction(k);
        if(t>n)
        {
            Fraction m1=new Fraction(t-n,t);
            r=r.add(ff(t-n,m.multiply(m1)).multiply(m1));
            if(g[x]==2)
            {
                r=r.divide(new Fraction(1).subtract(f[x].divide(m)));
            }
        }
        return r;
    }
    public void solve() throws IOException
    {
        n=nextInt();
        f=new Fraction[10010];
        g=new int[10010];
        ff(1,new Fraction(1,1)).write();
    }
    public void run() throws IOException
    {
        reader=new BufferedReader(new InputStreamReader(System.in));
        writer=new PrintWriter(System.out);
        solve();
        reader.close();
        writer.close();
    }
    public static void main(String[] args) throws IOException
    {
        new Main().run();
    }
    int nextInt() throws IOException
    {
        return Integer.parseInt(nextToken());
    }
    String nextToken() throws IOException
    {
        while(tokenizer==null||!tokenizer.hasMoreTokens())
        {
            tokenizer=new StringTokenizer(reader.readLine());
        }
        return tokenizer.nextToken();
    }
}