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
const int mod=998244353,MAX=300005;
const ll INF=1LL<<60;

vector<string> A(2),B(2);

set<vector<string>> SE;

void solve(vector<string> S){
    if(S==B){
        cout<<"YES\n";
        exit(0);
    }
    if(SE.count(S)) return;
    SE.insert(S);
    for(int i=0;i<2;i++){
        if(S[i][0]=='X'||S[i][1]=='X'){
            swap(S[i][0],S[i][1]);
            solve(S);
            swap(S[i][0],S[i][1]);
        }
    }
    for(int j=0;j<2;j++){
        if(S[0][j]=='X'||S[1][j]=='X'){
            swap(S[0][j],S[1][j]);
            solve(S);
            swap(S[0][j],S[1][j]);
        }
    }
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    //vector<string> A(2),B(2);
    for(int i=0;i<2;i++) cin>>A[i];
    for(int i=0;i<2;i++) cin>>B[i];
    
    solve(A);
    
    cout<<"NO\n";
}