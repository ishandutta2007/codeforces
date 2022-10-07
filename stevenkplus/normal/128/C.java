import java.math.BigInteger;
import java.util.Scanner;


public class C128
{
    public static void main( String[] args ) throws Exception
    {
        Scanner in = new Scanner( System.in );
        int m = in.nextInt(), n = in.nextInt(), c = in.nextInt();
        long mo = (long)( 1E9 + 7 );
        long a = choose( m - 1, c * 2 ), b = choose( n - 1, c * 2 );
        System.out.println( ( a % mo ) * ( b % mo ) % mo );

    }



    static long choose( int a, int b )
    {
        BigInteger ret = BigInteger.ONE;
        for ( int x = 1; x <= b; x++ )
        {
            ret =ret.multiply(BigInteger.valueOf( (long)(a - x + 1)));
            ret =ret.divide( BigInteger.valueOf( (long)x)) ;
        }
        return ret.mod( BigInteger.valueOf((long)(1E9+7) )).longValue();
    }
}