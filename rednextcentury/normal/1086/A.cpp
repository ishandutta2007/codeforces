#include<bits/stdc++.h>
using namespace std;
int dist(int x1,int y1,int x2,int y2)
{
    return abs(x1-x2)+abs(y1-y2);
}
void printPath(int x1,int y1,int x2,int y2)
{
    vector<pair<int,int> > vec;
    while(x1<x2)
    {
        vec.push_back({x1,y1});
        x1++;
    }
    vec.push_back({x1,y1});
    while(y1<y2)
    {
        vec.push_back({x1,y1});
        y1++;
    }
    vec.push_back({x1,y1});
    while(x1>x2)
    {
        vec.push_back({x1,y1});
        x1--;
    }
    vec.push_back({x1,y1});
    while(y1>y2)
    {
        vec.push_back({x1,y1});
        y1--;
    }
    vec.push_back({x1,y1});
    int n = unique(vec.begin(),vec.end()) - vec.begin();
    for (int i=0;i<n;i++)
    {
        if (vec[i].first!=x2 || vec[i].second!=y2)
        {
            cout<<vec[i].first<<' '<<vec[i].second<<endl;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int X[3],Y[3],a[3]={1,2,3};
    cin>>X[0]>>Y[0];
    cin>>X[1]>>Y[1];
    cin>>X[2]>>Y[2];
    int ret=1e7;
    do
    {
        ret=min(ret,dist(X[a[0]-1],Y[a[0]-1],X[a[1]-1],Y[a[1]-1])+dist(X[a[1]-1],Y[a[1]-1],X[a[2]-1],Y[a[2]-1]));
    }while(next_permutation(a,a+3));
    for (int i=0;i<=1000;i++)
        for (int j=0;j<=1000;j++)
            ret=min(ret,dist(X[0],Y[0],i,j)+dist(X[1],Y[1],i,j)+dist(X[2],Y[2],i,j));

    a[0]=1,a[1]=2,a[2]=3;
    cout<<ret+1<<endl;
    do
    {
        if (dist(X[a[0]-1],Y[a[0]-1],X[a[1]-1],Y[a[1]-1])+dist(X[a[1]-1],Y[a[1]-1],X[a[2]-1],Y[a[2]-1])==ret)
        {
            printPath(X[a[0]-1],Y[a[0]-1],X[a[1]-1],Y[a[1]-1]);
            printPath(X[a[1]-1],Y[a[1]-1],X[a[2]-1],Y[a[2]-1]);
            cout<<X[a[2]-1]<<' '<<Y[a[2]-1]<<endl;
            return 0;
        }
    }while(next_permutation(a,a+3));
    for (int i=0;i<=1000;i++)
        for (int j=0;j<=1000;j++)
            if (dist(X[0],Y[0],i,j)+dist(X[1],Y[1],i,j)+dist(X[2],Y[2],i,j)==ret)
            {
                printPath(X[0],Y[0],i,j);
                printPath(X[1],Y[1],i,j);
                printPath(X[2],Y[2],i,j);
                cout<<i<<' '<<j<<endl;
                return 0;
            }
}