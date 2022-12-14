#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll mod = 998244353;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        ll n,l,r;
        scanf("%lld%lld%lld",&n,&l,&r);
        ll cur = 0;
        vector<pair<ll,int> > vec;
        for (int i=1;i<=n;i++){
            int len = 2*(n-i);
            if (cur+len>=l && cur<=r){
                for (int j=i+1;j<=n;j++){
                    vec.push_back({cur+1,i});
                    vec.push_back({cur+2,j});
                    cur+=2;
                }
            } else {
                cur+=len;
            }
        }
        vec.push_back({cur+1,1});
        for (auto [id,val]:vec){
            if (id>=l && id<=r)printf("%d ",val);
        }
        printf("\n");
    }
}