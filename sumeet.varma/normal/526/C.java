
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class TaskC {

    static long c,hr,hb,wr,wb;

    
    public static void main(String args[] ) throws Exception {
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter w = new PrintWriter(System.out);
            
        StringTokenizer st1 = new StringTokenizer(br.readLine());
        c = ip(st1.nextToken());
        hr = ip(st1.nextToken());
        hb = ip(st1.nextToken());
        wr = ip(st1.nextToken());
        wb = ip(st1.nextToken());
    
        long ans = 0;
        for(long i=0;i<=1000000;i++){
            if(wr*i <= c)   ans = Math.max(ans, hr * i + ((c - wr * i)/wb) * hb);
            if(wb*i <= c)   ans = Math.max(ans, hb * i + ((c - wb * i)/wr) * hr);
        }
        
        w.print(ans);
        w.close();
    }
    
    public static int ip(String s){
        return Integer.parseInt(s);
    }
    
    public static long lp(String s){
        return Long.parseLong(s);
    }
}