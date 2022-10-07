#include<bits/stdc++.h>
using namespace std;
main()
{
    int n;
    pair<pair<int,int>,int> l[200009];
    cin>>n;
    for (int i=0; i<n; i++)
        {cin>>l[i].first.first>>l[i].first.second;
        l[i].first.second=-l[i].first.second;
            l[i].second=i+1;
        }
    sort(l,l+n);
    l[0].first.second*=-1;
   int  ma=l[0].first.second;
    for (int i=1; i<n; i++)
    {l[i].first.second=-l[i].first.second;
//cout<<l[i].first<<" "<<l[i+1].second<<endl;
        if(ma>=l[i].first.second) {cout<<l[i].second<<endl; return 0;}
       ma=max(ma,l[i].first.second);
        if(i<n-1 &&
            l[i+1].first.first<=l[i-1].first.second+1
            && l[i].first.second<=-l[i+1].first.second)
            {cout<<l[i].second<<endl; return 0;}
    }
    cout<<-1<<endl;
}
//