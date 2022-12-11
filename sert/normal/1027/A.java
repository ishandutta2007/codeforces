import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
	// write your code here
        Scanner in = new Scanner(System.in);
        int t = new Integer(in.nextLine());
        for (int it = 0; it < t; it++) {
            int n = new Integer(in.nextLine());
            String s = in.nextLine();

            int ok = 1;
            for (int i = 0; i < n / 2; i++) {
                int a = s.charAt(i) - 'a';
                int b = s.charAt(n - i - 1) - 'a';
                if (a != b && a - b != 2 && b - a != 2) {
                    ok = 0;
                }
            }
            if (ok == 1) System.out.println("YES");
            else System.out.println("NO");
        }
        //System.out.println("Kek!");
    }
}