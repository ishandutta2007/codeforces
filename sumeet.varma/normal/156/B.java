import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class R110qBSuspects {

    public static void main(String args[] ) throws Exception {
           
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter w = new PrintWriter(System.out);
        
        StringTokenizer st1 = new StringTokenizer(br.readLine());
        int n = ip(st1.nextToken());
        int m = ip(st1.nextToken());
             
        int yesCount[] = new int[n+1];
        int noCount[] = new int[n+1];
        int totalNo = 0;
        
        boolean what[] = new boolean[n+1];
        int suspect[] = new int[n+1];
        
        for(int i=1;i<=n;i++){
            int person = ip(br.readLine());
            if(person > 0){
                yesCount[person]++;
                what[i] = true;
                suspect[i] = person;
            }
            else{
                person *= -1;
                noCount[person]++;
                totalNo++;
                what[i] = false;
                suspect[i] = person;
            }
        }
        
        boolean isCriminal[] = new boolean[n+1];
        int s = 0;
        
        for(int i=1;i<=n;i++){
            int correct = yesCount[i] + totalNo - noCount[i];
            if(correct == m){
                isCriminal[i] = true;
                s++;
            }
        }
        
        for(int i=1;i<=n;i++){
            if(what[i]){
                if(isCriminal[suspect[i]]){
                    if(s == 1)
                        w.println("Truth");
                    else
                        w.println("Not defined");
                }
                else
                    w.println("Lie");
            }
            else{
                if(isCriminal[suspect[i]]){
                    if(s == 1)
                        w.println("Lie");
                    else
                        w.println("Not defined");
                }
                else
                    w.println("Truth");
            }
        }
        
        w.close(); 
    }
    
    public static int ip(String s){
        return Integer.parseInt(s);
    }
}