#include<bits/stdc++.h>
using namespace std;
#define ll long long
int num[1000000];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int dif=0;
        for (int i=1;i<=n;i++)num[i]=0;
        for (int i=1;i<=n;i++){
            int x;
            cin>>x;
            num[x]++;
            if (num[x]==1)dif++;
        }
        int ret=0;
        for (int i=1;i<=n;i++){
            if (num[i]==0)continue;
            ret = max(ret, min(num[i], dif-1));
            ret = max(ret, min(num[i]-1, dif));
        }
        cout<<ret<<endl;
    }
}