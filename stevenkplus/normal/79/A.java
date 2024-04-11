import java.util.Scanner;


public class A079
{
    public static void main(String[] args) throws Exception {
        Scanner in = new Scanner(System.in);
        int x= in.nextInt();
        int y =  in.nextInt();
        String res = "Ciel";
        for(int i = 0;true;i++) {
            if(x>=2) {
                x-=2;
                y-=2;
            }
            else {
                if(x==1) {
                    x--;
                    y-=12;
                }
                else
                    y-=22;
                
            }
            if(y<0) {res = "Hanako"; break;}
            
            
            if(y>=22) y-=22;
            else {
                if(y>=12) {y-=12;x--;}
                else if(y>=2) {y-=2; x-=2;}
                else break;
            }
            if(x<0) break;
         
        }
        System.out.println(res);
    }
}