import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;


public class Main {

    public static void main(String[] args) throws Exception {
        //InputStream inputStream = new FileInputStream("bluetube.in");//System.in;
        //OutputStream outputStream = new FileOutputStream("bluetube.out");//.out;
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        Solver solver = new Solver();
        int testCount = 1;
        for (int i = 0; i < testCount; ++i) {
            solver.solve(in, out);
        }
        out.close();
    }

}


class Solver {
    final static double eps = 1e-9;

    static class Event implements Comparable<Event> {
        double angle;
        int add;

        Event (double angle, int add) {
            this.angle = angle;
            this.add = add;
        }

        @Override
        public int compareTo(Event o) {
            if (angle + eps < o.angle) {
                return -1;
            }
            if (angle > o.angle + eps) {
                return 1;
            }
            return add - o.add;
        }
    }

    ArrayList<Event> events;

    void addEvent(double left, double right) {
        if (left < -eps) {
            addEvent(left + Math.PI * 2, Math.PI * 2);
            addEvent(0, right);
            return;
        }
        if (right > 2 * Math.PI + eps) {
            addEvent(left, Math.PI * 2);
            addEvent(0, right - 2 * Math.PI);
            return;
        }
        events.add(new Event(left, -1));
        events.add(new Event(right, 1));
    }

    static class Circle {
        double x;
        double y;
        double r;

        Circle(double x, double y, double r) {
            this.x = x;
            this.y = y;
            this.r = r;
        }

        boolean contains(double _x, double _y) {
            return (_x - x) * (_x - x) + (_y - y) * (_y - y) < r * r + eps;
        }
    }

    void addEvent(Circle circle, double startAngle, double radi) {
        double l = 0, r = Math.PI;

        double eps2 = eps / 2;

        while (r - l > eps2) {
            double m = (l + r) / 2;

            if (circle.contains(radi * Math.cos(startAngle + m), radi * Math.sin(startAngle + m))) {
                l = m;
            } else {
                r = m;
            }
        }
        addEvent(startAngle - l, startAngle + l);
    }

    final private static int MAGIC = 13;

    void processCircle(Circle circle, double d) {
        double angle = Math.atan2(circle.y, circle.x);
        if (angle < 0) {
            angle += 2 * Math.PI;
        }

        int dist = (int)(Math.sqrt(circle.x * circle.x + circle.y * circle.y) / d);

        double co = Math.cos(angle);
        double si = Math.sin(angle);

        for (int i = dist - MAGIC; i <= dist + MAGIC; ++i) {
            if (circle.contains(i * d * co, i * d * si)) {
                addEvent(circle, angle, i * d);
            }
        }
    }

    Circle readCircle(InputReader in) {
        double x = in.nextInt();
        double y = in.nextInt();
        double r = in.nextInt();
        return new Circle(x, y, r);
    }

    public void solve(InputReader in, PrintWriter out) throws IOException {
        int n = in.nextInt();
        double d = in.nextInt();
        events = new ArrayList<>();
        for (int i = 0; i < n; ++i) {
            Circle circle = readCircle(in);
            processCircle(circle, d);
        }

        Collections.sort(events);

        int answer = 0;

        int cur = 0;

        for (Event event : events) {
            //System.err.println(event.angle / Math.PI * 180 + " " + event.add);
            cur -= event.add;
            answer = Math.max(answer, cur);
        }
        out.println(answer);
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
                String s = reader.readLine();
                tokenizer = new StringTokenizer(s);
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
    public String nextLine() throws IOException {
        return reader.readLine();
    }
}