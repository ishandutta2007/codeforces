#include<iostream>
#include<vector>

using namespace std;

vector<int> v[100001];

pair<int,bool> solve(int u,int p)
{
    int i,res=0,cnt=1;
    pair<int,bool> x;

    for(i=0;i<v[u].size();i++)
    {
        if(v[u][i]==p)
            continue;

        x=solve(v[u][i],u);

        if(x.second)
        {
            res+=x.first+1;
        }
        else
        {
            res+=x.first;
            cnt++;
        }
    }

    if(cnt%2==0)
        x.second=1;
    else
        x.second=0;
    x.first=res;

    return x;
}

int main ()
{
    int n,i,x,y;
    pair<int,bool> res;

    cin>>n;

    for(i=0;i<n-1;i++)
    {
        cin>>x>>y;

        v[x].push_back(y);
        v[y].push_back(x);
    }

    res=solve(1,-1);

    if(res.second==1)
        cout<<res.first<<endl;
    else
        cout<<"-1"<<endl;

    return 0;
}