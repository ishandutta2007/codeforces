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
const int mod=1000000007,MAX=1005,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    vector<pair<int,int>> S(N);
    for(int i=0;i<N;i++){
        cin>>S[i].fi>>S[i].se;
    }
    
    vector<int> xmin(N),xmax(N),ymin(N),ymax(N);
    iota(all(xmin),0);
    iota(all(xmax),0);
    iota(all(ymin),0);
    iota(all(ymax),0);
    
    sort(all(xmin),[&](int a,int b){
        return S[a].fi<S[b].fi;
    });
    
    sort(all(xmax),[&](int a,int b){
        return S[a].fi>S[b].fi;
    });
    
    sort(all(ymin),[&](int a,int b){
        return S[a].se<S[b].se;
    });
    
    sort(all(ymax),[&](int a,int b){
        return S[a].se>S[b].se;
    });
    
    set<int> SE;
    SE.insert(xmin[0]);
    SE.insert(xmax[0]);
    SE.insert(ymin[0]);
    SE.insert(ymax[0]);
    
    int xdiff=S[xmax[0]].fi-S[xmin[0]].fi;
    int ydiff=S[ymax[0]].se-S[ymin[0]].se;
    
    if(si(SE)<=3){
        for(int i=3;i<=N;i++){
            cout<<(xdiff+ydiff)*2<<" ";
        }
        cout<<endl;
    }else{
        vector<int> A={xmin[0],xmax[0],ymin[0],ymax[0]};
        
        int ma=0;
        
        for(int a=0;a<4;a++){
            for(int b=a+1;b<4;b++){
                for(int i=0;i<N;i++){
                    if(i==A[a]||i==A[b]) continue;
                    
                    int xmi=min({S[A[a]].fi,S[A[b]].fi,S[i].fi}),xma=max({S[A[a]].fi,S[A[b]].fi,S[i].fi});
                    int ymi=min({S[A[a]].se,S[A[b]].se,S[i].se}),yma=max({S[A[a]].se,S[A[b]].se,S[i].se});
                    
                    chmax(ma,(xma-xmi+yma-ymi)*2);
                }
            }
        }
        
        cout<<ma;
        for(int i=4;i<=N;i++){
            cout<<" "<<(xdiff+ydiff)*2;
        }
        cout<<endl;
    }
}