import java.util.*;
import java.io.*;
import java.math.*;

public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        Solver solver = new Solver();
        solver.solve(in, out);
        out.close();
    }
}

class Solver {
    int[] x, y;
    public void solve(InputReader in, PrintWriter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        if (n > 4 && m == 3) {
            out.println(-1);
            return;
        }
        int INF = 100000000;
        int spare = n - m;
        x = new int[n];
        y = new int[n];
        int p = 0;
        int cx, cy;
        cx = 0;
        cy = INF;
        for (int i = 0; i < m; i++) {
            x[p] = cx;
            y[p] = cy;
            p++;
            cy--;
            cx += (i + 1); 
        }
        cx = 0;
        cy = -INF;
        for (int i = 0; i < spare; i++) {
            x[p] = cx;
            y[p] = cy;
            p++;
            cy++;
            cx -= (i + 1); 
        }
        /*
        x[p] = -INF;
        y[p] = -INF;
        p++;
        x[p] = -INF;
        y[p] = INF;
        p++;
        x[p] = INF;
        y[p] = INF;
        p++;*/
        /*
        int fx = 1;
        int fy = 1;
        int cx, cy;
        for (int t = 0; t < 4; t++) {
            int cur = m / 4;//Math.min((m + 3) / 4, rem);
            if (t < m % 4)
                cur++;
            cx = INF - (cur - 1);
            cy = INF;
            for (int i = 0; i < cur; i++) {
                x[p] = fx * cx;
                y[p] = fy * cy;
                p++;
                cx++;
                cy -= (i + 1); 
            }
            fx *= -1;
            int[] w;
            w = x;
            x = y;
            y = w;
            int wf;
            wf = fx;
            fx = fy;
            fy = wf;
        }
        cx = 0;
        cy = 0;
        for (int i = 0; i < spare; i++) {
            if (cy <= 0) {
                cy += (cy > 0)?(1):(-1);
                cx -= (i + 2)*(i + 2) + 10;
            }
            cy = -cy;
            
            x[p] = -INF + cx;
            y[p] = cy;
            p++;
        }*/
        for (int i = 0; i < n; i++) {
            out.format("%d %d\n", x[i], y[i]);
        }
        
        
    }
}

class InputReader {
    private BufferedReader reader;
    private StringTokenizer tokenizer;

    public InputReader(InputStream stream) {
        reader = new BufferedReader(new InputStreamReader(stream));
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

    public long nextLong() {
        return Long.parseLong(next());
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }

    public double nextDouble() {
        return Double.parseDouble(next());
    }
}