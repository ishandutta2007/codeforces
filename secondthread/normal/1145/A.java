import java.util.*;
import java.io.*;

public class A {
    
    public static void main(String[] args) {
        Scanner fs=new Scanner(System.in);
        int n=fs.nextInt();
        int[] a=new int[n];
        for (int i=0; i<n; i++) {
            a[i]=fs.nextInt();
        }
        System.out.println(go(a, 0, n-1));
    }
    
    public static int go(int[] a, int l, int r) {
        if (sorted(a, l, r))
        return r-l+1;
        return Math.max(go(a, l, (l+r)/2),
        go(a, 1+(l+r)/2, r));
    }
    
    public static boolean sorted(int[] a, int l, int r) {
        
        for (int i=l+1; i<=r; i++) {
            if (a[i]<a[i-1])
            return false;
        }
        return true;
    }
}