import java.util.*;
public class A{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int t = sc.nextInt();
        
        for (int z = 1; z <=t; z ++) {
            long val = sc.nextLong();
            int count = 0;
            while (val % 5 == 0) {
                count ++;
                val /= 5;
                val*=4l;
                
            }
            while(val%3 == 0) {
                val/=3;
                val*=2;
                count++;
            }
            while(val%2==0){
                count++;
                val/=2;
                
            
            }
            if (val!=1) {
                System.out.println("-1");
            }
            else 
            System.out.println(count);
        }
    }
}