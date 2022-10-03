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
const int mod=998244353,MAX=300005,INF=1<<30;

vector<int> dh={0,1,0,-1,0},dw={1,0,-1,0,0};

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int H,W;cin>>H>>W;
    int N=H*W;
    vector<vector<int>> A(H,vector<int>(W));
    vector<int> ok(N);
    vector<pair<int,int>> pos(N);
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            cin>>A[i][j];A[i][j]--;
            pos[A[i][j]]=mp(i,j);
        }
    }
    
    ok[0]=true;
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            for(int k=0;k<4;k++){
                int toh=i+dh[k],tow=j+dw[k];
                if(toh<0||toh>=H||tow<0||tow>=W) continue;
                if(A[i][j]>A[toh][tow]) ok[A[i][j]]=true;
            }
        }
    }
    
    vector<int> ng;
    for(int i=0;i<N;i++) if(!ok[i]) ng.push_back(i);
    
    if(si(ng)==0){
        cout<<0<<"\n";
        return 0;
    }
    
    if(si(ng)>10){
        cout<<2<<"\n";
        return 0;
    }
    
    vector<pair<int,int>> cand;
    for(int x:ng){
        int i=pos[x].fi,j=pos[x].se;
        for(int k=0;k<5;k++){
            int toh=i+dh[k],tow=j+dw[k];
            if(toh<0||toh>=H||tow<0||tow>=W) continue;
            cand.push_back(mp(toh,tow));
        }
    }
    
    sort(all(cand));
    cand.erase(unique(all(cand)),cand.end());
    
    vector<vector<int>> deta(H,vector<int>(W));
    
    for(auto [h,w]:cand) deta[h][w]=true;
    
    int ans=0;
    
    auto check=[&](int h,int w,int i,int j){
        for(int x:ng){
            int i=pos[x].fi,j=pos[x].se;
            bool f=false;
            for(int k=0;k<4;k++){
                int toh=i+dh[k],tow=j+dw[k];
                if(toh<0||toh>=H||tow<0||tow>=W) continue;
                if(A[i][j]>A[toh][tow]) f=true;
            }
            if(!f) return false;
        }
        for(int k=0;k<5;k++){
            int toh=h+dh[k],tow=w+dw[k];
            if(toh<0||toh>=H||tow<0||tow>=W) continue;
            if(A[toh][tow]==0) continue;
            bool f=false;
            for(int l=0;l<4;l++){
                int totoh=toh+dh[l],totow=tow+dw[l];
                if(totoh<0||totoh>=H||totow<0||totow>=W) continue;
                if(A[toh][tow]>A[totoh][totow]) f=true;
            }
            if(!f) return false;
        }
        for(int k=0;k<5;k++){
            int toh=i+dh[k],tow=j+dw[k];
            if(toh<0||toh>=H||tow<0||tow>=W) continue;
            if(A[toh][tow]==0) continue;
            bool f=false;
            for(int l=0;l<4;l++){
                int totoh=toh+dh[l],totow=tow+dw[l];
                if(totoh<0||totoh>=H||totow<0||totow>=W) continue;
                if(A[toh][tow]>A[totoh][totow]) f=true;
            }
            if(!f) return false;
        }
        return true;
    };
    
    for(auto [h,w]:cand){
        for(int i=0;i<H;i++){
            for(int j=0;j<W;j++){
                if(deta[i][j]&&mp(h,w)>=mp(i,j)) continue;
                
                swap(A[h][w],A[i][j]);
                if(check(h,w,i,j)) ans++;
                swap(A[h][w],A[i][j]);
            }
        }
    }
    
    if(ans==0){
        cout<<2<<"\n";
    }else{
        cout<<1<<" "<<ans<<"\n";
    }
}