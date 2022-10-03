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

bool ok(vector<int> &a,vector<int> &b,vector<int> &c){
    int s=0;
    for(int j=0;j<5;j++){
        s+=(b[j]-a[j])*(c[j]-a[j]);
    }
    if(s>0) return 1;
    return 0;
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    vector<int> ans;
    vector<vector<int>> A(N,vector<int>(5));
    
    for(int i=0;i<N;i++){
        for(int j=0;j<5;j++){
            cin>>A[i][j];
        }
    }
    
    for(int i=0;i<N;i++){
        bool check=false;
        for(int j=0;j<N;j++){
            for(int k=0;k<N;k++){
                if(j==k) continue;
                
                if(ok(A[i],A[j],A[k])){
                    check=true;
                    break;
                }
            }
            if(check) break;
        }
        if(!check) ans.push_back(i+1);
    }
    
    cout<<si(ans)<<endl;
    for(int a:ans) cout<<a<<"\n";
    
}