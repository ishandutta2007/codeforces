#include <iostream>
using namespace std;
typedef long long LL;
const int N=100000+10;

int n;LL l[N],suf[N]; char s[N];
int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld",&l[i]);
    }
    scanf("%s",s+1);
    
    bool W=0;
    LL ans=0, energy=0, G=0;
    for(int i=1;i<=n;i++){
        if(s[i]=='L'){
            if(l[i]<=energy) {
                energy-=l[i],ans+=l[i];
            } else {
                ans+=energy;l[i]-=energy,energy=0; 
                if(W)ans+=4*l[i];else ans+=6*l[i];
            }
        }
        if(s[i]=='W'){
            W=1;
            ans+=3*l[i];energy+=l[i];
        }
        if(s[i]=='G'){
            ans+=5*l[i];energy+=l[i];
            G+=2*l[i];
        }
        G=min(G,energy);
    }
    //printf("energy = %lld, G=%d, ans=%lld\n", energy,G,ans);

    ans -= 4*G/2;
    ans -= 2*(energy-G)/2;
    cout<<ans<<endl;
}