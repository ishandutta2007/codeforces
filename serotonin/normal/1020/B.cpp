#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll sz=1e5+5;

ll chor[1005],bol[1005],done[1005],ans;
vector <ll> keke;

void ekhon(ll i)
{
    if(chor[i]!=0) {
        ans=chor[i];
        return;
    }
    if(done[i]==2) {
        ans=i;
        return;
    }
    done[bol[i]]++;
    keke.push_back(i);
    ekhon(bol[i]);
}

int main()
{
    memset(chor,0,sizeof chor);
    ll n,h,m,i,j,k,x,y,z,fin;
    scanf("%I64d", &n);
    for(i=1;i<=n;i++) scanf("%I64d", &bol[i]);
    for(i=1;i<=n;i++) {
        if(chor[i]!=0) {
            printf("%I64d ", chor[i]);
            continue;
        }

        memset(done, 0, sizeof done);
        done[i]++;
        ekhon(i);
        printf("%I64d ", ans);

        m=keke.size();
        for(j=0;j<m;j++) {
            if(keke[j]==ans) break;
            chor[keke[j]]=ans;
        }
        keke.clear();
    }
    puts("");
}