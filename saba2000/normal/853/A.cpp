#include<bits/stdc++.h>
#define F first
#define S second
using namespace std;
pair<int,int> c[400009];
int v[400009];
main(){
    int n,k;
    cin>>n>>k;
    for(int i=0; i<n; i++)
       {
        cin>>c[i].first;
        c[i].second=i+1;
       }
       sort(c,c+n); reverse(c,c+n);
       set<int> S;
       for (int i=k+1; i<=k+n; i++)
        S.insert(i);
        long long ans=0;
    for (int j=0; j<n; j++)
    {
        auto it=S.lower_bound(c[j].second);
        long long z=(*it);
        v[c[j].second-1]=z;
        S.erase(it);
        ans+=(z-c[j].second)*c[j].first;

    }

    cout<<ans<<endl;
    for(int i=0; i<n; i++)
       printf("%d ",v[i]);


}

//1 2 3 4