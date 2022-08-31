import java.util.Scanner;

public class SolveA {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        for (int kases = scanner.nextInt(); kases > 0; --kases) {
            int n = scanner.nextInt();
            int k = scanner.nextInt();
            System.out.println(solve(n, k));
        }
    }

    private static int solve(int n, int k) {
        int p = (k - 1) / (n - 1);
        int q = (k - 1) % (n - 1);
        return p * n + q + 1;
    }
}