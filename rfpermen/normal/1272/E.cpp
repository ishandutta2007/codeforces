#include <bits/stdc++.h>
 
#pragma GCC optimize("O3")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(int i=n;i<=N;++i)
#define rap(i,n,N) for(int i=n;i>=N;--i)
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define fi first
#define se second
#define ff fi.fi
#define fs fi.se
#define sf se.fi
#define ss se.se
#define lc (id<<1)
#define rc ((id<<1)|1)
#define db(x) cerr << ">>>>>> " << #x << " -> " << x << endl
#define nani(x) cerr <<  "Line " << __LINE__ << ": " << #x << " is " << x << endl
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define pllll pair<pll,pll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 1e6+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000000006;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 2000;
 
int n,x[MAX],ans[MAX],nx,nw,mn;
queue<int> q;
vector<int> v[MAX];
bool vis[MAX];
 
int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,1,n)cin>>x[i];
    rep(i,1,n){
        if(i>x[i])v[i-x[i]].pb(i);
        if(i+x[i]<=n)v[i+x[i]].pb(i);
    }
    memset(ans,-1,sizeof ans);
    //kerjain solusi untuk odd ke even
    rep(i,1,n){
        if(x[i]&1)continue;
        for(auto j:v[i]){
            if(!vis[j] && (x[j]&1))vis[j] = 1, q.push(j), ans[j] = 1;
        }
    }
    while(!q.empty()){
        nw = q.front(); q.pop();
        for(auto j:v[nw]){
            if(!vis[j] && (x[j]&1))vis[j] = 1, q.push(j), ans[j] = ans[nw]+1;
        }
    }
    //kebalikannya
    rep(i,1,n){
        if(x[i]&1)
        for(auto j:v[i]){
            if(!vis[j] && !(x[j]&1))vis[j] = 1, q.push(j), ans[j] = 1;
        }
    }
    while(!q.empty()){
        nw = q.front(); q.pop();
        for(auto j:v[nw]){
            if(!vis[j] && !(x[j]&1))vis[j] = 1, q.push(j), ans[j] = ans[nw]+1;
        }
    }
    rep(i,1,n)cout<<ans[i]<<" "; cout<<endl;
    return 0;
}