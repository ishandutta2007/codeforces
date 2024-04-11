import java.util.*;
import java.io.*;

public class Main{
  public static void main(String[] args) throws IOException{
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();

    for(int i=0; i<n; i++){
      int m = sc.nextInt();
      int numbers[] = new int[m];
      for(int j=0; j<m; j++){
        numbers[j]=sc.nextInt();
      }
      int shawty = 1;
      for(int o=0; o<m; o++){
        if(o==0){
          if(numbers[o]!=numbers[o+1] && numbers[o] != numbers[o+2]){
            System.out.println(o+1);
            shawty = 0;
          }
        }
        else if(o!=0 && o!=m-1 && shawty != 0){
            if(numbers[o]!=numbers[o+1] && numbers[o] != numbers[o-1]){
            System.out.println(o+1);
            shawty = 0;
          }
        }
        else if(o==m-1 && shawty!=0){System.out.println(o+1);}
      }
   }
  }
}