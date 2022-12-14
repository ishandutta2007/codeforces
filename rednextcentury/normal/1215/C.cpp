#include<bits/stdc++.h>
using namespace std;
vector<int> AB,BA;
char inp[2000000];
int main()
{
    //ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    scanf("%d",&n);
    string a,b;
    scanf("%s",inp);a=inp;
    scanf("%s",inp);b=inp;
    for (int i=0;i<n;i++)
    {
        if (a[i]=='a' && b[i]=='b')AB.push_back(i);
        if (a[i]=='b' && b[i]=='a')BA.push_back(i);
    }
    vector<pair<int,int> > ret;
    while(AB.size()>=2)
    {
        int l = AB.back();AB.pop_back();
        int r = AB.back();AB.pop_back();
        ret.push_back({l,r});
    }
    while(BA.size()>=2)
    {
        int l = BA.back();BA.pop_back();
        int r = BA.back();BA.pop_back();
        ret.push_back({l,r});
    }
    if (AB.size()==1 && BA.size()==1)
    {
        int l = AB[0];
        int r = BA[0];
        ret.push_back({l,l});
        ret.push_back({l,r});
    }
    if (AB.size()!=BA.size())
    {
        puts("-1");
        return 0;
    }
    printf("%d\n",(int)ret.size());
    for (auto p:ret)
        printf("%d %d\n",p.first+1,p.second+1);
}