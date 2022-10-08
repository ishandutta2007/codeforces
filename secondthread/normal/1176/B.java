    import java.util.*;
     
    public class B {
        public static void main(String[] args) {
            Scanner fs=new Scanner(System.in);
        
            int T=fs.nextInt();
            for (int tt=0; tt<T; tt++) {
                int n=fs.nextInt();
                int [] a=new int[3];
                for (int i=0; i<n; i++) a[fs.nextInt()%3]++;
                int c=0;
                c+=a[0];
                c+=Math.min(a[1], a[2]);
                int sub=Math.min(a[1], a[2]);
                a[1]-=sub;
                a[2]-=sub;
                c+=a[1]/3;
                c+=a[2]/3;
                System.out.println(c);
            }
        }
    }