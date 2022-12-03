import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        long x = in.nextInt();
        Long[] c = new Long[n];
        for (int i = 0; i < n; i++) {
            c[i] = in.nextLong();
        }
        
        Arrays.sort(c);
        long ans = 0;
        for (int i = 0; i < n; i++) {
            ans += c[i] * x;
            x = Math.max(1, x - 1);
        }
        
        System.out.println(ans);
    }
}