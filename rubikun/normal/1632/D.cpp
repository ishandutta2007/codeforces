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
const int mod=998244353,MAX=1005,INF=1<<29;

ll gcd(ll a,ll b){
    if(b==0) return a;
    return gcd(b,a%b);
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    vector<ll> A(N);
    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    int ans=0;
    vector<ll> S;
    multiset<ll> ng;
    for(int i=0;i<N;i++){
        if(A[i]==1){
            ans++;
            cout<<ans<<" ";
            S.clear();
            ng.clear();
        }else{
            bool ok=true;
            S.push_back(A[i]);
            ng.insert(i+A[i]-1);
            int left=-1,right=si(S)-1;
            while(right-left>1){
                int mid=(left+right)/2;
                ll g=gcd(S[mid],A[i]);
                if(g!=S[mid]) right=mid;
                else left=mid;
            }
            for(int j=right;j<si(S)-1;j++){
                auto it=ng.lower_bound(i-si(S)+1+j+S[j]-1);
                ng.erase(it);
                S[j]=gcd(S[j],A[i]);
                ng.insert(i-si(S)+1+j+S[j]-1);
                if(S[j]==si(S)-j) ok=false;
            }
            auto it=ng.lower_bound(i);
            if(it!=ng.end()&&(*it)==i) ok=false;
            if(ok){
                cout<<ans<<" ";
            }else{
                ans++;
                cout<<ans<<" ";
                S.clear();
                ng.clear();
            }
        }
    }
    
    cout<<"\n";
}