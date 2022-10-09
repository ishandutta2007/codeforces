import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner (System.in);
        int t = scanner.nextInt();
    for(int i = 0; i<t; i++){
      int n = scanner.nextInt();
      int k = scanner.nextInt();
      String num = "";
        for (int c = 0; c < k; c++){
          num = num + "a";
        }
 
        int counter = 0;
        for(int x = 0; x<n-k; x++){
            if(counter==0){
            num = num + 'b';
            counter+=1;
            }
            else if(counter==1){
            num = num + ('c');
            counter+=1;
 
            }
            else{
            num = num + ('a');
            counter = 0;
            }
 
        }
      System.out.println(num);
 
 
    }
}
}