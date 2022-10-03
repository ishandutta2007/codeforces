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
const int mod=998244353,MAX=100005,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    string S;cin>>S;
    bool f=false;
    for(int i=0;i<si(S);i++){
        if(S[i]!='a'){
            int j=i;
            while(j<si(S)&&S[j]!='a') j++;
            for(int k=i;k<j;k++) S[k]--;
            f=true;
            break;
        }
    }
    if(!f) S.back()='z';
    cout<<S<<endl;
}