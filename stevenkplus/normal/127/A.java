import java.util.Scanner;

public class A127
{
    public static void main( String[] args ) throws Exception
    {
        Scanner in = new Scanner( System.in );
        int n = in.nextInt(),k=in.nextInt();
        double d = 0;
        int px = in.nextInt(),py=in.nextInt();
        for(int x=1;x<n;x++) {
           double dist = dist(px,py,px=in.nextInt(),py=in.nextInt()); 
           d+=dist;
        }
        System.out.println(k*d/50);
    }
    static double dist(int a,int b,int c,int d) {
        return Math.sqrt((a-c)*(a-c)+(b-d)*(b-d));
    }
}