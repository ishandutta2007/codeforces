import java.util.Scanner;


public class B127
{

    public static void main( String[] args ) throws Exception
    {
        Scanner in = new Scanner( System.in );
        int n = in.nextInt();
        int[] num = new int[1000];
        for(int x=0;x<n;x++) {
            num[in.nextInt()]++;
        }
        int sum = 0;
        for(int x=0;x<1000;x++) {
            sum+=num[x]/2;
        }
        System.out.println(sum/2);
    }
}