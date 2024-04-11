#include <iostream>
#include <vector>
using namespace std;
typedef long long LL;
int T;
LL a,m;
LL gcd(LL x,LL y){
    return y==0?x:gcd(y,x%y);
}
int main() {
    cin>>T;
    while(T--){
        cin>>a>>m;
        LL g=gcd(a,m);
        a/=g,m/=g;
        vector<LL> fac;

        LL tmp=m;
        for(LL x=2;x*x<=tmp;x++){
            if(tmp%x==0){
                fac.push_back(x);
                while(tmp%x==0) tmp/=x;
            }
        }
        if(tmp>1) fac.push_back(tmp);
        LL ans=0;
        for(int i=0;i<1<<fac.size();i++){
            LL tmp=1, cnt=0;
            for(int j=0;j<fac.size();j++) if(i>>j&1) {
                tmp *= fac[j]; ++cnt;
            }
            int sgn=cnt%2==0?1:-1;
            ans+=m/tmp*sgn;
        }
        cout<<ans<<endl;
    }
}