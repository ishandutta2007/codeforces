/**
 * Created by Alex on 7/9/2014.
 */

import java.io.*;
import java.util.*;

public class BStress {
    class Event implements Comparable<Event> {
        int coord;
        int type;
        int id;
        Shelf shelf;

        public Event(int coord, int type, int id, Shelf shelf) {
            this.coord = coord;
            this.type = type;
            this.id = id;
            this.shelf = shelf;
        }

        @Override
        public int compareTo(Event o) {
            if (coord != o.coord) return coord - o.coord;
            if (type != o.type) return o.type - type;
            return id - o.id;
        }
    }

    class Shelf implements Comparable<Shelf> {
        int h;
        int id;
        int d = -1;
        Shelf right;

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;

            Shelf shelf = (Shelf) o;

            if (h != shelf.h) return false;
            if (l != shelf.l) return false;
            if (r != shelf.r) return false;

            return true;
        }

        @Override
        public int hashCode() {
            int result = h;
            result = 239 * result + l;
            result = 239 * result + r;
            return result;
        }

        public Shelf(int h, int l, int r, int id) {
            this.h = h;
            this.l = l;
            this.r = r;
            this.id = id;
            children = new HashSet<Shelf>();
        }

        int l;
        int r;
        HashSet<Shelf> children;

        @Override
        public int compareTo(Shelf o) {
            return h - o.h;
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
        new BStress().run();
    }

    int intersects(Shelf a, Shelf b) {
        return Math.min(a.r, b.r) - Math.max(a.l, b.l);
    }

    boolean intersect3d(Shelf a, Shelf b) {
        return a.h > b.h && intersects(a, b) > 0;
    }

    ArrayList<Shelf> fast(ArrayList<Shelf> a) {
        ArrayList<Shelf> shelfs = new ArrayList<Shelf>(a);
        ArrayList<Event> events = new ArrayList<Event>();
        for (Shelf sh : shelfs) {
            events.add(new Event(sh.l, -1, sh.id, sh));
            events.add(new Event(sh.r, 1, sh.id, sh));
        }
        TreeSet<Shelf> cur = new TreeSet<Shelf>(new Comparator<Shelf>() {
            @Override
            public int compare(Shelf o1, Shelf o2) {
                if (o1.h != o2.h) return o1.h - o2.h;
                return o1.id - o2.id;
            }
        });
        Collections.sort(events);
        for (Event x : events) {
            if (x.type == -1) {
                Shelf parent = cur.higher(x.shelf);
                if (x.id == 1)
                    System.out.println();
                if (parent != null) {
                    if (parent.right == null)
                        parent.right = x.shelf;
                    else {
                        if (intersects(parent.right, x.shelf) > 0) {
                            if (x.shelf.h > parent.right.h) {
                                parent.children.remove(parent.right);
                                parent.right = x.shelf;
                                parent.children.add(x.shelf);
                            }
                        } else {
                            parent.right = x.shelf;
                            parent.children.add(x.shelf);
                        }
                    }
                }
                Shelf child = cur.lower(x.shelf);
                if (child != null) {
                    x.shelf.children.add(child);
                    x.shelf.right = child;
                }
                cur.add(x.shelf);
            } else
                cur.remove(x.shelf);
        }
        return shelfs;
    }



    public void solve() throws IOException {
        int n = nextInt();
        int t = nextInt();
        ArrayList<Shelf> shelfs = new ArrayList<Shelf>();
        for (int i = 0; i < n; ++i)
            shelfs.add(new Shelf(nextInt(), nextInt(), nextInt(), i));
        shelfs.add(new Shelf(t, (int) -1e9, (int) 1e9, -1));
        shelfs.add(new Shelf(0, (int) -1e9, (int) 1e9, -2));
        ArrayList<Shelf> fast = fast(shelfs);
        Collections.sort(fast);
        fast.get(0).d = Integer.MAX_VALUE;
        for (Shelf x : fast) {
            for (Shelf y : x.children)
                if (Math.min(y.d, intersects(x, y)) > x.d)
                    x.d = Math.min(y.d, intersects(x, y));
        }
        out.print(fast.get(fast.size() - 1).d);
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