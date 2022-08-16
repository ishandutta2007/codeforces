/* Anil Kishore */

import java.util.*;
import java.io.*;
import static java.lang.Math.*;

public class Template
{

    void solve() throws IOException
    {
        int a = nextInt(), b = nextInt();
        System.out.println((a*b)/2);
    }

    public static void main(String[] args) throws IOException
    {
        (new Template()).solve();
    }

    // ---------------------------

    BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    PrintWriter pw = new PrintWriter(new OutputStreamWriter(System.out));
    StringTokenizer st;

    String next() throws IOException
    {
        while(st==null || !st.hasMoreTokens()) st = new StringTokenizer(bf.readLine());
        return st.nextToken();
    }

    int nextInt() throws IOException{  return Integer.parseInt(next());   }
}