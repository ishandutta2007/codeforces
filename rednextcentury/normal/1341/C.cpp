#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[1000000];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<pair<int,int> > parts;
        for (int i=1;i<=n;i++) cin>>a[i];
        for (int i=1;i<=n;){
            int j=i;
            while(j+1<=n && a[j+1]-a[j]==1) j++;
            parts.emplace_back(a[i], a[j]);
            i=j+1;
        }
        bool ok = 1;
        for (int i=1;i<parts.size();i++){
            if (parts[i].second != parts[i-1].first - 1) ok=0;
        }
        if (ok)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}