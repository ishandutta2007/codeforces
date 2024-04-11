import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.HashSet;
import java.util.Iterator;
import java.util.List;
import java.util.Set;
import java.util.StringTokenizer;

public class probB {
    class FastScanner {
        private BufferedReader reader;
        private StringTokenizer tokenizer;

        public FastScanner(InputStream stream) {
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

    class Server {
        public int size, i;

        public Server(int size, int i) {
            this.size = size;
            this.i = i;
        }

        public int getSize() {
            return size;
        }

        public int getPos() { return i; }
    }

    private boolean check(int x, int serverNum, Server minServer) {
        int power = x / serverNum;
        power += x % serverNum != 0 ? 1 : 0;
        return power <= minServer.getSize();
    }

    private void printSorted(PrintWriter out, List<Server> servers) {
        servers.sort(Comparator.comparing(Server::getPos));
        for (int i = 0; i < servers.size(); i++) {
            out.print(servers.get(i).getPos());
            out.print(" ");
        }
        out.println();
    }

    private boolean solve(int x1, int x2, ArrayList<Server> servers, PrintWriter out, boolean frst) {
        int lst = servers.size() - 1;
        while (lst > 1 && !check(x1, servers.size() - lst, servers.get(lst))) {
            lst--;
        }
        if (lst < 1 || !check(x1, servers.size() - lst, servers.get(lst))) {
            return false;
        }

        int fst = lst - 1;
        while (fst > 0 && !check(x2, lst - fst, servers.get(fst))) {
            fst--;
        }
        if (lst < 0 || !check(x2, lst - fst, servers.get(fst))) {
            return false;
        }

        out.println("Yes");
        if (frst) {
            out.print(servers.size() - lst);
            out.print(" ");
            out.println(lst - fst);
        } else {
            out.print(lst - fst);
            out.print(" ");
            out.println(servers.size() - lst);
        }
        if (frst) {
            printSorted(out, servers.subList(lst, servers.size()));
        }
        printSorted(out, servers.subList(fst, lst));
        if (!frst) {
            printSorted(out, servers.subList(lst, servers.size()));
        }

        return true;
    }


    public void run() throws FileNotFoundException {
        FastScanner in = new FastScanner(System.in);
        PrintWriter out = new PrintWriter(System.out);

        //FastScanner in = new FastScanner(new FileInputStream("input.txt"));
        //PrintWriter out = new PrintWriter("output.txt");

        int n = in.nextInt();
        int x1 = in.nextInt();
        int x2 = in.nextInt();

        ArrayList<Server> servers = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            servers.add(new Server(in.nextInt(), i + 1));
        }
        servers.sort(Comparator.comparing(Server::getSize));

        if (!solve(x1, x2, servers, out, true)) {
            if (!solve(x2, x1, servers, out, false)) {
                out.println("No");
            }
        }

        out.close();
    }

    public static void main(String[] args) throws FileNotFoundException {
        new probB().run();
    }
}