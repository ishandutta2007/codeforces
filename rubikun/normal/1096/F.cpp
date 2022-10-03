#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=998244353,MAX=1<<18,INF=1<<30;

int bit[MAX+1],N;
//1-indexed

int sum(int i){
    int s=0;
    while(i>0){
        s+=bit[i];
        i-=i&-i;
    }
    return s;
}

//st=sum(t)-sum(s-1)

void add(int i,int x){
    while(i<=N){
        bit[i]+=x;
        i+=i&-i;
    }
}

ll rui(ll a,ll b){
    if(b==1) return a%mod;
    else if(b==0) return 1;
    else if(b%2==0) return (rui(a,b/2)*rui(a,b/2))%mod;
    else return (rui(a,b-1)*a)%mod;
}


int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    cin>>N;
    vector<ll> A(N),when(N+1,0),B(N+1,0),cntminus(N+1,0);
    ll cnt=0;//-1
    for(int i=0;i<N;i++){
        cin>>A[i];
        if(A[i]!=-1) when[A[i]]=i+1;
        else cnt++;
    }
    ll ans=0;
    
    for(int i=1;i<=N;i++){
        if(when[i]!=0){
            ans+=sum(N)-sum(when[i]-1);
            add(when[i],1);
        }
    }
    
    for(int i=N-1;i>=0;i--){
        if(A[i]==-1) cntminus[i]=cntminus[i+1]+1;//-1
        else cntminus[i]=cntminus[i+1];
    }
    
    for(int i=1;i<=N;i++){
        if(when[i]==0) B[i]=B[i-1]+1;//i-1
        else B[i]=B[i-1];
    }
    ans%=mod;
    
    ll ans2=0;
    
    for(int i=0;i<N;i++){
        if(A[i]!=-1){
            ans2+=cntminus[i]*B[A[i]];
            ans2+=(cnt-cntminus[i])*(cnt-B[A[i]]);
            ans2%=mod;
        }
    }
    //cout<<ans<<" "<<ans2<<endl;
    
    ans2=ans2*rui(cnt,mod-2)%mod;
    
    ans=(ans+ans2+((cnt)*(cnt-1))%mod*rui(4,mod-2))%mod;
    
    cout<<ans<<endl;
    
}