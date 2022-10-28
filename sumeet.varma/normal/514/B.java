import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class Round291DivTaskB {

    public static void main(String args[] ) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter w = new PrintWriter(System.out);
            
        StringTokenizer st1 = new StringTokenizer(br.readLine());
        int n = ip(st1.nextToken());
        int xo = ip(st1.nextToken());
        int yo = ip(st1.nextToken());
        
        int x[] = new int[n];
        int y[] = new int[n];
        
        for(int i=0;i<n;i++){
            StringTokenizer st2 = new StringTokenizer(br.readLine());
            x[i] = ip(st2.nextToken());
            y[i] = ip(st2.nextToken());
        }
        
        int count = 0;
        boolean done[] = new boolean[n];
        for(int i=0;i<n;i++){
            if(!done[i]){
                count++;
                for(int j=i+1;j<n;j++){
                    if((y[i]-yo)*(x[j]-xo) == (y[j]- yo)*(x[i]-xo))
                        done[j] = true;
                }
            }
        }
        
        w.println(count);
        w.close(); 
    }
    
    public static int ip(String s){
        return Integer.parseInt(s);
    }
}