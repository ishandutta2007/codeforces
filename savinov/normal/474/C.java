import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Main {
    static boolean home = true;

    static int [] rotate(int [] a, int [] b) {
        int dx = a[0] - b[0];
        int dy = a[1] - b[1];

        int [] res = new int[2];
        res[0] = b[0] - dy;
        res[1] = b[1] + dx;

        return res;
    }


    public static void main(String[] args) throws FileNotFoundException {
        InputStream is = home ? System.in : new FileInputStream("decoding.in");
        InputReader in = new InputReader(is);

        OutputStream os = home ? System.out : new FileOutputStream("decoding.out");
        PrintWriter out = new PrintWriter(os);

        int n = in.nextInt();

        int [][][] homes = new int[n][4][2];
        int [][][] positions = new int[n][4][2];

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 4; ++j) {
                for (int k = 0; k < 2; ++k) {
                    positions[i][j][k] = 4 * in.nextInt();
                }
                for (int k = 0; k < 2; ++k) {
                    homes[i][j][k] = 4 * in.nextInt();
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            int ans = Integer.MAX_VALUE;
            for (int m1 = 0; m1 < 4; ++m1, positions[i][0] = rotate(positions[i][0], homes[i][0])) {
                for (int m2 = 0; m2 < 4; ++m2, positions[i][1] = rotate(positions[i][1], homes[i][1])) {
                    for (int m3 = 0; m3 < 4; ++m3, positions[i][2] = rotate(positions[i][2], homes[i][2])) {
                        for (int m4 = 0; m4 < 4; ++m4, positions[i][3] = rotate(positions[i][3], homes[i][3])) {
                            int [] s = new int[2];
                            for (int j = 0; j < 4; ++j) {
                                for (int k = 0; k < 2; ++k) {
                                    s[k] += positions[i][j][k];
                                }
                            }
                            s[0] /= 4;
                            s[1] /= 4;

                            int [][] delta = new int[4][2];

                            boolean ok = true;

                            for (int j = 0; j < 4; ++j) {
                                for (int k = 0; k < 2; ++k) {
                                    delta[j][k] = positions[i][j][k] - s[k];

                                }
                                if (delta[j][0] == 0 && delta[j][1] == 0) {
                                    ok = false;
                                }
                            }

                            int [] x = delta[0];

                            for (int j = 0; j < 4; ++j) {
                                boolean f = false;
                                for (int k = 0; k < 4; ++k) {
                                    f |= Arrays.equals(x, delta[k]);
                                }
                                ok &= f;
                                x = rotate(x, new int[2]);
                            }
                            if (ok) {
                                ans = Math.min(ans, m1 + m2 + m3 + m4);
                            }
                        }
                    }
                }
            }
            if (ans == Integer.MAX_VALUE) {
                ans = -1;
            }
            out.println(ans);
        }

        out.close();
    }

    private static int gcd(int a, int b) {
        while (b > 0) {
            a %= b;
            a ^= b;
            b ^= a;
            a ^= b;
        }
        return a;
    }

}

class InputReader {
    public BufferedReader reader;
    public StringTokenizer tokenizer;

    public InputReader(InputStream stream) {
        reader = new BufferedReader(new InputStreamReader(stream), 32768);
        tokenizer = null;
    }

    public String next() {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            try {
                tokenizer = new StringTokenizer(reader.readLine());
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
        return tokenizer.nextToken();
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }

    public long nextLong() {
        return Long.parseLong(next());
    }
}