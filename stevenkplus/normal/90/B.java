import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class B090
{
    public static void main( String[] args ) throws Exception
    {
        BufferedReader r = new BufferedReader( new InputStreamReader( System.in ) );
        StringTokenizer st = new StringTokenizer(r.readLine());
        int n = Integer.parseInt(st.nextToken()),m=Integer.parseInt(st.nextToken());
        char[][] c = new char[n][m];
        for(int x = 0;x<n;x++) {
            String l = r.readLine();
            for(int y = 0;y<m;y++) {
                c[x][y] = l.charAt(y);
            }
        }
        for(int x =0;x<n;x++) {
            g:for(int y=0;y<m;y++) {
                char cc = c[x][y];
                for(int i =0 ;i<n;i++) {
                    if(i!=x&&c[i][y]==cc) continue g;
                }
                for(int i =0;i<m;i++) {
                    if(i!=y&&c[x][i]==cc) continue g;
                }
                    
                System.out.print(cc);
            }
        }
        System.out.println();
    }
}
//