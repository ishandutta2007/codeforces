#include<bits/stdc++.h>
using namespace std;
#define ll long long
int num[100];
int need[100];
int has[100];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--) {
        memset(num,0,sizeof(num));
        int n; ll m;
        cin>>m>>n;
        ll sum=0;
        for (int i=0;i<n;i++){
            ll x;
            cin>>x;
            sum+=x;
            int cur=0;
            while(x%2==0)x/=2,cur++;
            num[cur]++;
        }
        if (sum<m){
            cout<<-1<<endl;
            continue;
        }
        for (int i=0;i<70;i++)need[i]=(m%2),m/=2;
        int ret=0;
        for (int i=0;i<70;i++){
            int mn = min(need[i],num[i]);
            need[i]-=mn;
            num[i]-=mn;
            num[i+1]+=num[i]/2;
            need[i+1]+=(need[i]/2 + need[i]%2);
            ret+=(need[i]/2 + need[i]%2);
        }
        cout<<ret<<endl;
    }
}