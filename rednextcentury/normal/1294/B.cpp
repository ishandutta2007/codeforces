#include<bits/stdc++.h>
using namespace std;
#define ll long long
pair<int,int> a[1000000];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        for (int i=1;i<=n;i++)cin>>a[i].first>>a[i].second;
        sort(a+1,a+n+1);
        int x=0,y=0;
        bool ok=1;
        string ret="";
        for (int i=1;i<=n;i++) {
            if (x>a[i].first || y>a[i].second)ok=0;
            if (!ok)break;
            while(x<a[i].first)ret+="R",x++;
            while(y<a[i].second)ret+="U",y++;
        }
        if (!ok)cout<<"NO"<<endl;
        else cout<<"YES"<<endl<<ret<<endl;
    }
}