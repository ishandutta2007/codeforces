
import java.util.Arrays;
import java.util.Scanner;
import static java.lang.Math.*;

public class CF13_C
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int[] ar = new int[N];
        for(int i=0;i<N;i++) ar[i] = sc.nextInt();

        int[] br = ar.clone();
        Arrays.sort(br);

        long[] cur = new long[N];
        long[] prev = new long[N];

        //init
        for(int i=0;i<N;i++) cur[i] = abs(ar[0]-br[i]);

        for(int i=1;i<N;i++)
        {
            long[] temp = cur; cur = prev; prev = temp;
            long pmn = Long.MAX_VALUE;
            for(int j=0;j<N;j++)
            {
                pmn = min( pmn , prev[j] );
                cur[j] = pmn + abs(ar[i]-br[j]);
            }
        }

        long res = Long.MAX_VALUE;
        for(int i=0;i<N;i++) res = min( res , cur[i] );

        System.out.println(res);
    }
}