#include <bits/stdc++.h>
using namespace std;
int a[1000000];
int b[1000000];
int price[1000000];
int best[1000000][2];
int ret[1000000];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    int mx = (1<<9);
    for (int i=0;i<mx;i++)
        best[i][0]=best[i][1]=-1;
    for (int i=0;i<n;i++) {
        int k;
        cin>>k;
        int mask=0;
        for (int j=0;j<k;j++) {
            int x;
            cin>>x;
            mask+=(1<<(x-1));
        }
        a[i]=mask;
        ret[mask]++;
    }
    for(int i = 0;i < 9; ++i) for(int mask = 0; mask < mx; ++mask){
        if(mask & (1<<i))
            ret[mask] += ret[mask^(1<<i)];
    }
    for (int i=0;i<m;i++) {
        cin>>price[i];
        int k;
        cin>>k;
        int mask=0;
        for (int j=0;j<k;j++) {
            int x;
            cin>>x;
            mask+=(1<<(x-1));
        }
        b[i]=mask;
        if (best[mask][0]==-1)
            best[mask][0]=i;
        else if (price[i]<price[best[mask][0]])
        {
            best[mask][1]=best[mask][0];
            best[mask][0]=i;
        }
        else if (best[mask][1]==-1)
            best[mask][1]=i;
        else if (price[i]<price[best[mask][1]])
            best[mask][1]=i;
    }
    int ans=-1,bA,bB;
    int ansC=2e9;
    for (int i=0;i<mx;i++) {
        for (int j=0;j<mx;j++) {
            if (best[i][0]==-1 || best[j][0]==-1)continue;
            int cost;
            int A,B;
            if (i==j) {
                if (best[i][1]==-1)continue;
                cost = price[best[i][0]]+price[best[i][1]];
                A = best[i][0],B=best[i][1];
            } else {
                cost = cost = price[best[i][0]]+price[best[j][0]];
                A = best[i][0], B=best[j][0];
            }
            if (ret[i|j]>ans || (ret[i|j]==ans && cost<=ansC)) {
                ans = ret[i|j];
                ansC=cost;
                bA=A,bB=B;
            }
        }
    }
    cout<<bA+1<<' '<<bB+1<<endl;
}