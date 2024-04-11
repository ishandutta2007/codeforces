#include<bits/stdc++.h>
using namespace std;
#define ll long long
int loc[2000000];
int a[1000000];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        int tot = 0;
        for (int i=1;i<=2*n;i++) {
            cin>>a[i];
            if (a[i]==1)tot++;
            else tot--;
        }
        int offset=1e6;
        for (int i=offset-3*n;i<=offset+3*n;i++)loc[i]=0;
        int cur=offset+tot;
        loc[cur]=n+1;
        for (int i=n;i>=1;i--){
            if (a[i]==2)cur++;
            else cur--;
            loc[cur]=max(loc[cur],i);
        }
        int ret=n - loc[offset] + 1;
        if (loc[offset]==0)ret=1e9;
        if (tot==0)ret=0;
        cur=0;
        for (int i=n+1;i<=2*n;i++) {
            if (a[i]==2)cur++;
            else cur--;
            int need = -cur + offset;
            if (loc[need]!=0)
                ret=min(ret , n+1-loc[need]+(i-n));
        }
        cout<<ret<<endl;
    }
}