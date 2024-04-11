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
const int mod=1000000007,MAX=200005;
const ll INF=1LL<<60;
bool ok[MAX][5];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    string S;cin>>S;
    int N=si(S);
    set<string> SE;
    
    ok[0][2]=ok[0][3]=1;
    
    reverse(all(S));
    
    for(int i=2;i<N;i++){
        for(int j=2;j<=3;j++){
            if(i-j<0) continue;
            string A=S.substr(i-j,j);
            
            for(int k=2;k<=3;k++){
                if(ok[i-j][k]){
                    if(i-j==0) ok[i][j]=1;
                    else{
                        string B=S.substr(i-j-k,k);
                        if(A!=B) ok[i][j]=1;
                    }
                }
            }
        }
    }
    
    reverse(all(S));
    
    
    for(int i=5;i<N;i++){
        for(int j=2;j<=3;j++){
            int rem=N-i-j;
            if(rem<0||rem==1) continue;
            if(ok[rem][2]||ok[rem][3]) SE.insert(S.substr(i,j));
        }
    }
    
    cout<<si(SE)<<endl;
    for(auto x:SE) cout<<x<<"\n";
    
}