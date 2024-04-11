#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define ss second

const int N = 100 + 11;

map<int,bool> mt;
vector<int> vv;

int find_(int l, int r)
{
    cout<<"0 "<<l<<" "<<r<<endl;
    //return min(min(abs(l-2),abs(r)),abs(r+3));
    int p;
    cin>>p;
    return p;
}

void dfs(int l, int r)
{
    int mid=(l+r)/2;
    int c=find_(mid,mid);
    //cout<<l<<".."<<r<<endl;
    if (mid-c>=-100000000&&mt[mid-c]==0&&find_(mid-c,mid-c)==0)
    {
        mt[mid-c]=1;
        vv.pb(mid-c);
    }
    if (l<=mid-c-1) dfs(l,mid-c-1);
    if (mid+c<=100000000&&mt[mid+c]==0&&find_(mid+c,mid+c)==0)
    {
        mt[mid+c]=1;
        vv.pb(mid+c);
    }
    if (mid+c+1<=r) dfs(mid+c+1,r);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    dfs(-1e8,1e8);
    sort(vv.begin(),vv.end());
    vector<int> v1,v2;
    for (int i=0; i<vv.size(); i++)
    {
        if (find_(vv[i],228228)==0) v1.pb(vv[i]);
        if (find_(228228,vv[i])==0) v2.pb(vv[i]);
    }
    cout<<1<<" "<<v1.size()<<" "<<v2.size()<<endl;
    for (int i=0; i<v1.size(); i++)
        cout<<v1[i]<<" ";
    cout<<endl;
    for (int i=0; i<v2.size(); i++)
        cout<<v2[i]<<" ";
    cout<<endl;
}