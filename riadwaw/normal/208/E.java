import java.io.*;
import java.util.*;

public class E implements Runnable {
    void preCalc() {

    }
    ArrayList<Integer>[] childs;
    int[] parent, level;
    int[][] parents;
    ArrayList<Integer>[] allLevel;

    int[] timeIn, timeOut;
    int timer = 0;
    void dfs(int v, int lev){
        timeIn[v] = ++timer;
        level[v] = lev;
        allLevel[lev].add(v);
        parents[v][0] = parent[v] == -1 ? v : parent[v];
        for (int i=1; i<parents[v].length; ++i)
            parents[v][i] = parents[parents[v][i-1]][i-1];
        for(int child: childs[v]){
            dfs(child, lev + 1);
        }

        timeOut[v] = ++timer;
    }

    int nthParent(int v, int n){
        int curV = v;
        for(int l = parents[v].length - 1; l >= 0; --l){
            if(n>=(1<<l)){
                n-=(1<<l);

                curV = parents[curV][l];
            }
        }
        return curV;
    }

    void solve() throws IOException {
        int n = nextInt();
        HashSet<Integer> roots = new HashSet<Integer>();
        childs = new ArrayList[n];
        allLevel = new ArrayList[n];
        parent = new int[n];
        level = new int[n];
        timeIn = new int[n];
        timeOut = new int[n];
        for (int i = 0; i <n;++i){
            childs[i] = new ArrayList<Integer>();
            allLevel[i] = new ArrayList<Integer>();
        }
        for(int i = 0 ;i <n;++i){
            parent[i] = nextInt() - 1;
            if(parent[i] == -1)
                roots.add(i);
            else
                childs[parent[i]].add(i);
        }

        int l = 1;
        while ((1<<l) <= n)  ++l;
        parents = new int[n][l + 3];


        for(int root: roots){
            dfs(root, 0);
        }


        int m = nextInt();
        for(int i = 0; i <m; ++i){
            int v = nextInt() - 1, p = nextInt();
            int nth = nthParent(v, p);
            int prev = nthParent(v, p -1);
            if(nth == prev){
                out.print("0 ");
                continue;
            }

            int ans = get(nth, p) - 1;

            out.print(ans + " ");


        }


    }

    int bound(ArrayList<Integer> array,  int bound){

        int l = -1, r = array.size();
        while(l + 1 < r){
            int m = (l+r) >> 1;

            if(timeIn[array.get(m)] >= bound)
                r = m;
            else
                l = m;
        }
        return r;
    }

    private int get(int v, int p) {
        if(p == 0)
            return 1;
        int lev = level[v] + p;
        if(lev>= allLevel.length)
            return 0;
        return Math.max(0,bound(allLevel[lev], timeOut[v]) - bound(allLevel[lev], timeIn[v]));
    }

    public static void main(String[] args) {
        debugMode = args.length > 0 && args[0].equals("debug");
        new Thread(null, new E(), "", 1 << 25).start();
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