
 #include<bits/stdc++.h>
using namespace std;
int f[100009];
int pr[6009];
vector<int> Pa;
vector<int> v[5009];
vector<int> A, B;
void dfs(int x, int d){
    f[x] = 1;
    if(d) A.push_back(x);
    else B.push_back(x);
    for(int i =  0; i < v[x].size(); i++)
        if(!f[v[x][i]]) dfs(v[x][i], 1 - d);
}
vector<int> C(vector<int> a, vector<int> b){
    for(int i =0 ; i < b.size(); i++)
        a.push_back(b[i]);
    return a;
}
int F(vector<int> A){
    if(A.size() <= 1) return 0;
     printf("? %d\n", (int)A.size());
        for(int i = 0; i < A.size(); i++)
             printf("%d ", A[i]);
        cout<<endl;
    int x;
    cin>>x;
    if(x == -1) cout<<1/0<<endl;
    return x;
}
bool fp(int x, int y){
    f[x] = 1;
    if(x == y){
        Pa.push_back(x);
        return 1;
    }
    for(int i = 0; i < v[x].size(); i++){
        if(f[v[x][i]]) continue;
        if(fp(v[x][i], y)){
            Pa.push_back(x);
            return 1;
        }
    }
    return 0;
}
main(){
    int n;
    cin >> n;
    f[1] = 1;
    vector<int> a;
    a.push_back(1);
    for(int i = 2; i <= n; i++){
        vector<int> b;

        for(int j = 1; j <= n; j++){
            if(!f[j]) //a.push_back(j);
         b.push_back(j);
        }
        pr[a.size()-1] = F(a);
        int l = 0, r = (int)b.size()-1;
        while(l < r){
            int mid = (l+r)/2;
            vector<int> c;
            for(int j = 0; j <= mid; j++)
                c.push_back(b[j]);
            if(F(C(a,c)) - pr[a.size()-1] - F(c) == 0) l = mid + 1;
            else r = mid;
        }
        int e1 = b[l];
         l = 0, r = (int)a.size()-1;
        while(l < r){
            int mid = (l + r)/2;
            vector<int> c;
            for(int i = 0; i <= mid; i++)
                c.push_back(a[i]);
            if(F(C(c,{e1})) - pr[mid] == 0) l = mid + 1;
            else r = mid;
        }
        int e2 = a[l];
        if(F({e1,e2})==0) cout<<1/0<<endl;
        v[e1].push_back(e2);
        a.push_back(e1);
        v[e2].push_back(e1);
        f[e1] = 1;

    }
    for(int i = 1;i  <= n; i++)
        f[i] = 0;
    dfs(1, 0);
    if(F(A) == 0 && F(B) == 0){
        printf("Y %d\n", (int)A.size());
        for(int i = 0; i < A.size(); i++)
             printf("%d ", A[i]);
        cout<<endl;
        return 0;
    }
    else {
        if(F(A) == 0) A = B;
        int l = 0, r = (int)A.size()-1;
        while(l < r){
            int mid = (l + r)/2;
            vector<int> c;
             for(int i = 0; i <= mid; i++)
                c.push_back(A[i]);
            if(F(c)) r = mid;
            else l = mid + 1;
        }
        int e1 = A[l];
        int T = l;
          r = l- 1,l=0;
        while(l < r){
            int mid = (l + r+1)/2;
            vector<int> c;
             for(int i = mid; i <= T; i++)
                c.push_back(A[i]);
            if(F(c)) l = mid;
            else r = mid - 1;
        }
        int e2 = A[l];
        for(int i = 1; i <= n; i++)
            f[i] = 0;
       // if(F)
        fp(e1, e2);
          printf("N %d\n", (int)Pa.size());
        for(int i = 0; i < Pa.size(); i++)
             printf("%d ", Pa[i]);
        cout<<endl;
        return 0;
    }
}