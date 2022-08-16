import java.util.Scanner;

public class SolveA {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        for (int kases = scanner.nextInt(); kases > 0; --kases) {
            int n = scanner.nextInt();

            int[] res = new int[4];
            int k = 0;
            for (int m = n, p10 = 1; m > 0; m /= 10, p10 *= 10) {
                int c = (m % 10) * p10;
                if (c > 0)
                    res[k++] = c;
            }

            System.out.println(k);
            for (int i = k - 1; i >= 0 ; i--) {
                System.out.print(res[i] + " ");
            }
            System.out.println();
        }
    }
}