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
    
    int Q;cin>>Q;
    while(Q--){
        string S;cin>>S;
        vector<int> A;
        int i=0;
        while(i<si(S)){
            while(i<si(S)&&S[i]=='0') i++;
            int j=i;
            while(j<si(S)&&S[j]=='1') j++;
            if(i!=j) A.push_back(j-i);
            i=j;
        }
        sort(all(A));
        reverse(all(A));
        int ans=0;
        for(int i=0;i<si(A);i+=2) ans+=A[i];
        cout<<ans<<"\n";
    }
}