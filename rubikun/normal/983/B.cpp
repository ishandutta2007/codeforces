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
const int mod=1000000007,MAX=200005,INF=1<<30;

struct dat{
    int l;
    int r;
    int id;
};

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    vector<vector<int>> A(N,vector<int>(N));
    for(int i=0;i<N;i++) cin>>A[0][i];
    
    for(int i=1;i<N;i++){
        for(int j=0;j<N-i;j++){
            A[i][j]=A[i-1][j]^A[i-1][j+1];
        }
    }
    
    int Q;cin>>Q;
    vector<dat> S(Q);
    for(int i=0;i<Q;i++){
        cin>>S[i].l>>S[i].r;
        S[i].r=S[i].r-S[i].l;
        S[i].l--;
        S[i].id=i;
    }
    sort(all(S),[](auto a,auto b){
        if(a.l==b.l) return a.r<b.r;
        return a.l<b.l;
    });
    
    vector<int> ans(Q);
    
    vector<vector<int>> seg(N,vector<int>(N,-1));
    
    for(int i=0;i<N;i++){
        for(int j=0;i-j>=0;j++){
            seg[i][j]=A[i-j][j];
        }
    }
    
    for(int i=0;i<N;i++){
        for(int j=N-2;j>=0;j--){
            chmax(seg[i][j],seg[i][j+1]);
        }
    }
    
    int ma=-1,now=0;
    
    for(int i=0;i<Q;i++){
        //cout<<S[i].l<<" "<<S[i].r<<" "<<S[i].id<<endl;
        if(i){
            if(S[i-1].l!=S[i].l){
                ma=-1;
                now=0;
            }
        }
        
        while(now<=S[i].r){
            chmax(ma,seg[S[i].l+now][S[i].l]);
            now++;
        }
        
        ans[S[i].id]=ma;
    }
    
    for(int i=0;i<Q;i++) cout<<ans[i]<<"\n";
}