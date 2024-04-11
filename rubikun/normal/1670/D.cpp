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
const int mod=1000000007,MAX=300005;
const ll INF=1LL<<60;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N;cin>>N;
        ll left=0,right=100000;
        while(right-left>1){
            ll mid=(left+right)/2;
            vector<ll> A(3);
            for(int i=0;i<3;i++){
                A[i]=mid/3;
                if(mid%3>i) A[i]++;
            }
            ll sum=0;
            for(int i=0;i<3;i++){
                for(int j=i+1;j<3;j++){
                    sum+=A[i]*A[j];
                }
            }
            sum*=2;
            if(sum>=N) right=mid;
            else left=mid;
        }
        
        cout<<right<<"\n";
    }
}