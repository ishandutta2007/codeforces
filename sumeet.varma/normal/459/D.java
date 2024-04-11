import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Map;
import java.util.StringTokenizer;
import java.util.TreeMap;


public class R261D2TDPashmakAndParmidaProblem {

    public static void main(String args[] ) throws Exception {
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter w = new PrintWriter(System.out);
            
        StringTokenizer st1 = new StringTokenizer(br.readLine());
        int n = ip(st1.nextToken());
              
        StringTokenizer st2 = new StringTokenizer(br.readLine());
        int a[] = new int[n];
        for(int i=0;i<n;i++)
            a[i] = ip(st2.nextToken());
            
        int pre[] = new int[n];
        Map<Integer,Integer> preCount = new TreeMap<Integer,Integer>();
        for(int i=0;i<n;i++){
            if(preCount.containsKey(a[i])){
                int v = preCount.get(a[i]);
                preCount.put(a[i],v+1);
                pre[i] = v+1;
            }
            else{
                pre[i] = 1;
                preCount.put(a[i], 1);
            }
        }
       
        int post[] = new int[n];
        Map<Integer,Integer> postCount = new TreeMap<Integer,Integer>();
        for(int i=n-1;i>=0;i--){
            if(postCount.containsKey(a[i])){
                int v = postCount.get(a[i]);
                postCount.put(a[i],v+1);
                post[i] = v+1;
            }
            else{
                post[i] = 1;
                postCount.put(a[i], 1);
            }
        }
        
        w.println(mergeSort(pre,post,0,n-1));
        w.close(); 
    }
    
    public static long mergeSort(int pre[],int post[],int start,int end){
        if(start < end){
            int mid = (start + end) / 2;
            return mergeSort(pre,post,start,mid) + mergeSort(pre,post,mid+1,end) + merge(pre,post,start,mid+1,end);
        }
        return 0;
    }
    
    public static long merge(int[] pre,int[] post,int start,int mid,int end){
        
        long ans = 0;
        int y = mid;
        for(int x=start;x<mid;x++){
            while(y<=end && post[y] < pre[x])
                y++;
            ans += y - mid;
        }
        
        int t[] = new int[end-start+1];
        int i = start,j = mid,k = 0;
        while(i < mid && j<=end){
            if(pre[i] < pre[j])
                t[k++] = pre[i++];
            else
                t[k++] = pre[j++];
        }
        while(i < mid)
            t[k++] = pre[i++];
        while(j <= end)
            t[k++] = pre[j++];
        for(int x=start;x<=end;x++)
            pre[x] = t[x-start];
        
        i = start; j = mid; k = 0;
        while(i < mid && j<=end){
            if(post[i] < post[j])
                t[k++] = post[i++];
            else
                t[k++] = post[j++];
        }
        while(i < mid)
            t[k++] = post[i++];
        while(j <= end)
            t[k++] = post[j++];
        for(int x=start;x<=end;x++)
            post[x] = t[x-start];
        
        return ans;
    }
    
    public static int ip(String s){
        return Integer.parseInt(s);
    }
}