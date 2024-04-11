#include<iostream>
#include<map>

using namespace std;

#define MAXN 100001
#define MAXI 1000000000

map<string,int>Map;
string s[MAXN];
int group[MAXN],a[MAXN];
int mini[MAXN];

int main ()
{
    int n,k,m,i,x,j,y;
    string s2;

    cin>>n>>k>>m;

    for(i=0;i<n;i++)
    {
        cin>>s[i];
        Map[s[i]]=i;
    }

    for(i=0;i<n;i++)
        cin>>a[i];

    for(i=0;i<k;i++)
    {
        cin>>x;

        mini[i]=MAXI;

        for(j=0;j<x;j++)
        {
            cin>>y;

            group[y-1]=i;
            mini[i]=min(a[y-1],mini[i]);
        }
    }

    long long res=0;

    for(i=0;i<m;i++)
    {
        cin>>s2;
       //cout<<Map[s2]<<endl;
        //cout<<group[Map[s2]]<<endl;
        //cout<<mini[group[Map[s2]]]<<endl;
        res+=(long long)mini[group[Map[s2]]];
    }

    cout<<res<<endl;

    return 0;
}