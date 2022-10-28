
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class A_WatchingaMovie {

    public static void main(String args[] ) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter w = new PrintWriter(System.out);
       
        StringTokenizer st1 = new StringTokenizer(br.readLine().trim());
        int n = ip(st1.nextToken().trim());
        int x = ip(st1.nextToken().trim());
        
        int ans = 0;
        int curr = 1;
        
        for(int i=0;i<n;i++){
            StringTokenizer st2 = new StringTokenizer(br.readLine().trim());
            int l = ip(st2.nextToken().trim());
            int r = ip(st2.nextToken().trim());
            int count = (l - curr) / x;
            curr += count*x;
            ans += r - curr + 1;
            curr = r+1;
        }
            
        w.println(ans);
        w.close();
            
        System.exit(0);
    }
    
    public static int ip(String s){
        return Integer.parseInt(s);
    }
}