#include<cstdio>
#include<iostream>
#include<string>
#include<map>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;
int n,m;double k;map<string,int> a;vector<pair<string,int> > b;
int main()
{
    scanf("%d%d%lf",&n,&m,&k);
    for(int i=0;i<n;i++)
    {
        string x;int y;
        cin>>x>>y;
        y=(int)(y*k+1e-12);
        if(y<100)y=0;
        a[x]=y;
        if(y)b.push_back(make_pair(x,y));
    }
    for(int i=0;i<m;i++)
    {
        string x;cin>>x;
        if(a[x]==0)b.push_back(make_pair(x,a[x]));
    }
    sort(b.begin(),b.end());
    b.erase(unique(b.begin(),b.end()),b.end());
    printf("%d\n",(int)b.size());
    for(int i=0;i<(int)b.size();i++)
        cout<<b[i].first<<" "<<b[i].second<<endl;
    return 0;
}