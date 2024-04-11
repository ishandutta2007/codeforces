import java.io.*;
import java.text.DecimalFormat;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner in= new Scanner(System.in);
        int n,t1,t2; double k;
        DecimalFormat df= new DecimalFormat(".00");
        n=in.nextInt(); t1=in.nextInt();
        t2=in.nextInt(); k=in.nextInt();
        k= k/100;
        ArrayList<p> players= new ArrayList<p>();
        for (int i = 0; i < n; i++) {
            int s1= in.nextInt(); int s2= in.nextInt();
            double sum1= (s1*t1)-(s1*t1)*k+(s2*t2);
            double sum2= (s2*t1)-(s2*t1)*k+(s1*t2);
            if(sum1>sum2)
                players.add(new p(i+1,new Double(df.format(sum1)) ));
            else
                players.add(new p(i+1,new Double(df.format(sum2)) ));
        }
        Collections.sort(players);
        for(p pl : players){
            System.out.print(pl.ind+" "+pl.time);
            if(pl.time.toString().split("[.]")[1].length()==1)
                System.out.print("0");
            System.out.print("\n");
        }
        
        
    }
    
    
}

class p implements Comparable<p>{
    int ind;
    Double time;
    p(int i,double d){
        ind=i; time=d;
    }
    
    public int compareTo(p o) {
        if(this.time==o.time){
            return -new Integer(this.ind).compareTo(o.ind);
        }
        return -time.compareTo(o.time);
    }
}