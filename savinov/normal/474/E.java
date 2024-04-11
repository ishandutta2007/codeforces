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

        long [] s = new long[n];
        long [] x = new long[n];

        long d = in.nextLong();

        for (int i = 0; i < n; ++i) {
            x[i] = s[i] = in.nextLong();
        }

        Arrays.sort(x);

        long [] y = new long[n];

        int sz = 0;

        for (int i = 0; i < n; ++i) {
            int j = i;

            while (j < n && x[i] == x[j]) {
                ++j;
            }
            y[sz++] = x[i];
            i = j - 1;
        }



        int [] ma = new int[sz + sz];
        int [] pos = new int[sz + sz];
        Arrays.fill(pos, -1);
        int [] parent = new int[n];
        int [] dp = new int[n];

        int best = 0, po = -1;

        for (int i = 0; i < n; ++i) {

            int lo = -1;
            int hi = sz - 1;

            while (lo < hi) {
                int mid = (lo + hi + 1) >> 1;
                if (y[mid] > s[i] - d) {
                    hi = mid - 1;
                } else {
                    lo = mid;
                }
            }

            int l = lo;

            lo = 0;
            hi = sz;

            while (lo < hi) {
                int mid = (lo + hi) >> 1;
                if (y[mid] < s[i] + d) {
                    lo = mid + 1;
                } else {
                    hi = mid;
                }
            }

            int r = lo;
//
//            System.err.println(i + 1 + " " + s[i]);
//            System.err.println("LOWER");
//            for (int j = 0; j <= l; ++j) {
//                System.err.print(y[j] + " ");
//            }
//            System.err.println();
//            System.err.println("HIGHER");
//            for (int j = r; j < sz; ++j) {
//                System.err.print(y[j] + " ");
//            }
//            System.err.println();

            int val = 0;
            int prev = -1;

            //prefix

            for (int L = 0 + sz, R = l + sz; L <= R; L = (L + 1) >> 1, R = (R - 1) >> 1) {
                if ((L & 1) != 0) {
                    if (ma[L] > val) {
                        val = ma[L];
                        prev = pos[L];
                    }
                }
                if ((R & 1) == 0) {
                    if (ma[R] > val) {
                        val = ma[R];
                        prev = pos[R];
                    }
                }
            }

            //suffix

            for (int L = r + sz, R = sz - 1 + sz; L <= R; L = (L + 1) >> 1, R = (R - 1) >> 1) {
                if ((L & 1) != 0) {
                    if (ma[L] > val) {
                        val = ma[L];
                        prev = pos[L];
                    }
                }
                if ((R & 1) == 0) {
                    if (ma[R] > val) {
                        val = ma[R];
                        prev = pos[R];
                    }
                }
            }

            ++val;
            parent[i] = prev;
            dp[i] = val;

            if (val > best) {
                best = val;
                po = i;
            }

            int p = Arrays.binarySearch(y, 0, sz, s[i]) + sz;

            if (ma[p] < val) {
                ma[p] = val;
                pos[p] = i;
            }

            for (p >>= 1; p > 0; p >>= 1) {
                int t = Math.max(ma[p + p], ma[p + p + 1]);
                ma[p] = t;
                if (ma[p + p] == t) {
                    pos[p] = pos[p + p];
                } else {
                    pos[p] = pos[p + p + 1];
                }
            }
        }
        sz = 0;

        while (po != -1) {
            x[sz++] = po + 1;
            po = parent[po];
        }

        out.println(sz);

        while (sz > 0) {
            out.print(x[--sz] + " ");
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