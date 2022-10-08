#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,m,S=0;scanf("%d%d",&n,&m);vector<pair<int,int> > a;vector<int> v(n,0);
    for(int i=0,x;i<n;i++)scanf("%d",&x),a.push_back(make_pair(x,i));
    while(!a.empty())
    {
        sort(a.begin(),a.end()),
        reverse(a.begin(),a.end());
        pair<int,int> x=a[0];a.erase(a.begin());
        if(x.first<m||v[x.second]==3){S+=x.first;continue;}
        v[x.second]++,x.first-=m;
        a.push_back(x);
    }
    printf("%d\n",S);
    return 0;
}