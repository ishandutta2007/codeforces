import java.util.Scanner;

public class SolveA {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        for (int kases = scanner.nextInt(); kases > 0; --kases) {
            int n = scanner.nextInt();
            int k = scanner.nextInt();
            if (!solve(n, k)) {
                System.out.println("NO");
            }
        }
    }

    private static boolean solve(int n, int k) {
        if (k > n)
            return false;

        int[] res = new int[k];

        if (k == 1) {
            res[0] = n;
        } else if (n % 2 == 1) {
            if (k % 2 != 1)
                return false;
            for (int i = 0; i < k; i++) {
                res[i] = 1;
            }
            res[0] += n - k;
        } else {
            // odds
            if ((n - k) % 2 == 0) {
                for (int i = 0; i < k; i++) {
                    res[i] = 1;
                }
                res[0] += n - k;
            } else if (n >= 2 * k && (n - 2 * k) % 2 == 0) {
                for (int i = 0; i < k; i++) {
                    res[i] = 2;
                }
                res[0] += n - 2 * k;
            } else {
                return false;
            }
        }

        System.out.println("YES");
        for (int i = 0; i < k; i++) {
            System.out.print(res[i] + " ");
        }
        System.out.println();
        return true;
    }
}