
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class B_TaskBLecture {

    public static int ip(String s){
        return Integer.parseInt(s);
    }
    
    public static void main(String args[] ) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter w = new PrintWriter(System.out);
            
        StringTokenizer st1 = new StringTokenizer(br.readLine());
        int n = ip(st1.nextToken());
        int m = ip(st1.nextToken());
        
        String a[] = new String[m];
        String b[] = new String[m];
        for (int i = 0; i < m; i++) {
            
            StringTokenizer st2 = new StringTokenizer(br.readLine());
            a[i] = st2.nextToken();
            String temp = st2.nextToken();
            b[i] = temp;
            
            if(a[i].length() > temp.length()){
                b[i] = a[i];
                a[i] = temp;
            }
                
        }
        
        StringTokenizer st3 = new StringTokenizer(br.readLine());
        
        for(int i=0;i<n;i++){
            String c = st3.nextToken();
            
            for(int j=0;j<m;j++){
                if(a[j].equals(c) || b[j].equals(c)){
                    w.print(a[j]);
                    break;
                }
            }
            
            w.print(" ");
        }
        
        w.close();
    }
    
    
}