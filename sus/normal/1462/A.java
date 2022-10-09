import java.util.*;
import java.io.*;
public class Main {
    public static void main(String[] args) throws IOException{
        Scanner scanner = new Scanner(System.in);
       
        int t = scanner.nextInt();
                
      for(int i = 0; i<t; i++){
      int n = scanner.nextInt();
      int board[] = new int [n];

      for(int j = 0; j<n; j++){
       board[j] = scanner.nextInt();
      }
      if(n==1){
        System.out.print(board[0]);
      }
      else if(n%2!=1){
        for(int y = 0; y<n/2; y++){
      
          System.out.print(board[y]+ " ");
          System.out.print(board[(n-y)-1]+ " ");
        }
      }
      else{
        for(int e = 0; e<n/2+1; e++){
          if(e<n/2){
            System.out.print(board[e]+ " ");
            System.out.print(board[(n-e)-1]+ " ");
            
            
          }
          else {
            int num = board[n/2]+1;
            System.out.print(num-1); }
          
        }

      }
      
      
      System.out.print("\n");
 
 
    }
       

}
}