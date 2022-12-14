#include<bits/stdc++.h>
using namespace std;
map<int,int> mp;
int a[1000000];
int main()
{
    int n,k;
    cin>>n>>k;
    set<int> s;
    for (int i=0;i<k;i++)
    {
        int x;
        cin>>x;
        a[i]=x;
        if (mp[x]==1)s.erase(s.find(x));
        mp[x]++;
        if (mp[x]==1)s.insert(x);;
    }
    for (int i=k;i<n;i++)
    {
        int x;
        cin>>x;
        a[i]=x;
        if (s.empty())printf("Nothing\n");
        else printf("%d\n",*(--s.end()));
        if (mp[x]==1)s.erase(s.find(x));
        mp[x]++;
        if (mp[x]==1)s.insert(x);
        if (mp[a[i-k]]==1)s.erase(s.find(a[i-k]));
        mp[a[i-k]]--;
        if (mp[a[i-k]]==1)s.insert(a[i-k]);
    }
    if (s.empty())printf("Nothing\n");
    else printf("%d\n",*(--s.end()));
}