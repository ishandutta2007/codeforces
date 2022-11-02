import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Main {
    static boolean home = true;

    public static void main(String[] args) throws FileNotFoundException {
        InputStream is = home ? System.in : new FileInputStream("decoding.in");
        InputReader in = new InputReader(is);

        OutputStream os = home ? System.out : new FileOutputStream("decoding.out");
        PrintWriter out = new PrintWriter(os);

        int n = in.nextInt();

        int [] s = new int[n];

        for (int i = 0; i < n; ++i) {
            s[i] = in.nextInt();
        }

        int [] st = new int[n + n];
        int [] cnt = new int[n + n];

        int [] gc = new int[n + n];

        for (int i = 0; i < n; ++i) {
            st[i + n] = s[i];
            cnt[i + n] = 1;
            gc[i + n] = s[i];
        }
        for (int i = n - 1; i > 0; --i) {
            st[i] = Math.min(st[i + i], st[i + i + 1]);

            if (st[i] == st[i + i]) cnt[i] += cnt[i + i];
            if (st[i] == st[i + i + 1]) cnt[i] += cnt[i + i + 1];
            gc[i] = gcd(gc[i + i], gc[i + i + 1]);
        }

        int q = in.nextInt();

        while (q-- > 0) {
            int l = in.nextInt() - 1;
            int r = in.nextInt() - 1;

            int min = Integer.MAX_VALUE;
            int count = 0;
            int gcd = 0;

            for (int L = l + n, R = r + n; L <= R; L = (L + 1) >> 1, R = (R - 1) >> 1) {
                if ((L & 1) != 0) {
                    if (st[L] < min) {
                        min = st[L];
                        count = cnt[L];
                    } else {
                        if (st[L] == min) {
                            count += cnt[L];
                        }
                    }
                    gcd = gcd(gcd, gc[L]);
                }
                if ((R & 1) == 0) {
                    if (st[R] < min) {
                        min = st[R];
                        count = cnt[R];
                    } else {
                        if (st[R] == min) {
                            count += cnt[R];
                        }
                    }
                    gcd = gcd(gcd, gc[R]);
                }
            }
            int ans = r - l + 1;
            if (gcd % min == 0) {
                ans -= count;
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

}