/* Anil Kishore */

import java.util.*;
import java.io.*;
import static java.lang.Math.*;

public class Main
{

    void solve() throws IOException
    {
        int m = Integer.parseInt(bf.readLine());
        String[] sa = bf.readLine().split("[.!?]");
        for(int i=0;i<sa.length;i++) sa[i] = sa[i].trim();
        int ans = 0;
        for(int i=0;i<sa.length;i++)
        {
            int j = i+1, len = sa[i].length() + 1;
            if(len>m){ ans=-1; break; }
            while(j<sa.length && len+sa[j].length()+2<=m)
            {
                len+=sa[j].length()+2;
                j++;
            }
            ans++;
            i = j - 1;
        }
        if(ans==-1) pw.println("Impossible");
        else pw.println(ans);
        pw.flush();
    }

    public static void main(String[] args) throws IOException
    {
        (new Main()).solve();
    }

    // ---------------------------

    BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    PrintWriter pw = new PrintWriter(new OutputStreamWriter(System.out));
    StringTokenizer st;
}