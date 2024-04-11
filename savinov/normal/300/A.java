
import java.io.*;
import java.util.*;
import java.util.Arrays;

public class main
{
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        PrintWriter out = new PrintWriter(System.out);

        int n = in.nextInt();

        int a[] = new int[n];

        for(int i = 0; i < n; ++i)
        {
            a[i] = in.nextInt();
        }
        Arrays.sort(a);
        out.println("1 " + a[0]);
        if (a[n - 1] > 0)
        {
            out.println("1 " + a[n - 1]);
            out.print((n - 2) + " ");
            for(int i = 1; i < n - 1; ++i)
                out.print(a[i] + " ");
            out.println("");
        } else
        {
            out.println("2 " + a[1] + " " + a[2]);
            out.print((n - 3) + " ");
            for(int i = 3; i < n; ++i)
                out.print(a[i] + " ");
            out.println("");
        }
        out.flush();

    }

}