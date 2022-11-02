import java.io.*;
import java.util.*;
import java.math.*;

public class a implements Runnable {

	public static void main(String[] args) {
		new Thread(new a()).start();
	}
	private void solve() throws IOException {
	   Scanner in = new Scanner( System.in );
	   BigInteger z = in.nextBigInteger();

	   if ( z.compareTo( BigInteger.valueOf( -128 ) ) >= 0 && z.compareTo( BigInteger.valueOf( 127 ) ) <= 0 ) System.out.println( "byte" ); else
	   if ( z.compareTo( BigInteger.valueOf( -32768 ) ) >= 0 && z.compareTo( BigInteger.valueOf( 32767 ) ) <= 0 ) System.out.println( "short" ); else
	   if ( z.compareTo( BigInteger.valueOf( -2147483648 ) ) >= 0 && z.compareTo( BigInteger.valueOf( 2147483647 ) ) <= 0 ) System.out.println( "int" ); else
	   if ( z.compareTo( BigInteger.valueOf( -9223372036854775808L ) ) >= 0 && z.compareTo( BigInteger.valueOf( 9223372036854775807L ) ) <= 0 ) System.out.println( "long" ); else
	     System.out.println( "BigInteger" );
	}

	public void run() {
	    try {
			solve();
		} catch (IOException e) {
			e.printStackTrace();
			System.exit(1);
		}

	}
}