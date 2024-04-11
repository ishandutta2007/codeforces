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

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    vector<ll> A(N),cnt(40);
    for(int i=0;i<N;i++){
        cin>>A[i];
        for(int k=35;k>=0;k--){
            if(A[i]&(1LL<<k)){
                cnt[k]++;
                break;
            }
        }
    }
    
    sort(all(cnt));
    
    if(cnt.back()>=3){
        cout<<1<<endl;
        return 0;
    }
    
    int ans=INF;
    
    for(int a=0;a<N;a++){
        for(int b=a;b<N;b++){
            int c=b+1;
            if(c>=N) continue;
            int x=0;
            for(int k=a;k<=b;k++) x^=A[k];
            for(int d=c;d<N;d++){
                int y=0;
                for(int k=c;k<=d;k++) y^=A[k];
                if(x>y) chmin(ans,b-a+d-c);
                
                //cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<x<<" "<<y<<endl;
            }
        }
    }
    
    if(ans==INF) ans=-1;
    cout<<ans<<endl;
}