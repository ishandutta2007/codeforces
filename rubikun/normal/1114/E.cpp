#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=5005,INF=1<<29;

ll gcd(ll a,ll b){
    if(b==0) return a;
    return gcd(b,a%b);
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    mt19937_64 rng(58);
    
    int N;cin>>N;
    int left=0,right=1000000000;
    for(int k=0;k<30;k++){
        int mid=(left+right)/2;
        cout<<"> "<<mid<<endl;
        bool p;cin>>p;
        if(p) left=mid;
        else right=mid;
    }
    int ma=left+1;
    
    vector<int> A;
    
    for(int k=0;k<30;k++){
        int x=rng()%N+1;
        cout<<"? "<<x<<endl;
        int a;cin>>a;
        //a=C[x];
        A.push_back(a);
    }
    
    sort(all(A));
    
    int ans=0;
    
    for(int i=0;i+1<A.size();i++){
        ans=gcd(ans,A[i+1]-A[i]);
    }
    
    cout<<"! "<<ma-ans*(N-1)<<" "<<ans<<endl;
}