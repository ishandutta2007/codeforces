import java.io.*;
import java.util.*;

public class C implements Runnable {
    void preCalc() {

    }

    ArrayList<Integer>[] g;

    double[] paths;
    int[] dist;
    double[] pathFrom;

    void solve() throws IOException {
        int n = nextInt(), m= nextInt();
        g = new ArrayList[n];
        paths = new double[n];
        dist = new int[n];
        int[] distFrom = new int[n];
        pathFrom = new double[n];
        Arrays.fill(dist, -1);
        Arrays.fill(distFrom, -1);
        for(int i = 0; i< n;++i){
            g[i] = new ArrayList<Integer>();
        }

        for(int i = 0;i<m;++i){
            int a = nextInt() - 1, b = nextInt() - 1;
            g[a].add(b);
            g[b].add(a);
        }

        paths[0] = 1;


        Queue<Integer> q = new LinkedList<Integer>();
        q.add(0);
        dist[0] = 0;
        while (!q.isEmpty()){
            int cur = q.poll();

            for(int next: g[cur]){
                if(dist[next] == -1){
                    dist[next] = dist[cur] + 1;
                    q.add(next);
                }
                if(dist[next] == dist[cur] + 1){
                    paths[next] += paths[cur];
                }
            }
        }




        q = new LinkedList<Integer>();
        q.add(n - 1);
        pathFrom[n - 1] = 1;
        distFrom[n - 1] = 0;
        while (!q.isEmpty()){
            int cur = q.poll();
            for(int next: g[cur]){
                if(distFrom[next] == -1){
                    distFrom[next] = distFrom[cur] + 1;
                    q.add(next);
                }
                if(distFrom[next] == distFrom[cur] + 1){
                    pathFrom[next] += pathFrom[cur];
                }
            }
        }

        double numerator = 0;

        for(int i = 0; i <n;++i){

            //out.println(i+ " " + dist[i] + " " + distFrom[i] + " " + pathFrom[i]);
            if(dist[i] + distFrom[i] == dist[n-1]){
                int cnt = 2;
                if(i == 0 || i == n- 1)
                    --cnt;
                numerator =Math.max(numerator, cnt * 1.0 * paths[i] * pathFrom[i]);
            }
        }


        out.println(numerator / 1.0 / pathFrom[0]);

    }

    public static void main(String[] args) {
        debugMode = args.length > 0 && args[0].equals("debug");
        new Thread(null, new C(), "", 1 << 25).start();
    }


    private void multiTest() throws IOException {
        int t = 1;
        preCalc();
        for (int i = 0; i < t; ++i) {
            solve();
        }
    }

    PrintWriter out;
    StringTokenizer st;
    BufferedReader br;

    public void run() {
        try {
            initFiles();
            long startTime = System.currentTimeMillis();
            if (debugMode) {
                out.println("Output:");
            }

            multiTest();
            if (debugMode) {
                double time = (System.currentTimeMillis() - startTime) / 1000.0;
                out.println("\n\n\nTime: " + time);
            }
            out.flush();
        } catch (IOException e) {
            out.println("IOException:");
            out.println(e.getStackTrace());
        }

    }

    private void initFiles() throws IOException {
        if (debugMode) {
            out = new PrintWriter(System.out);
            br = new BufferedReader(new FileReader("input.txt"));
        } else {
            out = new PrintWriter(System.out);
            br = new BufferedReader(new InputStreamReader(System.in));
        }
    }

    public String nextString() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine());
        }
        return st.nextToken();
    }

    public int nextInt() throws IOException {
        return Integer.parseInt(nextString());
    }

    public double nextDouble() throws IOException {
        return Double.parseDouble(nextString());
    }

    public long nextLong() throws IOException {
        return Long.parseLong(nextString());
    }


    static boolean debugMode = false;


}