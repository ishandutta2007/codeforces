    import java.util.*;
     
    public class C {
        public static void main(String[] args) {
            Scanner s =new Scanner(System.in);
            
                
            int n = s.nextInt();
            
            int[] a = {4, 8, 15, 16, 23, 42};
            int[] running = new int[6];
            int[] cmp = new int[50];
            for(int i = 0; i < 6; i++){
                cmp[a[i]] = i;
            }
            int del = 0;
            for(int i = 0; i< n; i++){
                int cur = cmp[s.nextInt()];
                if (cur == 0) {
                    running[0]++;
                }else {
                    if (running[cur-1] > 0) {
                        running[cur-1]--;
                        running[cur]++;
                    }
                    else {
                        del++;
                    }
                }
            }
            for(int i = 0; i < 5; i ++){
                del+=(i+1)*running[i];
            }
            System.out.println(del);
        }
    }