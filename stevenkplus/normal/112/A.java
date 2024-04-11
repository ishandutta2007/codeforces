import java.util.Scanner;

public class A112 {
public static void main(String[] args) throws Exception {
Scanner in = new Scanner(System.in);
String a =in.next(),b=in.next();
int k = a.compareToIgnoreCase(b);
if(k<0) System.out.println("-1");
else if (k==0) System.out.println(k);
else System.out.println(1);
}}