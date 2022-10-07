#include<bits/stdc++.h>
#define ll long long
#define fr first
#define se second
#define pb push_back
using namespace std;
int V[2009];
int f[1009];
int ask(vector<int> v){
    cout<<"? ";
    for(int x : v)
        cout<<x<<" ";
    cout<<endl;
    int a,b;
    cin>>a>>b;
    V[a] = b;
    return a;

}
main(){
    int n, k;
    cin >> n >> k;
    for(int i =1; i <= n- k + 1; i++){
        vector<int> v;
        for(int j = 1; (v.size() <k && j <= n); j++)
            if(f[j] == 0) v.push_back(j);
        int x =  ask(v);
        f[x] = 1;
    }
    int t = 0, p = 0;
    int ans = 1;
    vector<int> w;
    for(int i = 1; i <= n; i++){
        if(f[i] == 0) w.push_back(i);
        if(f[i] == 1) if(t == 0) t = i; else p = i;}
    if(V[t] > V[p]) swap(t,p);
    for(int x : w){
        vector<int> v;
        v.push_back(t);
        v.push_back(p);
        for(int i =1; i <= n; i++)
            if(f[i] == 0 && i != x) v.push_back(i);
        int u = ask(v);
        if(u != t) ans++;
    }
    cout<<"! "<<ans<<endl;
}
//m -1    k - m
//S 0
//S