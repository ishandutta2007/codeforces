#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=1<<17,INF=(((1<<30)-1)<<1)+1;
 
ll rui(ll a,ll b){
    ll ans=1;
    while(b>0){
        if(b&1) ans=ans*a;
        a=a*a;
        b/=2;
    }
    return ans;
}
 
int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    vector<long double> prime={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61};
    while(Q){
        ll N;cin>>N;
        ll diff=0;
        for(long double p:prime){
            if(p>=38){
                if(rui(2,p)<=N) diff++;
                continue;
            }else if(p>=30){
                if(rui(2,p)<=N) diff++;
                if(rui(3,p)<=N) diff++;
                continue;
            }else if(p>=26){
                if(rui(2,p)<=N) diff++;
                if(rui(3,p)<=N) diff++;
                if(rui(4,p)<=N) diff++;
                continue;
            }else if(p>=24){
                if(rui(2,p)<=N) diff++;
                if(rui(3,p)<=N) diff++;
                if(rui(4,p)<=N) diff++;
                if(rui(5,p)<=N) diff++;
                continue;
            }else if(p>=22){
                if(rui(2,p)<=N) diff++;
                if(rui(3,p)<=N) diff++;
                if(rui(4,p)<=N) diff++;
                if(rui(5,p)<=N) diff++;
                if(rui(6,p)<=N) diff++;
                continue;
            }else if(p>=20){
                if(rui(2,p)<=N) diff++;
                if(rui(3,p)<=N) diff++;
                if(rui(4,p)<=N) diff++;
                if(rui(5,p)<=N) diff++;
                if(rui(6,p)<=N) diff++;
                if(rui(7,p)<=N) diff++;
                continue;
            }
            ll left=1,right=ll(pow(N,1.0/p)+2);
            while(right-left>1){
                ll mid=(left+right)/2;
                if(rui(mid,p)>N) right=mid;
                else left=mid;
            }
            diff+=left-1;
        }
        
        for(int i=0;i<7;i++){
            for(int j=i+1;prime[i]*prime[j]<64;j++){
                double p=prime[i]*prime[j];
                if(p>=38){
                    if(rui(2,p)<=N) diff--;
                    continue;
                }else if(p>=30){
                    if(rui(2,p)<=N) diff--;
                    if(rui(3,p)<=N) diff--;
                    continue;
                }else if(p>=26){
                if(rui(2,p)<=N) diff--;
                if(rui(3,p)<=N) diff--;
                if(rui(4,p)<=N) diff--;
                continue;
                }else if(p>=24){
                if(rui(2,p)<=N) diff--;
                if(rui(3,p)<=N) diff--;
                if(rui(4,p)<=N) diff--;
                if(rui(5,p)<=N) diff--;
                continue;
                }else if(p>=22){
                if(rui(2,p)<=N) diff--;
                if(rui(3,p)<=N) diff--;
                if(rui(4,p)<=N) diff--;
                if(rui(5,p)<=N) diff--;
                if(rui(6,p)<=N) diff--;
                continue;
            }else if(p>=20){
                if(rui(2,p)<=N) diff--;
                if(rui(3,p)<=N) diff--;
                if(rui(4,p)<=N) diff--;
                if(rui(5,p)<=N) diff--;
                if(rui(6,p)<=N) diff--;
                if(rui(7,p)<=N) diff--;
                continue;
            }
                ll left=1,right=ll(pow(N,1.0/p)+2);
                while(right-left>1){
                    ll mid=(left+right)/2;
                    if(rui(mid,p)>N) right=mid;
                    else left=mid;
                }
                diff-=left-1;
            }
        }
        
        for(int j=1;j<5;j++){
            for(int k=j+1;k<j+4;k++){
                double p=2.0*prime[j]*prime[k];
                if(p>=64) continue;
                if(p>=38){
                    if(rui(2,p)<=N) diff++;
                    continue;
                }else if(p>=30){
                    if(rui(2,p)<=N) diff++;
                    if(rui(3,p)<=N) diff++;
                    continue;
                }else if(p>=26){
                if(rui(2,p)<=N) diff++;
                if(rui(3,p)<=N) diff++;
                if(rui(4,p)<=N) diff++;
                continue;
                }else if(p>=24){
                if(rui(2,p)<=N) diff++;
                if(rui(3,p)<=N) diff++;
                if(rui(4,p)<=N) diff++;
                if(rui(5,p)<=N) diff++;
                continue;
                }else if(p>=22){
                if(rui(2,p)<=N) diff++;
                if(rui(3,p)<=N) diff++;
                if(rui(4,p)<=N) diff++;
                if(rui(5,p)<=N) diff++;
                if(rui(6,p)<=N) diff++;
                continue;
            }else if(p>=20){
                if(rui(2,p)<=N) diff++;
                if(rui(3,p)<=N) diff++;
                if(rui(4,p)<=N) diff++;
                if(rui(5,p)<=N) diff++;
                if(rui(6,p)<=N) diff++;
                if(rui(7,p)<=N) diff++;
                continue;
            }
                ll left=1,right=ll(pow(N,1.0/p)+2);
                while(right-left>1){
                    ll mid=(left+right)/2;
                    if(rui(mid,p)>N) right=mid;
                    else left=mid;
                }
                diff+=left-1;
            }
        }
        
        cout<<N-1-diff<<"\n";
        
        Q--;
    }
}