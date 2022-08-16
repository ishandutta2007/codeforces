import java.util.Scanner;

public class SolveA {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        for (int kases = scanner.nextInt(); kases > 0; --kases) {
            long n = scanner.nextLong();
            long ans = 0;
            while (n > 0) {
                ans += n;
                n /= 2;
            }

            System.out.println(ans);
        }
    }

    private static int solve(long a, long b) {
        if (a == b) {
            return 0;
        }

        if (a < b) {
            long temp = a;
            a = b;
            b = temp;
        }

        int steps = 0;
        while (a > b) {
            b <<= 1;
            steps++;
            // System.out.println(a + " , " + b);
        }

        if (a != b)
            return -1;

        return steps / 3 + (steps % 3 != 0 ? 1 : 0);
    }

}