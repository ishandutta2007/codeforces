#include <iostream>
using namespace std;
typedef long long LL;
LL C,Hr,Hb,Wr,Wb;

int main(){
    cin>>C>>Hr>>Hb>>Wr>>Wb;
    LL ans=0;
    if (Wr >= 1e4) {
        for(LL x=0;x*Wr<=C;x++){
            LL tmp = x*Hr + (C-x*Wr)/Wb * Hb; ans=max(ans,tmp);
        }
    }
    if (Wb >= 1e4) {
        for(LL x=0;x*Wb<=C;x++) {
            LL tmp = x*Hb + (C-x*Wb)/Wr * Hr; ans=max(ans,tmp);
        }
    }

    if(Hr * Wb <= Hb * Wr) {
        swap(Hr,Hb); swap(Wr,Wb);
    }
    for(LL x=C/Wr;x>=max(0LL,C/Wr-(LL)1e7);x--) {
        LL tmp = x*Hr + (C-x*Wr)/Wb * Hb; ans=max(ans,tmp);
    }
    cout<<ans<<endl;
}