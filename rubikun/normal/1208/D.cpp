#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=1<<18,INF=1<<30;

ll bit[MAX+1];
int N;

//1-indexed

ll sum(int i){
    ll s=0;
    while(i>0){
        s+=bit[i];
        i-=i&-i;
    }
    return s;
}

//st=sum(t)-sum(s-1)

void add(int i,ll x){
    while(i<=N){
        bit[i]+=x;
        i+=i&-i;
    }
}

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    cin>>N;
    for(int i=1;i<=N;i++){
        add(i,i);
    }
    vector<ll> ans(N),A(N),used(N+1);
    for(int i=0;i<N;i++){
        scanf("%lld",&A[i]);
    }
    
    for(int i=N-1;i>=0;i--){
        int left=1,right=N+1;
        while(1){
            int mid=(left+right)/2;
            ll a=sum(mid-1);
            if(a>A[i]) right=mid;
            else if(a<A[i]) left=mid;
            else if(used[mid]==1) left=mid;
            else{
                right=mid;
                break;
            }
        }
        ans[i]=right;
        used[right]=1;
        add(right,-right);
    }
    
    for(int i=0;i<N;i++){
        if(i) printf(" ");
        printf("%lld",ans[i]);
    }
    
    cout<<endl;
}