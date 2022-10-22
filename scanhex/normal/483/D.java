import java.io.*;
import java.util.*;

public class D {
    class IntervalTree {
        int[] d;
        HashSet<Integer> badId;
        int neutral;
        boolean and;
        int cnt = 0;
        int n;

        public IntervalTree(int n, boolean and) {
            this.and = and;
            neutral = and ? Integer.MAX_VALUE : 0;
            d = new int[n * 4];
            this.n = n;
            Arrays.fill(d, neutral);
            badId = new HashSet<Integer>();
        }

        void add(int x) {
            set(x, cnt++, 0, n - 1, 0);
        }

        void remove(int id) {
            set(neutral, id, 0, n - 1, 0);
            badId.add(id);
        }

        int set(int x, int ind, int L, int R, int i) {
            if (L > ind || R < ind)
                return d[i];
            if (L == R) {
                d[i] = badId.contains(ind) ? neutral : x;
                return d[i];
            }
            int M = (R + L) / 2;
            int res = set(x, ind, L, M, (i * 2) + 1);
            if (and)
                res &= set(x, ind, M + 1, R, (i * 2) + 2);
            else
                res |= set(x, ind, M + 1, R, (i * 2) + 2);
            d[i] = res;
            return d[i];
        }

        int get(int l, int r, int L, int R, int i) {
            if (R < l || L > r)
                return neutral;
            if (l <= L && r >= R)
                return d[i];
            if (L == R) {
                if (badId.contains(L))
                    d[i] = neutral;
                return d[i];
            }
            int M = (R + L) / 2;
            if (and)
                return get(l, r, L, M, (i * 2) + 1) & get(l, r, M + 1, R, (i * 2) + 2);
            else
                return get(l, r, L, M, (i * 2) + 1) | get(l, r, M + 1, R, (i * 2) + 2);
        }
    }

    class Interval {
        int l, r, q;

        Interval(int l, int r, int q) {
            this.l = l;
            this.r = r;
            this.q = q;
        }
    }

    class Event implements Comparable<Event> {
        int coord, q, itid;
        Event pair;

        Event(int coord, int id, boolean begin, int q) {
            this.coord = coord;
            this.id = id;
            this.begin = begin;
            this.q = q;
        }

        int id;
        boolean begin;

        @Override
        public int compareTo(Event o) {
            if (this.coord != o.coord)
                return this.coord - o.coord;
            if (!this.begin && o.begin)
                return 1;
            if (begin && !o.begin)
                return -1;
            if (this.id != o.id)
                return id - o.id;
            return 0;
        }
    }

    BufferedReader br;
    StringTokenizer in;
    PrintWriter out;

    public String nextToken() throws IOException {
        while (in == null || !in.hasMoreTokens()) {
            in = new StringTokenizer(br.readLine());
        }
        return in.nextToken();
    }

    public int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    public double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }

    public long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }

    public static void main(String[] args) throws IOException {
        new D().run();
    }

    public void solve() throws IOException {
        int n = nextInt();
        int m = nextInt();
        Event[] events = new Event[m << 1];
        Interval[] intervals = new Interval[m];
        for (int i = 0; i < m; ++i) {
            int l = nextInt() - 1;
            int r = nextInt() - 1;
            int q = nextInt();
            intervals[i] = new Interval(l, r, q);
            events[i * 2] = new Event(l, i, true, q);
            events[(i * 2) + 1] = new Event(r, i, false, q);
            events[i * 2].pair = events[(i * 2) + 1];
            events[(i * 2) + 1].pair = events[i * 2];
        }
        Arrays.sort(events);
        int[] a = new int[n];
        int cnt = 0;
        IntervalTree it = new IntervalTree(m, false);
        TreeSet<Event> ts = new TreeSet<Event>(new Comparator<Event>() {
            @Override
            public int compare(Event o1, Event o2) {
                if (o1.q != o2.q)
                    return o1.q - o2.q;
                return o1.id - o2.id;
            }
        });
        for (int i = 0; i < n; ++i) {
            while (cnt < (m * 2) && events[cnt].coord == i && events[cnt].begin) {
                it.add(events[cnt].q);
                ts.add(events[cnt]);
                events[cnt].itid = it.cnt - 1;
                ++cnt;
            }
            a[i] = ts.size() == 0 ? 239 : it.get(0, m - 1, 0, m - 1, 0);

            while (cnt < (m * 2) && events[cnt].coord == i) {
                it.remove(events[cnt].pair.itid);
                ts.remove(events[cnt].pair);
                ++cnt;
            }
        }
        IntervalTree it1 = new IntervalTree(n, true);
        for (int i = 0; i < n; ++i)
            it1.add(a[i]);
        for (int i = 0; i < m; ++i)
            if (intervals[i].q != it1.get(intervals[i].l, intervals[i].r, 0, n - 1, 0)) {
                out.print("NO");
                return;
            }

        out.println("YES");
        for (int i : a) {
            out.print(i + " ");
        }
    }

    public void run() {
        try {
            br = new BufferedReader(new InputStreamReader(System.in));
            out = new PrintWriter(System.out);
            solve();

            out.close();
        } catch (IOException e) {
            e.printStackTrace();
            System.exit(1);
        }
    }
}