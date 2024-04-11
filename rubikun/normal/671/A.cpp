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
typedef double ld;

ld hypo(ld a,ld b){
    return sqrt(a*a+b*b);
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;
    ld x1,y1,x2,y2,o1,o2;cin>>x1>>y1>>x2>>y2>>o1>>o2;
    cin>>N;
    ld ans=0,sum=0;
    
    ans+=hypo(x1-o1,y1-o2)+hypo(x2-o1,y2-o2);
    
    vector<pair<ld,int>> A(N),B(N);
    
    for(int i=0;i<N;i++){
        ld x,y;cin>>x>>y;
        ans+=2.0*hypo(x-o1,y-o2);
        sum+=2.0*hypo(x-o1,y-o2);
        A[i]=mp(hypo(x-x1,y-y1)-(hypo(x-o1,y-o2)+hypo(x1-o1,y1-o2)),i);
        B[i]=mp(hypo(x-x2,y-y2)-(hypo(x-o1,y-o2)+hypo(x2-o1,y2-o2)),i);
    }
    
    A.push_back(mp(0,-1));
    B.push_back(mp(0,-1));
    
    sort(all(A));
    sort(all(B));
    
    if(A[0].se!=B[0].se){
        ans+=A[0].fi+B[0].fi;
    }else{
        ld a=A[0].fi+B[1].fi,b=A[1].fi+B[0].fi;
        ans+=min(a,b);
    }
    
    chmin(ans,sum+hypo(x1-o1,y1-o2)+A[0].fi);
    chmin(ans,sum+hypo(x2-o1,y2-o2)+B[0].fi);
    
    cout<<fixed<<setprecision(30)<<ans<<endl;
}