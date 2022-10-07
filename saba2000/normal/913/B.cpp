#include<bits/stdc++.h>
using namespace std;
int f[200009];
vector<int> v[200009];
main()
{
    int n;
    cin >>n;
    for (int i= 2 ; i<=n; i++)
    {
        int p;
        cin >> p;
        v[p].push_back(i);
    }
    for (int i=1; i<=n; i++)
    {
        if( v[i].size()==0) f[i]=1;
    }
    for (int i=1; i<=n; i++)
    {
        int k=0;
        if(f[i]) continue;
        for (int j=0; j<v[i].size(); j++)
            k+=f[v[i][j]];
        if(k<3) {cout<<"No"<<endl; return 0;}
    }
    cout<<"Yes"<<endl;
}