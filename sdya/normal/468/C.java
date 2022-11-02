import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.*;
 
public class Main {
   public static void main(String[] args) {
       Scanner in = new Scanner(System.in);
       BigInteger a = in.nextBigInteger();
 
       BigInteger A = BigInteger.TEN.pow(50);
       BigInteger B = BigInteger.TEN.pow(49);
 
       BigInteger res = B.multiply(BigInteger.valueOf(45).multiply(BigInteger.valueOf(50)));
       res = res.remainder(a);
 
       if (res.compareTo(BigInteger.ZERO) == 0) {
       	   System.out.print("1 ");
       	   for (int i = 0; i < 50; ++i) {
       	   	System.out.print("9");
       	   }
       	   System.out.println();
           return;
       }
 
       BigInteger left = a.subtract(res);
       BigInteger right = A.add(left.subtract(BigInteger.ONE));
       System.out.println(left + " " + right);
   }
}