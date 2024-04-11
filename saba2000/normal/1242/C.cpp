#include<bits/stdc++.h>
using namespace std;
unordered_map<long long,int> M;
int T[200009];
int I[200009];
int N[200009];
int f[200009];
int w[29];
int n[29];
vector<int> v[29];
long long su[29];
vector<int> Y[200009];
stack<int> S;
void dfs(int x){
    f[x] = 1;
    S.push(x);
    int k = N[x], u = I[k];

    if(!k || f[k] == 2) {f[x] = 2;return;}
    if(f[k] == 1){
        vector<int > z={k};
        int B = (1<<u);
        while(S.top() != k){
            z.push_back(S.top());
            B|=(1<<I[S.top()]);
            S.pop();
        }
        if(__builtin_popcount(B) == z.size()) Y[B] =z;
        f[x] = 2;
        return;
    }
    dfs(k);
    f[x] = 2;
}
main(){
    int k;
    int c = 0;
    long long SU = 0;
    cin >> k;
    for(int i = 0; i < k; i++){
        int x;
        cin >> x;
        for(int j = 0; j < x; j++){
            int a;
            cin >> a;

            v[i].push_back(a);
            T[++c] = a;
            M[a] = c;
            I[c] = i;
            su[i]+=a;
            SU += a;
        }
    }
    if(SU % k != 0){
        cout<<"No"<<endl;
        return  0;
    }
    long long s = SU / k;

    for(int i = 0; i < k; i++){
        for(int x: v[i]){
            N[M[x]] = M[s - (su[i] - x)];
        }
    }
    for(int i = 1; i <= c; i++){
        if(f[i] == 0){
            while(S.size()) S.pop();
            dfs(i);
        }
    }
    for(int i = 1; i < (1<<k); i++){
        if(Y[i].size()) continue;
        for(int x = (i-1)&i; x; x = (x-1)&i){
            if(Y[x].size() && Y[i-x].size()){
                Y[i] = Y[x];
                for(int u : Y[i-x])
                    Y[i].push_back(u);
                break;
            }
        }
    }
    if(!Y[(1<<k)-1].size()){
        cout<<"No"<<endl;
        return  0;
    }
    cout<<"Yes"<<endl;
    vector<int> v = Y[(1<<k)-1];
    for(int x : v){
        w[I[x]] = T[x];
        n[I[N[x]]] = I[x];
    }
    for(int i =0 ; i < k; i++)
        cout<<w[i]<<" "<<n[i]+1<<endl;
}
//
//