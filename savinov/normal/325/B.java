import com.sun.imageio.plugins.common.BitFile;

import java.io.IOException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.*;

public class Main
{
    static BigInteger sqrt(BigInteger a)
    {
        BigInteger l = BigInteger.ZERO;
        BigInteger r = a;
        while (l.compareTo(r) < 0)
        {
            BigInteger m = l.add(r).shiftRight(1);
            BigInteger z = m.multiply(m);
            int c = z.compareTo(a);
            if (c == 0)
            {
                return m;
            }
            if (c < 0)
                l = m.add(BigInteger.ONE);
            if (c > 0)
                r = m.subtract(BigInteger.ONE);
        }
        BigInteger z = l.multiply(l);
        if (z.compareTo(a) == 0)
        {
            return l;
        }
        return BigInteger.ZERO;
    }

    static boolean check(BigInteger a, BigInteger b, BigInteger c)
    {
        BigInteger t = a.add(a).multiply(b.subtract(BigInteger.ONE)).add(a.multiply(a.subtract(BigInteger.ONE)));
        return t.compareTo(c.add(c)) == 0;
    }


    static BigInteger solve(BigInteger a, BigInteger b)
    {
        BigInteger p = a.subtract(BigInteger.ONE).multiply(BigInteger.valueOf(2)).subtract(BigInteger.ONE);
        BigInteger d = p.multiply(p).add(b.multiply(BigInteger.valueOf(8)));
        return p.negate().add(sqrt(d)).divide(BigInteger.valueOf(2));
    }

    public static void main(String[] args) throws IOException
    {
        //BufferedReader in = new BufferedReader (new InputStreamReader(System.in));
        Scanner in = new Scanner(System.in);
        //Scanner in = new Scanner(new File("parallel.in"));
        //PrintWriter out = new PrintWriter(new File("parallel.out"));
        PrintWriter out = new PrintWriter(System.out);
        BigInteger a = in.nextBigInteger();
        boolean flag = false;
        BigInteger cur = BigInteger.ONE;
        TreeSet<BigInteger> ans = new TreeSet<BigInteger>();
        for(int i = 0; i < 70; ++i)
        {
            //out.println(cur);
            BigInteger x = solve(cur, a);
            //out.println(x.multiply(cur));
            //out.flush();
            if (check(x, cur, a))
            {
                flag = true;
                if (x.mod(BigInteger.valueOf(2)).compareTo(BigInteger.ONE) == 0) ans.add(x.multiply(cur));
            }
            cur = cur.add(cur);
        }
        if (ans.isEmpty())
        {
            out.println("-1");
        }
        else
        {
            for(BigInteger z : ans)
                out.println(z);
        }
        out.flush();
    }
}