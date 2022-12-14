#include<bits/stdc++.h>
using namespace std;
#define ll long long
int vis[202][202];
int loc[202][202];
int pre[202*202];
int T;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int a,b,q;
        cin>>a>>b>>q;
        T++;
        int len=0;
        int num=0;
        int A=0,B=0;
        for (int i=0;i<=a*b;i++){
            if (vis[i%a][i%b]==T)break;
            vis[i%a][i%b]=T;
            loc[i%a][i%b]=i;
            if (i)pre[i]=pre[i-1];
            else pre[i]=0;
            if (((i%a)%b)!=((i%b)%a)) pre[i]++;
            len++;
            A = i%a;
            B = i%b;
        }
        while(q--){
            ll l,r;
            cin>>l>>r;
            ll ans=0;
            int loc1 = loc[l%a][l%b];
            int loc2 = loc[r%a][r%b];
            if (r-l+1 == loc2 - loc1 + 1){
                ans = pre[loc2];
                if (loc1)ans-=pre[loc1-1];
            } else {
                ans = pre[len-1];
                if (loc1) ans-=pre[loc1-1];
                ans += pre[loc2];
                l+=(len - loc1);
                r-=loc2+1;
                ans += ((r-l+1)/len) * 1LL * pre[len-1];
            }
            cout<<ans<<' ';
        }
        cout<<endl;
    }
}