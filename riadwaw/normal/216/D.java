import java.util.List;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.util.Collections;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author RiaD
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		Reader in = new Reader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD {
    class Line implements Comparable<Line>{
        int sector;
        int dist;

        Line(int sector, int dist) {
            this.sector = sector;
            this.dist = dist;
        }

        public int compareTo(Line o) {
            return dist - o.dist;
        }
    }

    int countGreater(ArrayList<Integer> a, int v){
        int x =Collections.binarySearch(a, v);
        
        int ip = - x - 1;
        return a.size() - ip;
    }
	public void solve(int testNumber, Reader in, PrintWriter out) {
        int n = in.nextInt();

        ArrayList<Integer>[] points = new ArrayList[n];
        for(int i = 0 ;i < n ; ++i){
            points[i] = new ArrayList<Integer>();
        }

        ArrayList<Line> lines = new ArrayList<Line>();

        for(int i = 0; i < n; ++i){
            int k = in.nextInt();
            for(int d: in.nextIntArray(k)){
                lines.add(new Line(i, d));
            }
        }

        Collections.sort(lines);
        int ans = 0;
        for(Line line: lines){
            points[line.sector].add(line.dist);
            if(points[line.sector].size() == 1)
                continue;

            int prev = points[line.sector].get(points[line.sector].size() - 2);

            int left = countGreater(points[(line.sector + n - 1) % n],prev);
            int right = countGreater(points[(line.sector + 1) % n], prev);

            if(left != right)
                ++ans;
        }
        out.print(ans);
	}
}

class Reader {
    private BufferedReader reader;
    private StringTokenizer tokenizer;

    public Reader(BufferedReader reader) {
        this.reader = reader;
    }

    public Reader(InputStream stream) {
        this(new BufferedReader(new InputStreamReader(stream)));
    }

    public String nextString() {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(readLine());
        }
        return tokenizer.nextToken();
    }

    public int nextInt() {
        return Integer.parseInt(nextString());
    }

    public int[] nextIntArray(int size) {
        int[] array = new int[size];
        for (int i = 0; i < size; ++i) {
            array[i] = nextInt();
        }
        return array;
    }

    private String readLine() {
        try {
            return reader.readLine();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}