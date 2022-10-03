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
const int mod=1000000007,MAX=200005,INF=1<<29;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n,t,k,d;cin>>n>>t>>k>>d;
    int rem1=n,rem2=n;
    for(int i=1;;i++){
        if(i%t==0){
            rem1-=k;
            rem2-=k;
        }
        if(i>d&&i%t==d%t){
            rem2-=k;
        }
        if(rem2<=0){
            if(rem1<=0){
                cout<<"NO\n";
            }else{
                cout<<"YES\n";
            }
            return 0;
        }
    }
}