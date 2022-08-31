/**
 * @author Anil Kishore, IIIT-Hyderabad
 * May, 2010
 */

import java.io.*;
import java.util.*;
import static java.lang.Math.*;

public class CF13_E
{
    BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in));
    PrintWriter stdout = new PrintWriter(new OutputStreamWriter(System.out));
    StringTokenizer st;
    StringBuilder sb = new StringBuilder();

    final int lim = (int)1e5 + 5;
    int[] pow = new int[lim];
    int[] next = new int[lim];
    int[] jumps = new int[lim];

    void solve() throws IOException
    {
        int N = INT(), M = INT();
        int i=0, j=0, k=0, from=0, to=0, size = (int)sqrt(N);

        for(i=0;i<N;i++) pow[i] = INT();
        for(from=0;from<N;from+=size)
        {
            to = min(from+size-1,N-1);
            for(j=to;j>=from;j--)
            {
                k = j + pow[j];
                if(k>to){ next[j]=k; jumps[j]=1; }
                else{ next[j]=next[k]; jumps[j]=jumps[k]+1; }
            }
        }

        while(M-->0)
        {
            int op = INT();
            if(op==0)
            {
                int a = INT() - 1, b = INT();
                pow[a] = b;
                from = (a/size)*size; to = min(from+size-1,N-1);
                for(j=to;j>=from;j--)
                {
                    k = j + pow[j];
                    if(k>to){ next[j]=k; jumps[j]=1; }
                    else{ next[j]=next[k]; jumps[j]=jumps[k]+1; }
                }
            }
            else
            {
                int a = INT() - 1;
                int last = a, jmps = 0;

                while(next[last]<N)
                {
                    jmps+=jumps[last];
                    last = next[last];
                }

                while(last+pow[last]<N)
                {
                    jmps++;
                    last = last+pow[last];
                }

                sb.append(last+1);
                sb.append(' ');
                sb.append(jmps+1);
                sb.append('\n');
            }

            
        }

        stdout.print(sb);
        
        stdin.close();
        stdout.close();
    }

    final int INT() throws IOException
    {
        return Integer.parseInt(TOK());
    }

    final String TOK() throws IOException
    {
        if(st==null || !st.hasMoreTokens()) st = new StringTokenizer(stdin.readLine());
        return st.nextToken();
    }

    public static void main(String[] args) throws IOException
    {
        (new CF13_E()).solve();
    }
}