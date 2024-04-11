import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.InputMismatchException;
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
		TaskB solver = new TaskB();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskB {
    public void solve(int testNumber, Reader in, OutputWriter out) {
        String s1 = in.nextString();
        String s2 = in.nextString();
        String virus = in.nextString();
        int[][][] dp = new int[s1.length() + 1][s2.length() + 1][virus.length() + 1];
        for(int i = 0; i <= s1.length(); ++i)
            for(int j = 0; j <= s2.length(); ++j)
                Arrays.fill(dp[i][j], -1);
        int[][][] pred = new int[s1.length() + 1][s2.length() + 1][virus.length() + 1];


        int[] pf = prefix_function(virus);

        int[][] aut = new int[virus.length()][26];
        for (int i = 0; i < virus.length(); ++i)
            for (char c='A'; c <= 'Z'; ++c) {
                int j = i;
                while (j > 0 && c != virus.charAt(j))
                    j = pf[j - 1];
                if (c == virus.charAt(j))  ++j;
                aut[i][c - 'A'] = j;
            }

        dp[0][0][0] = 0;

        for(int i = 0; i <= s1.length(); ++i) {
            for(int j = 0; j <= s2.length(); ++j) {
                for(int k = 0; k < virus.length(); ++k) {
                    if(dp[i][j][k] == -1)
                        continue;
                    if(i != s1.length() && dp[i + 1][j][k] < dp[i][j][k]) {
                        dp[i + 1][j][k] = dp[i][j][k];
                        pred[i + 1][j][k] = -2;
                    }
                    if(j != s2.length() && dp[i][j + 1][k] < dp[i][j][k]) {
                        dp[i][j + 1][k] = dp[i][j][k];
                        pred[i][j + 1][k] = -3;
                    }
                    if(i != s1.length() && j != s2.length() && s1.charAt(i) == s2.charAt(j)) {
                        int nextK = aut[k][s1.charAt(i) - 'A'];
                        if(dp[i + 1][j + 1][nextK] < dp[i][j][k] + 1) {
                            dp[i + 1][j + 1][nextK] = dp[i][j][k] + 1;
                            pred[i + 1][j + 1][nextK] = k;
                        }
                    }
                }
            }
        }

        int best = 0;

        int[] res = dp[s1.length()][s2.length()];

        for(int k = 0; k < virus.length(); ++k) {
            if(res[k] > res[best]) {
                best = k;
            }
        }

        if(res[best] == 0) {
            out.println(res[best]);
            return;
        }

        int ci = s1.length();
        int cj = s2.length();
        int ck = best;
        StringBuffer s = new StringBuffer();
        while (ci > 0 && cj > 0) {
            //System.err.println(ci + " " + cj + " " + ck);
            if(pred[ci][cj][ck] == -2) {
                --ci;
            }
            else if(pred[ci][cj][ck] == -3){
                --cj;
            }
            else {
                ck = pred[ci][cj][ck];
                --ci;
                --cj;
                s.append(s1.charAt(ci));

            }
        }

        out.println(s.reverse().toString());


    }

    int[] prefix_function (String s) {
        int n = s.length();
        int[] pi = new int[n];
        for (int i = 1; i < n; ++i) {
            int j = pi[i - 1];
            while (j > 0 && s.charAt(i) != s.charAt(j))
                j = pi[j-1];
            if (s.charAt(i) == s.charAt(j))
                ++j;
            pi[i] = j;
        }
        return pi;
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