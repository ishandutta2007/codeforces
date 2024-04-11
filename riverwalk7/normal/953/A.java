import java.util.ArrayList;
import java.util.Scanner;
public class MyClass {
    public static void main(String args[]) {
        int[] x = new int[31*19];
        long counter = 1;
        long counter2 = 1;
        long counter3 = 0;
        Scanner sc = new Scanner(System.in);
        long l = sc.nextInt();
        long r = sc.nextInt();
        int ans  = 0;
        for(int i=0; i<31; i++)
        {
            counter2 = counter;
            for(long j=counter2; j<2000000000; j*=3)
            {
                if(l <= j && j<=r)
                {
                    ++ans;
                }
            }
            counter *= 2;
        }
        System.out.println(ans);
    }
}