import java.io.IOException;
import java.io.InputStreamReader;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.util.StringTokenizer;
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
        OutputWriter out = new OutputWriter(outputStream);
        TaskE solver = new TaskE();
        solver.solve(1, in, out);
        out.close();
    }
}

class TaskE {
    ArrayList<Pair<Integer, String>>[] children;
    int[][] automaton;
    public void solve(int testNumber, Reader in, OutputWriter out) {
        int n = in.nextInt();
        children = new ArrayList[n];

        for(int i = 0; i < n; ++i)
            children[i] = new ArrayList<Pair<Integer, String>>();

        for(int i = 1; i < n; ++i){
            int parent = in.nextInt() - 1;
            children[parent].add(new Pair<Integer, String>(i, in.nextString()));
        }

        automaton = prefixFunctionAutomaton(in.nextString());
        dfs(0, 0);
        out.println(ans);
    }

    int ans = 0;

    private void dfs(int v, int startState) {
        for (Pair<Integer, String> child : children[v]) {
            int state = startState;
            for(int i = 0; i < child.second.length(); ++i){
                state = automaton[state][child.second.charAt(i) - 'a'];
                if(automaton.length - 1 == state) {
                    ++ans;
                }
            }
            dfs(child.first, state);
        }

    }

    int[][] prefixFunctionAutomaton(String s) {
        int alphabet = 26;

        s += '#';
        int n = s.length();
        int[] pi = prefixFunction(s);
        int[][] aut = new int[n][alphabet];
        for (int i=0; i<n; ++i)
            for (char c=0; c<alphabet; ++c)
                if (i > 0 && c + 'a' != s.charAt(i))
                    aut[i][c] = aut[pi[i-1]][c];
                else
                    aut[i][c] = i + (c + 'a' == s.charAt(i) ? 1 : 0);
        return aut;
    }

    private int[] prefixFunction(String s) {
        int n = s.length();
        int[] pi = new int[n];
        for (int i=1; i<n; ++i) {
            int j = pi[i-1];
            while (j > 0 && s.charAt(i) != s.charAt(j))
                j = pi[j-1];
            if (s.charAt(i) == s.charAt(j))  ++j;
            pi[i] = j;
        }
        return pi;
    }
}

class Pair<F, S> implements Comparable<Pair<F, S>> {

    public F first;
    public S second;

    public Pair(F first, S second) {
        this.first = first;
        this.second = second;
    }

    public int compareTo(Pair<F, S> other) {
        int res = ((Comparable<F>) first).compareTo(other.first);
        if (res != 0) {
            return res;
        }
        return ((Comparable<S>) second).compareTo(other.second);
    }

    public String toString() {
        return "(" + first + "," + second + ")";
    }

    public boolean equals(Object o) {
        if (this == o) {
            return true;
        }
        if (o == null || getClass() != o.getClass()) {
            return false;
        }

        Pair pair = (Pair) o;

        if (first != null ? !first.equals(pair.first) : pair.first != null) {
            return false;
        }
        if (second != null ? !second.equals(pair.second) : pair.second != null) {
            return false;
        }

        return true;
    }

    public int hashCode() {
        int result = first != null ? first.hashCode() : 0;
        result = 31 * result + (second != null ? second.hashCode() : 0);
        return result;
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

    private String readLine() {
        try {
            return reader.readLine();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}

class OutputWriter extends PrintWriter {

    public OutputWriter(OutputStream out) {
        super(out);
    }

    public OutputWriter(java.io.Writer writer){
        super(writer);
    }

    }