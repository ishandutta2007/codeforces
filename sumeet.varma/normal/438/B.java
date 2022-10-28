import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.util.Arrays;
import java.util.ArrayList;

public class R250QDTheChildAndTheZoo {

    static ArrayList<Integer> g[];
    static Pair a[];
    
    @SuppressWarnings("unchecked")
    public static void main(String args[] ) throws Exception {
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter w = new PrintWriter(System.out);
            
        StringTokenizer st1 = new StringTokenizer(br.readLine());
        int n = ip(st1.nextToken());
        int m = ip(st1.nextToken());
              
        StringTokenizer st2 = new StringTokenizer(br.readLine());
        a = new Pair[n];
        for(int i=0;i<n;i++)
            a[i] = new Pair(i+1,ip(st2.nextToken()));
            
        Arrays.sort(a); 
        
        g = new ArrayList[n+1];
        for(int i=1;i<=n;i++)
            g[i] = new ArrayList<Integer>();
        
        for(int i=0;i<m;i++){
            StringTokenizer st3 = new StringTokenizer(br.readLine());
            int x = ip(st3.nextToken());
            int y = ip(st3.nextToken());
            g[x].add(y);
            g[y].add(x);
        }
        
        long ans = 0; 
        DisjointSett ds = new DisjointSett(n);
        boolean inGraph[] = new boolean[n+1];
        
        for(int i=n-1;i>=0;i--){
            int idx = a[i].idx;
            int val = a[i].val;
            inGraph[idx] = true;
            int s = g[idx].size();
        
            for(int j=0;j<s;j++){
                int c = g[idx].get(j);
                if(inGraph[c]){
                    if(ds.find(c) != ds.find(idx)){
                        ans += val * 1L * ds.size[ds.find(idx)] * ds.size[ds.find(c)];
                        ds.merge(idx, c);
                    }
                }
            }   
        }
       
        w.println(ans * 2.0 / (1L * n * 1L * (n-1))); 
        w.close(); 
    }
    
    public static int ip(String s){
        return Integer.parseInt(s);
    }
}

class Pair implements Comparable<Pair>{
    int idx,val;
    Pair(int i,int v){
        idx = i;
        val = v;
    }
    public int compareTo(Pair b){
        return val - b.val;
    }
}


class DisjointSett {

    public int rank[],parent[],size[];
    public int n;
    
    public DisjointSett(int n){
        this.n = n;
        makeSet();
    }
    
    public void makeSet(){
        rank = new int[n+1];
        parent = new int[n+1];
        size = new int[n+1];
        for(int i=1;i<=n;i++){
            parent[i] = i;
            rank[i] = 0;
            size[i] = 1;
        }
    }
    
    public int find(int x){
        if(parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }
    
    public void merge(int x,int y){
        int xRoot = find(x);
        int yRoot = find(y);
        
        if(xRoot == yRoot)
            return;
        
        if(rank[xRoot] < rank[yRoot]){
            parent[xRoot] = yRoot;
            size[yRoot] += size[xRoot];
        }
        else{
            parent[yRoot] = xRoot;
            size[xRoot] += size[yRoot];
            if(rank[xRoot] == rank[yRoot]){
                parent[yRoot] = xRoot;
                rank[xRoot]++;
            }
        }
        
    }
    
}