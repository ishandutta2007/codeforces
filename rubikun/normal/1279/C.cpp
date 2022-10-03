#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=1<<18,INF=1<<30;

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

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int T;cin>>T;
    while(T--){
        int M;cin>>N>>M;
        memset(bit,0,min(int(sizeof(bit)),N*8));
        vector<int> A(N),B(M);
        ll ans=0;
        for(int i=0;i<N;i++){
            int a;cin>>a;
            a--;
            A[a]=i;
        }
        for(int i=0;i<M;i++){
            cin>>B[i];
            B[i]--;
        }
        
        for(int i=0;i<M;i++){
            int wh=A[B[i]]+1;
            
            if(sum(N)-sum(wh)==0){
                ans+=(wh-sum(wh)-1)*2+1;
                add(wh,1);
            }else{
                add(wh,1);
                ans++;
            }
        }
        
        cout<<ans<<endl;
    }
}