import java.io.* ;
import java.util.*;
public class Main {

  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    for(int i = 0; i<n; i++){
      int x = sc.nextInt();
      int y = sc.nextInt();
      int curx = 0;
      int cury = 0;
      int xcounter = 0;
      int ycounter = 0;
      String seq = sc.next();
      for(int j = 0; j<seq.length(); j++){
        if(x>0){
          if(seq.charAt(j)=='R' && xcounter!=Math.abs(x)){
            xcounter++;
          }
        }
        else if(x<0){
          if(seq.charAt(j)=='L'&& xcounter!=Math.abs(x)){
            xcounter++;
          }
        }

        if(y>0){
          if(seq.charAt(j)=='U'&& ycounter!=Math.abs(y)){
            ycounter++;
          }
        }

        else if(y<0){
          if(seq.charAt(j)=='D'&& ycounter!=Math.abs(y)){
            ycounter++;
          }
        }

    }
    if(xcounter==Math.abs(x) && ycounter==Math.abs(y)){
        System.out.println("yes");

      }

      else{System.out.println("no");}
   
  }
    
       
 
}
}