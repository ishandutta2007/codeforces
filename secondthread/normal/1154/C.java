import java.util.*;
public class c{
    public static void main(String[] args){
        Scanner s=new Scanner(System.in);
        int a=s.nextInt();
        int b=s.nextInt();
        int c=s.nextInt();
        int numfull=Math.min(Math.min(a/3,b/2),c/2);
        numfull--;
        a-=3*numfull;
        b-=2*numfull;
        c-=2*numfull;
        int best=0;
        for(int i=0;i<7;i++){
            int steps=0;
            int aa=a;
            int bb=b;
            int cc=c;int day=i;
            while(aa>=0&&bb>=0&&cc>=0){
                if((day)%7%3==0)aa--;
                else if((day)%7==1||(day)%7==5)bb--;
                else cc--;
                day++;
                steps++;
                if(aa<0||bb<0||cc<0)break;
                best=Math.max(best,steps);
            }
        }System.out.println(best+numfull*7);
    }
}