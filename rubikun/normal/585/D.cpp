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
const int mod=1000000007,MAX=35;
//const int INF=1<<30;
const ll INF=1LL<<60;

map<pair<ll,ll>,pair<ll,vector<int>>> MA;

int N;
ll A[MAX][3];

vector<int> X;

pair<ll,vector<int>> ans;

void DFS(int u,pair<ll,ll> diff,ll sum){
    if(si(X)&&u==N/2){
        if(MA.count(diff)) chmax(MA[diff],mp(sum,X));
        else MA[diff]=mp(sum,X);
        
        return;
    }
    
    if(si(X)&&u==N){
        pair<ll,ll> want={-diff.fi,-diff.se};
        if(MA.count(want)){
            vector<int> Y=MA[want].se;
            for(int a:X) Y.push_back(a);
            chmax(ans,mp(MA[want].fi+sum,Y));
        }
        return;
    }
    
    for(int i=0;i<3;i++){
        X.push_back(i);
        if(i==0){
            diff.fi+=A[u][1];
            diff.se+=A[u][2];
        }
        if(i==1){
            diff.fi-=A[u][0];
            diff.se+=A[u][2]-A[u][0];
            sum+=A[u][0];
        }
        if(i==2){
            diff.fi+=A[u][1]-A[u][0];
            diff.se-=A[u][0];
            sum+=A[u][0];
        }
        
        DFS(u+1,diff,sum);
        
        X.pop_back();
        if(i==0){
            diff.fi-=A[u][1];
            diff.se-=A[u][2];
        }
        if(i==1){
            diff.fi+=A[u][0];
            diff.se-=A[u][2]-A[u][0];
            sum-=A[u][0];
        }
        if(i==2){
            diff.fi-=A[u][1]-A[u][0];
            diff.se+=A[u][0];
            sum-=A[u][0];
        }
    }
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin>>N;
    for(int i=0;i<N;i++){
        for(int j=0;j<3;j++){
            cin>>A[i][j];
        }
    }
    
    if(N==1){
        pair<ll,int> res={-INF,0};
        for(int i=0;i<3;i++){
            vector<ll> X;
            for(int j=0;j<3;j++){
                if(i==j) continue;
                X.push_back(A[0][j]);
            }
            if(X[0]==X[1]) chmax(res,mp(X[0],i));
        }
        if(res.fi==-INF) cout<<"Impossible"<<endl;
        else{
            if(res.se==0) cout<<"MW"<<endl;
            if(res.se==1) cout<<"LW"<<endl;
            if(res.se==2) cout<<"LM"<<endl;
        }
        
        return 0;
    }
    
    ans={-INF,vector<int>()};
    
    DFS(0,{0,0},0);
    DFS(N/2,{0,0},0);
    
    if(ans.fi==-INF) cout<<"Impossible"<<endl;
    else{
        for(int a:ans.se){
            if(a==0) cout<<"MW"<<endl;
            if(a==1) cout<<"LW"<<endl;
            if(a==2) cout<<"LM"<<endl;
        }
    }
}