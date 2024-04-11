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
const int mod=1000000007,MAX=10000005,INF=1<<30;

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

int divv[MAX];

ll gcd(ll a,ll b){
    if(b==0) return a;
    return gcd(b,a%b);
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    sieve(MAX-2);
    
    int N;cin>>N;
    
    for(int p:prime){
        for(int j=2;p*j<=10000000;j++){
            if(divv[p*j]==0) divv[p*j]=p;
        }
    }
    
    vector<int> A(N,-1),B(N,-1);
    
    for(int i=0;i<N;i++){
        int a;cin>>a;
        if(divv[a]){
            int b=a;
            int x=1;
            while(b%divv[a]==0){
                x*=divv[a];
                b/=divv[a];
            }
            int y=a/x;
            if(gcd(x+y,a)==1&&y>1){
                A[i]=x;
                B[i]=y;
            }
        }
    }
    
    for(int i=0;i<N;i++) cout<<A[i]<<" ";
    cout<<endl;
    for(int i=0;i<N;i++) cout<<B[i]<<" ";
    cout<<endl;
}