import java.util.Scanner;
import java.io.OutputStream;
import java.io.IOException;
import java.io.PrintWriter;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author codeKNIGHT
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        Scanner in = new Scanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskE solver = new TaskE();
        solver.solve(1, in, out);
        out.close();
    }
}

class TaskE {
    public void solve(int testNumber, Scanner in, PrintWriter out) {
        int n=in.nextInt(),mod=1000000007,i;
        long ans=1;
        for(i=1;i<=n;i++)
            ans=(ans*3)%mod;
        if(n%2==0)
            ans+=3;
        else ans-=3;
        ans*=250000002;
        ans%=mod;
        long a=(long)ans;
        out.println(a);
    }
}