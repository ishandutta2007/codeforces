import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Hashtable;
import java.util.StringTokenizer;
import java.util.TreeSet;


public class A159
{
    static class guy
    {
        Hashtable<guy, TreeSet<Integer>> ht;

        String name;


        public guy( String s )
        {
            name = s;
            ht = new Hashtable<guy, TreeSet<Integer>>();
        }


        public void add( guy a, int t )
        {
            if ( ht.get( a ) == null )
                ht.put( a, new TreeSet<Integer>() );
            ht.get( a ).add( t );
        }


        public boolean friends( guy o )
        {
            TreeSet<Integer> ts = o.ht.get( this );
            if ( ts == null )
                return false;
            if ( ht.get( o ) == null )
                return false;
            for ( int t : ht.get( o ) )
            {
                Integer a = ts.lower( t ), b = ts.higher( t );
                if ( ( a != null && close( a, t ) )
                    || ( b != null && close( b, t ) ) )
                {
                    return true;
                }
            }
            return false;
        }


        static boolean close( int a, int b )
        {
            int d = a - b;
            d = d > 0 ? d : -d;
            return d > 0 && d <= D;
        }
    }

    static int D;


    static String next()
    {
        if ( st == null || !st.hasMoreTokens() )
            nextLine();
        return st.nextToken();
    }


    static int nextInt()
    {
        return Integer.parseInt( next() );
    }


    static void nextLine()
    {
        try
        {
            st = new StringTokenizer( f.readLine() );
        }
        catch ( Exception e )
        {
            e.printStackTrace();
        }
    }

    static StringTokenizer st;

    static PrintWriter out;

    static BufferedReader f;

    static ArrayList<guy> guise;


    public static void main( String[] args ) throws IOException
    {
        f = new BufferedReader( new InputStreamReader( System.in ) );
        out = new PrintWriter( System.out );
        guise = new ArrayList<guy>();
        int N = nextInt();
        D = nextInt();
        Hashtable<String, guy> ht = new Hashtable<String, guy>();
        for ( int x = 0; x < N; x++ )
        {
            String a = next(), b = next();
            int t = nextInt();
            guy ga = get( ht, a ), gb = get( ht, b );
            ga.add( gb, t );
        }
        StringBuffer prnt = new StringBuffer();
        int count = 0;
        for ( int x = 0; x < guise.size(); x++ )
        {
            guy a = guise.get( x );
            for ( int y = x + 1; y < guise.size(); y++ )
            {
                guy b = guise.get( y );
                if ( a.friends( b ) )
                {
                    count++;
                    prnt.append( String.format( "%s %s\n", a.name, b.name ) );
                }
            }
        }
        out.println( count );
        out.print( prnt );
        out.close(); // System.exit(0); }
    }


    static guy get( Hashtable<String, guy> h, String s )
    {
        if ( !h.containsKey( s ) )
        {
            guy g;
            h.put( s, g = new guy( s ) );
            guise.add( g );
        }
        return h.get( s );
    }
}