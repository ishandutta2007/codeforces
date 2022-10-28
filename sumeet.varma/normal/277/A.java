import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class R170qALearningLanguages {

    public static void main(String args[] ) throws Exception {
           
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter w = new PrintWriter(System.out);
        
        StringTokenizer st1 = new StringTokenizer(br.readLine());
        int n = ip(st1.nextToken());
        int m = ip(st1.nextToken());
              
        boolean know[][] = new boolean[n][m];
        boolean atLeast1 = false;
        
        for(int i=0;i<n;i++){
            StringTokenizer st2 = new StringTokenizer(br.readLine());
            int s = ip(st2.nextToken());
            if(s != 0)  atLeast1 = true;
            while(s-- > 0)
                know[i][ip(st2.nextToken())-1] = true;
        }
        
        DS ds = new DS(n);
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=0;k<m;k++){
                    if(know[i][k] && know[j][k]){
                        ds.merge(i, j);
                        break;
                    }
                }
            }
        }
        
        int ans = ds.comp;
        if(atLeast1)
            ans--;
        
        w.println(ans);
        w.close(); 
    }
    
    public static int ip(String s){
        return Integer.parseInt(s);
    }
}

class DS {

    public int rank[],parent[];
    public int n,comp;
    
    public DS(int n){
        this.n = n;
        makeSet();
    }
    
    public DS(int n,int comp,int r[],int p[]){
        this.n = n;
        this.comp = comp;
        rank = new int[n];
        parent = new int[n];
        for(int i=0;i<n;i++){
            rank[i] = r[i];
            parent[i] = p[i];
        }
    }
    
    public void makeSet(){
        comp = n;
        rank = new int[n];
        parent = new int[n];
        for(int i=0;i<n;i++)
            parent[i] = i;
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
        
        comp--;
        if(rank[xRoot] < rank[yRoot])
            parent[xRoot] = yRoot;
        else{
            parent[yRoot] = xRoot;
            if(rank[xRoot] == rank[yRoot]){
                parent[yRoot] = xRoot;
                rank[xRoot]++;
            }
        }
    }
    
    public void print(){
        for(int i=0;i<n;i++)
            System.out.println(i + " " + parent[i]);
        System.out.println();
    }
    
}