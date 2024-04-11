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
int l[MAX],r[MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int H,W,Q;cin>>H>>W>>Q;
    int left=0,right=Q+1;
    vector<int> h(Q),w(Q);
    for(int i=0;i<Q;i++){
        cin>>h[i]>>w[i];
        h[i]--;
        w[i]--;
    }
    
    while(right-left>1){
        int mid=(left+right)/2;
        for(int i=0;i<=H;i++){
            l[i]=INF;
            r[i]=-INF;
        }
        for(int i=0;i<mid;i++){
            if(h[i]&1){
                chmax(r[h[i]/2],w[i]/2);
            }else{
                chmin(l[h[i]/2],w[i]/2);
            }
        }
        
        for(int i=1;i<=H;i++){
            chmin(l[i],l[i-1]);
            chmax(r[H-i],r[H-i+1]);
        }
        
        bool ok=true;
        for(int i=0;i<=H;i++){
            if(l[i]<=r[i]) ok=false;
        }
        
        if(ok) left=mid;
        else right=mid;
    }
    
    for(int i=0;i<left;i++) cout<<"YES\n";
    for(int i=left;i<Q;i++) cout<<"NO\n";
}