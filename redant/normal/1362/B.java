import java.util.Arrays;
import java.util.Scanner;

public class SolveA {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        for (int kases = scanner.nextInt(); kases > 0; --kases) {
            int n = scanner.nextInt();
            final int M = 1024;
            int[] a = new int[n];
            int[] count = new int[M + 1];
            for (int i = 0; i < n; i++) {
                a[i] = scanner.nextInt();
                count[a[i]]++;
            }

            int ans = -1;
            for (int i = 0; i < n; i++) {
                j: for (int j = 0; j < i; j++) {
                    if (a[i] == a[j])
                        continue;
                    int k = a[i] ^ a[j];
                    if (ans != -1 && ans < k)
                        continue;
                    for (int l = 0; l < n; l++) {
                        int p = a[l] ^ k;
                        if (p > M || count[a[l]] != count[p])
                            continue j;
                    }
                    ans = k;
                }
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