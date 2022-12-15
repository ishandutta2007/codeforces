#include<iostream>
#include<map>

using namespace std;

int col[100001];
map<int,bool> mp[100001];
int res[100001];

int main ()
{
    int n,m,i,result=0,num,a,b;

    ios::sync_with_stdio(false);

    cin>>n>>m;

    for(i=1;i<=n;i++)
    {
        cin>>a;
        col[i]=a;
    }

    for(i=0;i<m;i++)
    {
        cin>>a>>b;

        if(col[a]==col[b])continue;

        if(mp[col[a]][col[b]]==0)
        {
            mp[col[a]][col[b]]=1;
            res[col[a]]++;
        }
        if(mp[col[b]][col[a]]==0)
        {
            mp[col[b]][col[a]]=1;
            res[col[b]]++;
        }
    }

    for(i=1;i<100001;i++)
    {
        if(res[i]>result)
        {
            result=res[i];
            num=i;
        }
    }

    if(result==0)
    {
        num=col[1];
        for(i=2;i<=n;i++)
        {
            if(col[i]<num)num=col[i];
        }
    }

    //cout<<result<<endl;
    cout<<num<<endl;

    return 0;
}