import java.io.*;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

public class B {

    boolean[] vert(int n, int m, int k, int q, Point[] p) {
        boolean[] ans = new boolean[q];
        Arrays.sort(p);
        ST tree = new ST(100100);
        for (Point x : p) {
            if (x.isPoint()) {
                tree.set(x.y1, x.x1);
            } else {
                int min = tree.get(x.y1, x.y2 + 1);
                if (min < x.x1) continue;
                ans[x.id] = true;
            }
        }
        return ans;
    }

    void solve() throws IOException {
        int n = in.nextInt();
        int m = in.nextInt();
        int k = in.nextInt();
        int q = in.nextInt();
        int[] x = new int[k];
        int[] y = new int[k];
        for (int i = 0; i < k; ++i) {
            x[i] = in.nextInt();
            y[i] = in.nextInt();
        }
        int[] x1 = new int[q];
        int[] y1 = new int[q];
        int[] x2 = new int[q];
        int[] y2 = new int[q];
        for (int i = 0; i < q; ++i) {
            x1[i] = in.nextInt();
            y1[i] = in.nextInt();
            x2[i] = in.nextInt();
            y2[i] = in.nextInt();
        }
        Point[] p1 = new Point[q + k];
        int s1 = 0;
        for (int i = 0; i < k; ++i) {
            p1[s1++] = new Point(x[i], y[i]);
        }
        for (int i = 0; i < q; ++i) {
            p1[s1++] = new Point(x1[i], y1[i], x2[i], y2[i], i);
        }
        boolean[] a1 = vert(n, m, k, q, p1);

        Point[] p2 = new Point[q + k];
        int s2 = 0;
        for (int i = 0; i < k; ++i) {
            p2[s2++] = new Point(y[i], x[i]);
        }
        for (int i = 0; i < q; ++i) {
            p2[s2++] = new Point(y1[i], x1[i], y2[i], x2[i], i);
        }
        boolean[] a2 = vert(m, n, k, q, p2);
        for (int i = 0; i < q; ++i) {
            out.println(a1[i] || a2[i] ? "YES" : "NO");
        }
    }

    static FastReader in;
    static PrintWriter out;
    static PrintStream err;

    public static void main(String[] args) {
        try {
            in = new FastReader();
            out = new PrintWriter(System.out);
            err = System.err;
            new B().solve();
            out.close();
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(1);
        }
    }
}

class FastReader {
    BufferedReader br;
    StringTokenizer st;

    FastReader(InputStream is) {
        br = new BufferedReader(new InputStreamReader(is));
    }

    FastReader() {
        this(System.in);
    }

    FastReader(String file) throws FileNotFoundException {
        this(new FileInputStream(file));
    }

    String nextToken() throws IOException {
        while (st == null || !st.hasMoreElements()) {
            st = new StringTokenizer(br.readLine());
        }
        return st.nextToken();
    }

    int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }
}

class ST {
    int n;
    int[] min;

    ST(int n) {
        this.n = n;
        min = new int[4 * n];
        Arrays.fill(min, Integer.MIN_VALUE);
    }

    int get(int l, int r) {
        return _get(l, r, 0, 0, n);
    }

    int _get(int l, int r, int v, int L, int R) {
        if (l <= L && R <= r) return min[v];
        if (l >= R || L >= r) return Integer.MAX_VALUE;
        int M = (L + R) / 2;
        return Math.min(_get(l, r, 2 * v + 1, L, M),
                        _get(l, r, 2 * v + 2, M, R));
    }

    void set(int pos, int val) {
        _set(pos, val, 0, 0, n);
    }

    void _set(int pos, int val, int v, int l, int r) {
        if (r - l == 1) {
            min[v] = val;
        } else {
            int m = (l + r) / 2;
            if (pos < m) {
                _set(pos, val, 2 * v + 1, l, m);
            } else {
                _set(pos, val, 2 * v + 2, m, r);
            }
            min[v] = Math.min(min[2 * v + 1], min[2 * v + 2]);
        }
    }
}

class Point implements Comparable<Point> {
    int x1, x2, y1, y2;
    int type;

    int id;

    boolean isPoint() {
        return type == -1;
    }

    Point(int x, int y) {
        x1 = x;
        x2 = x;
        y1 = y;
        y2 = y;
        type = -1;
    }

    public Point(int x1, int y1, int x2, int y2, int id) {
        this.x1 = x1;
        this.x2 = x2;
        this.y1 = y1;
        this.y2 = y2;
        this.id = id;
        type = 1;
    }

    int getPos() {
        return x2;
    }

    @Override
    public int compareTo(Point o) {
        if (getPos() != o.getPos()) return Integer.compare(getPos(), o.getPos());
        return Integer.compare(type, o.type);
    }
}