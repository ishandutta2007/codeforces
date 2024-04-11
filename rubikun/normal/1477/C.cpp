#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define mp make_pair
#define si(x) int(x.size())
const int mod=1000000007,MAX=5005;
const ll INF=1LL<<40;

struct Point{
    ll x;
    ll y;
    int id;
};

Point P[MAX];

vector<int> trail;

bool dot(int a,int b,int c){
    if(b==-1) return 1;
    
    ll sx=P[b].x-P[a].x,sy=P[b].y-P[a].y;
    ll gx=P[c].x-P[a].x,gy=P[c].y-P[a].y;
    
    if(sx*gx+sy*gy>0) return 1;
    return 0;
}

void DFS(int u,int p,vector<int> rem){
    if(si(rem)==0){
        for(int a:trail) cout<<a+1<<" ";
        cout<<endl;
        exit(0);
    }
    
    for(int to:rem){
        if(dot(u,p,to)){
            trail.push_back(to);
            vector<int> tt;
            for(int a:rem) if(a!=to) tt.push_back(a);
            
            DFS(to,u,tt);
            
            trail.pop_back();
        }
    }
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    for(int i=0;i<N;i++){
        cin>>P[i].x>>P[i].y;
        P[i].id=i;
    }
    
    vector<int> A(N-1);
    iota(all(A),1);
    
    trail.push_back(0);
    DFS(0,-1,A);
    
    cout<<-1<<endl;
}