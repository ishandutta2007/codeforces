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

int main() {
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    string S,T;cin>>S>>T;
    int N=si(S),M=si(T);
    vector<int> p(N);
    for(int i=0;i<N;i++){
        cin>>p[i];p[i]--;
    }
    int left=0,right=N;
    while(right-left>1){
        int mid=(left+right)/2;
        vector<int> alive(N,true);
        for(int i=0;i<mid;i++) alive[p[i]]=false;
        string U;
        for(int i=0;i<N;i++) if(alive[i]) U+=S[i];
        int j=0;
        for(int i=0;i<si(U);i++){
            if(j<M&&U[i]==T[j]) j++;
        }
        if(j==M) left=mid;
        else right=mid;
    }
    
    cout<<left<<endl;
}