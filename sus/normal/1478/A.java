import java.util.*;
import java.io.*;
public class Main {
    public static void main(String[] args) {
      Scanner sc = new Scanner(System.in);
      int n = sc.nextInt();

      for (int i=0; i<n; i++){
        int max = 0;
        int count = 0;
        int k = sc.nextInt();
        int[] balls = new int[k];
        for(int j = 0; j<k; j++){
          balls[j] = sc.nextInt();
        }
        
        for(int f = 0; f<k; f++){
          int x = balls[f];
         
          count = 0;
          
          for(int g = 0; g<k; g++){
            if(balls[g] == x){
              count++;
             
              if(count>=max){
                max = count;
                
              }
           }
        }
        }

        System.out.println(max);
      }

  }
       
 
}