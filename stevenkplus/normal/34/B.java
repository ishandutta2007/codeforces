import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;


public class B034
{
    public static void main(String[] args) throws Exception {
        Scanner in = new Scanner(System.in);
        int n= in.nextInt(),m=in.nextInt();
        ArrayList<Integer> ar = new ArrayList<Integer>();
        for(int x=0;x<n;x++) {
            int r = in.nextInt();
            if(r<0)ar.add(r);
        }
        Collections.sort( ar );
        int sum = 0;
        for(int x=0;x<m&&x<ar.size();x++) {
            sum-=ar.get( x );
        }
        System.out.println(sum);
        
    }
}