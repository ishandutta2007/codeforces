import java.util.*;
public class a{
    public static void main(String[] args){
        Scanner s=new Scanner(System.in);
        int ab=s.nextInt();
        int ac=s.nextInt();
        int bc=s.nextInt();
        int abc=s.nextInt();
 //       System.out.println(abc-bc+" "+(abc-ac)+" "+(abc-ab));
        int max=Math.max(Math.max(ab,ac),Math.max(bc,abc));
        int[] arr={ab,bc,ac,abc};
        Arrays.sort(arr);
        System.out.println(max-arr[0]+" "+(max-arr[1])+" "+(max-arr[2]));           
    }    
}