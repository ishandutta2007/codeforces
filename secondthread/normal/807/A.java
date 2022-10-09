import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class isItRated {

   
 public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int length=s.nextInt();
        int[] numbers=new int[length];
        int[] arr=new int[length];
        for (int i=0; i<length; i++) {
            int a=s.nextInt(), b=s.nextInt();
            if (a!=b) {
                System.out.println("rated");
                return;
            }
            numbers[i]=a;
            arr[i]=a;
        }
        Arrays.sort(arr);
        for (int i=0; i<arr.length; i++) {
            if (arr[i]!=numbers[length-i-1]) {
                System.out.println("unrated");
                return;
            }
        }
        System.out.println("maybe");
   }
}