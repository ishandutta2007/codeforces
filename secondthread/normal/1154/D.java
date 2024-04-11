import java.util.*;

public class D {
    public static void main (String[] args ) {
        Scanner fs=new Scanner(System.in);
        int n=fs.nextInt();
        int b=fs.nextInt();
        int bCap=b;
        int a=fs.nextInt(); int aCap=a;
        boolean[] sun=new boolean[n];
        for (int i=0; i<n; ++i){
            sun[i]=fs.nextInt()==1;
            
        }
        int dist=0;
        while (dist<n&&(Math.max(a, b)>0)) {
            if (a==aCap){ 
                a--;
            }
            else {
                if (sun[dist]) {
                    if (b>0) {
                        b--;
                        a=Math.min(a+1, aCap);
                    }
                    else a--;
                    
                }
                else {
                    if (a>0) a--;
                    else b--;
                }
            }
            dist++;
            
        }
        System.out.println(dist);
        
    }
}