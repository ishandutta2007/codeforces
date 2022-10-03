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

string S,T;
vector<int> ans;
int N;

void f(int x){
    string A=S.substr(0,N-x),B=S.substr(N-x);
    reverse(all(B));
    
    ans.push_back(x);
    S=B+A;
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin>>N;
    cin>>S>>T;
    
    {
        string A=S,B=T;
        sort(all(A));
        sort(all(B));
        if(A!=B){
            cout<<-1<<endl;
            return 0;
        }
    }
    
    for(int i=N-1;i>=0;i--){
        for(int j=N-1-i;j<N;j++){
            if(S[j]==T[i]){
                f(N);
                f(j);
                f(1);
                break;
            }
        }
    }
    
    cout<<si(ans)<<endl;
    for(int a:ans) cout<<a<<" ";
    cout<<endl;
}