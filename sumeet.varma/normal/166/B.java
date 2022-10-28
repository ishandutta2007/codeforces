
import java.util.Arrays;
import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner s = new Scanner(System.in);
    int n = s.nextInt();
    
    Point point[] = new Point[n];
    for (int i = 0; i < n; i++)
      point[i] = new Point(s.nextInt(), s.nextInt());
    
    PointInPolygonQuery pointInPolygonQuery = new PointInPolygonQuery(point);
    
    boolean ans = true;
    
    int m = s.nextInt();
    
    while (m-- > 0) {
      Point q = new Point(s.nextInt(), s.nextInt());
      ans &= pointInPolygonQuery.query(q) > 0;
    }
    
    System.out.println(ans ? "YES" : "NO");
    
    /*Polygon[] p = new Polygon[n];
    for (int i = 0; i < n; i++) {
      int c = s.nextInt();
      Point[] h = new Point[c];
      for (int j = 0; j < c; j++) {
        h[j] = new Point(s.nextInt(), s.nextInt());
      }
      p[i] = new Polygon(h);
    }
    Polygon ans = p[0];
    for (int i = 1; i < n; i++) {
      //      System.out.println(ans);
      //      System.out.println("Adding -- > " + p[i].toString());
      ans = ans.intersection(p[i]);
    }
    //    System.out.println(ans);
    System.out.println(Math.abs(ans.area() * 1.0 / 2));*/
  }

  public static class Polygon {

    @Override
    public String toString() {
      return "Polygon [p=" + Arrays.deepToString(p) + "]";
    }

    int n;
    Point p[];

    public Polygon(Point[] p) {
      this.n = p.length;
      this.p = p;
    }

    public int next(int i) {
      return i == n - 1 ? 0 : (i + 1);
    }

    public int prev(int i) {
      return i == 0 ? (n - 1) : (i - 1);
    }

    public long area() {
      long area = 0;
      for (int i = 0; i < n; ++i)
        area += p[i].x * (p[prev(i)].y - p[next(i)].y);
      return area;
    }

    public Polygon intersection(Polygon o) {
      Point[] newpoints = new Point[n * o.n + n + o.n];
      int ptr = 0;
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < o.n; j++) {
          Point p1 = p[i];
          Point p2 = p[next(i)];
          Point p3 = o.p[j];
          Point p4 = o.p[o.next(j)];
          Line l1 = new Line(p1, p2);
          Line l2 = new Line(p3, p4);
          Point xx = l1.intersect(l2);
          if (xx != null) {
            if (xx.x >= Math.min(p1.x, p2.x) && xx.x <= Math.max(p1.x, p2.x) && xx.y >= Math.min(p1.y, p2.y)
                && xx.y <= Math.max(p1.y, p2.y)) {
              if (xx.x >= Math.min(p3.x, p4.x) && xx.x <= Math.max(p3.x, p4.x) && xx.y >= Math.min(p3.y, p4.y)
                  && xx.y <= Math.max(p3.y, p4.y)) {
                if (xx.x == p1.x && xx.y == p1.y)
                  continue;
                if (xx.x == p2.x && xx.y == p2.y)
                  continue;
                if (xx.x == p3.x && xx.y == p3.y)
                  continue;
                if (xx.x == p4.x && xx.y == p4.y)
                  continue;
                newpoints[ptr++] = xx;
              }
            }
          }
        }
      }
      //      System.out.println(Arrays.deepToString(Arrays.copyOf(newpoints, ptr)));
      PointInPolygonQuery pq = new PointInPolygonQuery(p);
      for (int i = 0; i < o.n; i++) {
        if (pq.query(o.p[i]) >= 0) {
          newpoints[ptr++] = o.p[i];
        }
      }
      //      System.out.println(Arrays.deepToString(Arrays.copyOf(newpoints, ptr)));
      pq = new PointInPolygonQuery(o.p);
      for (int i = 0; i < n; i++) {
        if (pq.query(p[i]) >= 0) {
          newpoints[ptr++] = p[i];
        }
      }
      //      System.out.println(Arrays.deepToString(Arrays.copyOf(newpoints, ptr)));
      return new Polygon(new PointInPolygonQuery(Arrays.copyOf(newpoints, ptr)).total);
    }
  }

  static class PointInPolygonQuery {
    Point[] upper, lower, total;
    double minx = Integer.MAX_VALUE;
    double maxx = Integer.MIN_VALUE;
    double miny1 = Integer.MAX_VALUE;
    double miny2 = Integer.MIN_VALUE;
    double maxy1 = Integer.MAX_VALUE;
    double maxy2 = Integer.MIN_VALUE;

    PointInPolygonQuery(Point[] p) {
      findHull(p);
      total = new Point[upper.length + lower.length - 2];
      int ptr = 0;
      for (int i = 0; i < lower.length - 1; i++) {
        total[ptr++] = lower[i];
      }
      for (int i = 0; i < upper.length - 1; i++) {
        total[ptr++] = upper[i];
      }
      total = Arrays.copyOf(total, ptr);
      for (int i = 0; i < (upper.length + 1) / 2; i++) {
        Point temp = upper[i];
        upper[i] = upper[upper.length - 1 - i];
        upper[upper.length - 1 - i] = temp;
      }
      for (int i = 0; i < total.length; i++) {
        if (total[i].x < minx) {
          minx = total[i].x;
        }
        if (total[i].x > maxx) {
          maxx = total[i].x;
        }
      }
      for (int i = 0; i < total.length; i++) {
        if (total[i].x == minx) {
          miny1 = Math.min(miny1, total[i].y);
          miny2 = Math.max(miny2, total[i].y);
        }
        if (total[i].x == maxx) {
          maxy1 = Math.min(maxy1, total[i].y);
          maxy2 = Math.max(maxy2, total[i].y);
        }
      }

      //            System.out.println("Upper  " + Arrays.deepToString(upper));
      //            System.out.println("Lower  " + Arrays.deepToString(lower));
      //            System.out.println("minx " + minx + " " + miny1  + " "+ miny2);
      //            System.out.println("maxx " + maxx + " " + maxy1  + " "+ maxy2);
    }

    int query(Point p) {
      if (p.x < upper[0].x || p.x > upper[upper.length - 1].x)
        return -1;
      if (p.x == minx) {
        if (p.y >= miny1 && p.y <= miny2) {
          return 0;
        } else
          return -1;
      }
      if (p.x == maxx) {
        if (p.y >= maxy1 && p.y <= maxy2) {
          return 0;
        } else
          return -1;
      }
      return -1 * above(lower, p) * above(upper, p);
    }

    int above(Point[] hull, Point p) {

      int lo = 0, hi = hull.length - 1;
      while (true) {
        int mid = (lo + hi) / 2;
        if (p.x >= hull[mid].x && p.x <= hull[mid + 1].x) {
          //          System.out.println("Query for " + p +" :: >  " + hull[mid] +" "+ hull[mid + 1]);
          return (int) Math.signum(hull[mid + 1].minus(hull[mid]).cross(p.minus(hull[mid])));

        } else if (p.x >= hull[mid].x)
          lo = mid;
        else
          hi = mid;
      }
    }

    void findHull(Point[] points) {
      int n = points.length;
      Arrays.sort(points);
      lower = new Point[2 * n];
      upper = new Point[2 * n];
      int k = 0, start = 0;
      for (int i = 0; i < n; i++) {
        Point p = points[i];
        while (k - start >= 2 && p.minus(lower[k - 1]).cross(p.minus(lower[k - 2])) >= 0)
          k--;
        lower[k++] = p;
      }
      lower = Arrays.copyOf(lower, k);
      start = 0;
      k = 0;
      for (int i = n - 1; i >= 0; i--) {
        Point p = points[i];
        while (k - start >= 2 && p.minus(upper[k - 1]).cross(p.minus(upper[k - 2])) >= 0)
          k--;
        upper[k++] = p;
      }
      upper = Arrays.copyOf(upper, k);
    }

  }

  static public class Point implements Comparable<Point> {

    double x, y;

    public Point(double x, double y) {
      this.x = x;
      this.y = y;
    }

    public int compareTo(Point o) {
      if (x != o.x)
        return Double.compare(x, o.x);
      return Double.compare(y, o.y);
    }

    public double dot(Point o) {
      return x * 1L * o.x + y * 1L * o.y;
    }

    public double cross(Point o) {
      return x * 1L * o.y - y * 1L * o.x;
    }

    public Point minus(Point p) {
      return new Point(x - p.x, y - p.y);
    }

    // slope of a-c > a-b
    public static double ccw(Point a, Point b, Point c) {
      return (c.y - a.y) * 1L * (b.x - a.x) - (b.y - a.y) * 1L * (c.x - a.x);
    }

    @Override
    public String toString() {
      return "[" + x + ", " + y + "]";
    }

    public double dist(Point o) {
      double X = x - o.x;
      double Y = y - o.y;
      return Math.sqrt(X * X + Y * Y);
    }
  }

  static public class Line {
    public double a, b, c;
    public static final double EPS = 1e-9;

    public Line(double a, double b, double c) {
      this.a = a;
      this.b = b;
      this.c = c;
    }

    public Line(double m, double c) {
      new Line(m, -1.0, c);
    }

    public Line(Point p1, Point p2) {
      a = +(p1.y - p2.y);
      b = -(p1.x - p2.x);
      c = p1.x * p2.y - p2.x * p1.y;
    }

    public boolean isParallel(Line line) {
      return (a * line.b - b * line.a) < EPS;
    }

    public boolean isPerpendicular(Line line) {
      return sign(a * line.a + b * line.b) == 0;
    }

    public Point intersect(Line line) {
      double d = a * line.b - line.a * b;
      if (sign(d) == 0)
        return null;
      double x = -(c * line.b - line.c * b) / d;
      double y = -(a * line.c - line.a * c) / d;
      return new Point(x, y);
    }

    public Point dist(Point a) {
      double m = -1 / slope();
      double c = a.y - m * a.x;
      return intersect(new Line(m, c));
    }

    public double slope() {
      return sign(-a / b) == 0 ? 0 : (-a / b);
    }

    public static int sign(double a) {
      return a < -EPS ? -1 : a > EPS ? 1 : 0;
    }
  }

}