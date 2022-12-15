#include<iostream>
#include<vector>

using namespace std;

vector<int> v[100001];

int main ()
{
    int n,m,i,x,y,maxi=0,mini=100;

    cin>>n>>m;

    for(i=0;i<m;i++)
    {
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
        maxi=max(maxi,max((int)v[x].size(),(int)v[y].size()));
    }
    for(i=1;i<=n;i++)
        mini=min(mini,(int)v[i].size());

    if(m==n-1)
    {
        if(maxi==n-1 && mini==1)
        {
            cout<<"star topology\n";
            return 0;
        }
        if(maxi<=2 && mini==1)
        {
            cout<<"bus topology"<<endl;
            return 0;
        }
        cout<<"unknown topology"<<endl;
        return 0;
    }
    if(m==n)
    {
        if(maxi==2 && mini==2)
        {
            cout<<"ring topology"<<endl;
            return 0;
        }
    }

    cout<<"unknown topology"<<endl;

    return 0;
}