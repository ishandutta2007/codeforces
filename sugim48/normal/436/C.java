import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int m = in.nextInt();
        int k = in.nextInt();
        int w = in.nextInt();
        char[][][] a = new char[k][n][m];
        for (int i = 0; i < k; i++) {
            for (int y = 0; y < n; y++) {
                String s = in.next();
                for (int x = 0; x < m; x++) {
                    a[i][y][x] = s.charAt(x);
                }
            }
        }
        
        int[][] l = new int[k][k];
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                for (int y = 0; y < n; y++) {
                    for (int x = 0; x < m; x++) {
                        if (a[i][y][x] != a[j][y][x]) {
                            l[i][j] += w;
                        }
                    }
                }
            }
        }
        
        boolean[] used = new boolean[k];
        int[] L = new int[k];
        Arrays.fill(L, Integer.MAX_VALUE);
        int[] prev = new int[k];
        int ans = 0;
        StringBuilder s = new StringBuilder("");
        for (int K = 0; K < k; K++) {
            int i = -1, min = Integer.MAX_VALUE;
            for (int _i = 0; _i < k; _i++) {
                if (!used[_i] && L[_i] <= min) {
                    i = _i;
                    min = L[_i];
                }
            }
            used[i] = true;
            for (int j = 0; j < k; j++) {
                if (!used[j] && l[i][j] < L[j]) {
                    L[j] = l[i][j];
                    prev[j] = i;
                }
            }
            if (min < m * n) {
                ans += min;
                s.append(i + 1);
                s.append(" ");
                s.append(prev[i] + 1);
                s.append("\n");
            } else {
                ans += m * n;
                s.append(i + 1);
                s.append(" ");
                s.append(0);
                s.append("\n");
            }
        }
        
        System.out.println(ans);
        System.out.print(s);
    }
}