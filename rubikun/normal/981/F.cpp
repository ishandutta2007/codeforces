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
const int mod1=1000000007,mod2=1000000009,MAX=10005,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,L;cin>>N>>L;
    vector<ll> A(N),B(N);
    for(int i=0;i<N;i++) cin>>A[i];
    for(int i=0;i<N;i++){
        cin>>B[i];
        B[i]-=L;
    }
    
    sort(all(A));
    sort(all(B));
    for(int i=0;i<N;i++) B.push_back(B[i]+L);
    for(int i=0;i<N;i++) B.push_back(B[i]+L+L);
    
    int left=-1,right=L/2;
    while(right-left>1){
        int mid=(left+right)/2;
        int L=-N,R=N;
        for(int i=0;i<N;i++){
            int itl=lower_bound(all(B),A[i]-mid)-B.begin()-(N+i);
            int itr=upper_bound(all(B),A[i]+mid)-B.begin()-(N+i)-1;
            chmax(L,itl);
            chmin(R,itr);
        }
        if(L<=R) right=mid;
        else left=mid;
    }
    
    cout<<right<<endl;
    
}