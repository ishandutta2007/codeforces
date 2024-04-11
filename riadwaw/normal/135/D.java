import java.io.*;

import java.awt.geom.Point2D;
import java.text.*;
import java.math.*;
import java.util.*;

public class Main implements Runnable {

        final String filename = "";

        public void solve() throws Exception {
                n = iread();
                m = iread();
                field = new int[n][m];
                color = new int[n][m];
                int num = 0;
                for (int i = 0; i < n; i++) {
                        String s = readword();
                        for (int j = 0; j < m; j++) {
                                field[i][j] = s.charAt(j) - '0';
                        }
                }
                qx = new int[n * m];
                qy = new int[n * m];

                int ans = 0;
                for (int i = 0; i < n; i++)
                        cycle: for (int j = 0; j < m; j++) {
                                if (field[i][j] == 0) {
                                        if (color[i][j] == 0) {
                                                num++;
                                                s = 0;
                                                side = false;
                                                dfs(i, j, num);
                                                if (!side) {

                                                        for (int r = 0; r < s; r++) {
                                                                int ss = 0;
                                                                int x1 = qx[r], y1 = qy[r];
                                                                for (int dx = -1; dx <= 1; dx++)
                                                                        for (int dy = -1; dy <= 1; dy++)
                                                                                if (dx * dy == 0 && dx * dx + dy * dy != 0) {
                                                                                        int x2 = x1 + dx, y2 = y1 + dy;
                                                                                        if (x2 >= 0 && x2 < n && y2 >= 0 && y2 < m) {
                                                                                                if (field[x2][y2] == 1 && color[x2][y2] == num)
                                                                                                        ss++;
                                                                                        }
                                                                                }
                                                                if (ss != 2)
                                                                        continue cycle;
                                                        }

                                                        s2 = 0;
                                                        dfs2(qx[0], qy[0], num);
                                                        if (s2 == s) {
//                                                              System.out.println("found " + s);
                                                                ans = Math.max(ans, s);
                                                        }
                                                }
                                        }
                                } else {
                                        if (i + 1 < n && j + 1 < m) {
                                                if (field[i + 1][j + 1] == 1 && field[i][j + 1] == 1 && field[i + 1][j] == 1) {
                                                        ans = Math.max(ans, 4);
                                                }
                                        }
                                }
                        }
                out.write(ans + "\n");
        }

        boolean side;
        int[][] color;
        int[][] field;
        int[] qx, qy;
        int n, m;
        int s;

        void dfs(int x, int y, int clr) {
                if (x < 0 || x >= n || y < 0 || y >= m) {
                        side = true;
                        return;
                }
                if (field[x][y] != 0) {
                        if (color[x][y] != clr) {
                                color[x][y] = clr;
                                qx[s] = x;
                                qy[s] = y;
                                s++;
                        }
                        return;
                }
                if (color[x][y] != 0)
                        return;
                color[x][y] = clr;
                for (int dx = -1; dx <= 1; dx++)
                        for (int dy = -1; dy <= 1; dy++) {
                                dfs(x + dx, y + dy, clr);
                        }
        }

        int s2;

        void dfs2(int x, int y, int clr) {
                if (x < 0 || x >= n || y < 0 || y >= m) {
                        return;
                }
                if (field[x][y] == 0)
                        return;
                if (color[x][y] != clr)
                        return;
                s2++;
                color[x][y] = 0;
                for (int dx = -1; dx <= 1; dx++)
                        for (int dy = -1; dy <= 1; dy++) {
                                dfs2(x + dx, y + dy, clr);
                        }
        }

        public void run() {
                try {
                        in = new BufferedReader(new InputStreamReader(System.in));
                        out = new BufferedWriter(new OutputStreamWriter(System.out));
                        // in = new BufferedReader(new FileReader(filename+".in"));
                        // out = new BufferedWriter(new FileWriter(filename+".out"));
                        solve();
                        out.flush();
                } catch (Exception e) {
                        e.printStackTrace();
                        System.exit(1);
                }
        }

        public int iread() throws Exception {
                return Integer.parseInt(readword());
        }

        public double dread() throws Exception {
                return Double.parseDouble(readword());
        }

        public long lread() throws Exception {
                return Long.parseLong(readword());
        }

        BufferedReader in;

        BufferedWriter out;

        public String readword() throws IOException {
                StringBuilder b = new StringBuilder();
                int c;
                c = in.read();
                while (c >= 0 && c <= ' ')
                        c = in.read();
                if (c < 0)
                        return "";
                while (c > ' ') {
                        b.append((char) c);
                        c = in.read();
                }
                return b.toString();
        }

        public static void main(String[] args) {
                try {
                        Locale.setDefault(Locale.US);
                } catch (Exception e) {

                }
                // new Thread(new Main()).start();
                new Thread(null, new Main(), "1", 1 << 26).start();
        }
}