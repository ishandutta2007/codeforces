#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=200003;
const ll INF=1LL<<61;

ll rui(ll a,ll b){
    ll ans=1;
    while(b>0){
        if(b&1) ans=ans*a;
        if(b!=1) a=a*a;
        b/=2;
    }
    return ans;
}

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int Q;cin>>Q;
    while(Q){
        ll A,B,M;cin>>A>>B>>M;
        ll left=A+1,right=A+M;
        int cnt=-1;
        bool ok=false;
        for(int i=3;i<=53;i++){
            left*=2;
            if(right<=INF) right*=2;
            if(left<=B&&B<=right){
                ok=true;
                cnt=i;
                break;
            }
            if(left>B) break;
        }
        if(A==B) cout<<1<<" "<<A<<endl;
        else if(B<=A+M) cout<<2<<" "<<A<<" "<<B<<endl;
        else if(!ok) cout<<-1<<endl;
        else{
            cout<<cnt;
            vector<ll> r(cnt-1,1);
            B-=A*rui(2,cnt-2);
            B-=rui(2,cnt-2);
            
            for(int i=0;i<cnt-2;i++){
                r[i]+=min(M-1,B/rui(2,cnt-3-i));
                B-=(r[i]-1)*rui(2,cnt-3-i);
            }
            r[cnt-2]+=B;
            //for(int a:r) cout<<a<<" ";
            ll now=A;cout<<" "<<now<<" "<<now+r[0];
            now+=r[0];
            for(int i=1;i<cnt-1;i++){
                now*=2;
                now-=r[i-1];
                now+=r[i];
                cout<<" "<<now;
            }
            cout<<endl;
        }
        
        Q--;
    }
    
}