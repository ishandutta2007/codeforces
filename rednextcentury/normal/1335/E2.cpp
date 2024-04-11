#include<bits/stdc++.h>
using namespace std;
#define ll long long
int cnt[200001][201];
int a[200001];
int cntL[201];
int cntR[201];
int L[201];
int R[201];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for (int i=1;i<=n;i++){
            cin>>a[i];
            for (int j=1;j<=200;j++) cnt[i][j]=cnt[i-1][j];
            cnt[i][a[i]]++;

        }
        int ret=0;
        for (int i=1;i<=200;i++)ret=max(ret,cnt[n][i]) , cntL[i]=0,cntR[i]=0,L[i]=0,R[i]=n+1;
        for (int i=1;i<=n;i++){
            cntL[a[i]]++;
            while(R[a[i]]-1>i && cntR[a[i]]<cntL[a[i]]){
                cntR[a[i]]+=a[R[a[i]]-1]==a[i];
                R[a[i]]--;
            }
            if (cntL[a[i]]==cntR[a[i]]){
                int mx=0;
                for (int v=1;v<=200;v++)mx=max(mx,cnt[R[a[i]]-1][v]-cnt[i][v]);
                ret=max(ret,mx+cntL[a[i]]*2);
            }

        }
        cout<<ret<<endl;
        
    }
}