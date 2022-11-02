import java.io.*;
import java.util.*;
import java.math.BigInteger;

public class E {
  public static void main( String[] args ) {
    new E().run();
  }

  ArrayList<Integer>[] g;
  ArrayList<Integer>[] gw;
  BigInteger[][] f;
  int n;
  int[] maxs;

  public void dfs( int i ) {
    BigInteger[] ft = new BigInteger[n+1];

    for ( Integer v: g[i] )
      dfs( v );

    if ( g[i].size() == 0 ) {
      f[i][1] = BigInteger.ONE;
      f[i][0] = BigInteger.ONE;
      maxs[i] = 1;
      return;
    }

    int ms = maxs[ g[i].get(0) ];
    for ( int j=0; j<=ms; j++ )
      f[i][j+1] = f[ g[i].get( 0 ) ][j];
    ms++;

    for ( int q=1; q<g[i].size(); q++ ) {
      int v = g[i].get( q );

      int ms2 = maxs[v];
      for ( int t=0; t<=ms; t++ )
        for ( int u=0; u<=ms2; u++ )
          if ( ft[t+u] == null || f[i][t].multiply( f[v][u] ).compareTo( ft[t+u] ) > 0 )
            ft[t+u] = f[i][t].multiply( f[v][u] );
      ms += ms2;

      for ( int t=0; t<=ms; t++ )
        f[i][t] = ft[t];
    }

    for ( int j=1; j<=ms; j++ )
      if ( f[i][j].multiply( BigInteger.valueOf( j ) ).compareTo( f[i][0] ) > 0 )
        f[i][0] = f[i][j].multiply( BigInteger.valueOf( j ) );

    maxs[i] = ms;
  }

  public void dfsp( int i, int p ) {
    for ( Integer v: gw[i] )
      if ( v != p ) {
        g[i].add( v );
        dfsp( v, i );
      }         
  }

  public void run() {
    try {
      Scanner in = new Scanner( System.in );
      PrintWriter out = new PrintWriter( System.out );

      n = in.nextInt();
      g = new ArrayList[n];
      gw = new ArrayList[n];
      for ( int i=0; i<n; i++ ) g[i] = new ArrayList<Integer>();
      for ( int i=0; i<n; i++ ) gw[i] = new ArrayList<Integer>();

      for ( int i=0; i<n-1; i++ ) {
        int a = in.nextInt() - 1;
        int b = in.nextInt() - 1;

        gw[a].add( b );
        gw[b].add( a );
      }

      dfsp( 0, -1 );

      f = new BigInteger[n][n+1];
      for ( int i=0; i<n; i++ )
        for ( int j=0; j<=n; j++ )
          f[i][j] = BigInteger.ZERO;

      maxs = new int[n];

      dfs( 0 );
      out.println( f[0][0] );

      out.flush();
      out.close();
      in.close();
    } catch ( Exception e ) {
      e.printStackTrace();
    }
  }
}