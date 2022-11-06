#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int>pi;
const int maxn=1e6+100;
int _,pr[10],cc;
ll p,q;
int main(){
    cin >> _;
    while (_--){
        cin >> p >> q;
        if (p%q){
            cout << p << endl;
            continue;
        }
        ll j=2,s; cc=0;
        ll ans=1;
        while (j*j<=q){
            if (q%j==0){
                s=1;
                while (q%j==0) q/=j,s*=j;
                ll tmp=p;
                while (tmp%s==0) tmp/=j;
                ans=max(ans,tmp);
            }
            ++j;
        }
        if (q>1){
            s=q;
            ll tmp=p;
            while (tmp%s==0) tmp/=q; ans=max(ans,tmp);
        }
        printf("%lld\n",ans);
    }
    return 0;
}