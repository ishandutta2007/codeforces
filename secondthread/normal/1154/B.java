import java.util.*;

public  class B {
    public static void main(String[] args) {
        Scanner s=new Scanner(System.in);
        TreeSet<Integer> ts=new TreeSet<>();
        int n=s.nextInt();
        for (int i=0; i<n; i++) ts.add(s.nextInt());
        if (ts.size()==2) {
            if ((ts.last()-ts.first())%2==0) {
                System.out.println((ts.last()-ts.first())/2);
            }else {
                System.out.println(ts.last()-ts.first());
            }
        } else if (ts.size()==1) {
            System.out.println(0);
        }
        else if (ts.size()==3) {
            int d1=ts.last()-ts.first();
            ts.remove(ts.first());
            int d2=ts.last()-ts.first();
            if (d1==d2*2) {
                System.out.println(d2);
            }
            else {
              System.out.println(-1);  
            }
        }
        else {
            System.out.println(-1);  
        }
    }
}