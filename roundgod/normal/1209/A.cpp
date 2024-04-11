#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
int n,a[MAXN];
vector<int> v;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        v.push_back(a[i]);
    }
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    int cnt=0;
    for(int i=0;i<(int)v.size();i++)
    {
        bool f=true;
        for(int j=0;j<i;j++)
        {
            if(v[i]%v[j]==0) f=false;
        }
        if(f) cnt++;
    }
    printf("%d\n",cnt);
}