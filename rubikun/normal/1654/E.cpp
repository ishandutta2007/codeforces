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
const int mod=998244353,MAX=31000005,INF=1<<30;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

const int D=300;
const int lim=345;
int cn[MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    vector<int> A(N);
    for(int i=0;i<N;i++) cin>>A[i];
    
    int ans=0;
    
    for(int q=0;q<2;q++){
        vector<int> save=A;
        for(int t=0;t<=D;t++){
            for(int i=0;i<N;i++){
                cn[A[i]]++;
            }
            for(int i=0;i<N;i++){
                chmax(ans,cn[A[i]]);
                cn[A[i]]=0;
            }
            for(int i=0;i<N;i++) A[i]+=i;
        }
        A=save;
        reverse(all(A));
    }
    
    for(int i=0;i<N;i++){
        unordered_map<int,int,custom_hash> MA;
        for(int j=i+1;j<=i+lim;j++){
            if(j>=N) break;
            if(abs(A[j]-A[i])%(j-i)) continue;
            //if(abs(A[j]-A[i])/(j-i)<=D) continue;
            MA[(A[j]-A[i])/(j-i)]++;
        }
        for(auto a:MA) chmax(ans,a.se+1);
    }
    
    cout<<N-ans<<"\n";
}