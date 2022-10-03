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
const int mod=1000000007,MAX=15000005,INF=1<<30;

vector<int> prime;//i
bool is_prime[MAX+1];

void sieve(int n){
    for(int i=0;i<=n;i++){
        is_prime[i]=true;
    }
    
    is_prime[0]=is_prime[1]=false;
    
    for(int i=2;i<=n;i++){
        if(is_prime[i]){
            prime.push_back(i);
            for(int j=2*i;j<=n;j+=i){
                is_prime[j] = false;
            }
        }
    }
}

ll gcd(ll a,ll b){
    if(b==0) return a;
    return gcd(b,a%b);
}

int cnt[MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    vector<int> A(N);
    int g=0;
    for(int i=0;i<N;i++){
        cin>>A[i];
        g=gcd(g,A[i]);
    }
    
    for(int i=0;i<N;i++){
        A[i]/=g;
        cnt[A[i]]++;
    }
    
    if(cnt[1]==N){
        cout<<-1<<endl;
        return 0;
    }
    
    sieve(MAX-3);
    
    int ma=0;
    
    for(int p:prime){
        int sum=0;
        for(int i=p;i<MAX;i+=p){
            sum+=cnt[i];
        }
        chmax(ma,sum);
    }
    
    cout<<N-ma<<endl;
}