#include<bits/stdc++.h>
using namespace std;
vector<int> v[100009];
pair<int,int> b[100009];
int a[100009];
int f[100009];
main()
{
    int n;
    cin>>n;
    for (int i=0; i<n; i++)
        {cin>>a[i];
        b[i].first=a[i];
        b[i].second=i+1;}
    sort(b,b+n);
    int x=0;
        for(int i=0; i<n; i++)//{
            a[b[i].second]=i+1;
            //out<<b[i].second<<" "<<i+1<<endl;}
        for (int i=1; i<=n; i++)
        {
           // cout<<i<<" "<<f[i]<<endl;
            if (f[i]) continue;
           // cout<<i<<endl;
        //cout<<a[i]<<endl;
        v[x].push_back(i);
        int c=i;
        int z=i;
        //cout<<x<<" "<<i<<endl;
        while(a[z]!=i)
        {
            v[x].push_back(a[z]);
            //cout<<x<<"  "<<a[i]<<endl;
            f[a[z]]=1;
            //cout<<f[2]<<endl;
            z=a[z];

        }
        x++;
        }
        cout<<x<<endl;
        for (int i=0; i<x; i++){
                cout<<v[i].size()<<" ";
            for (int j=0; j<v[i].size(); j++)
            cout<<v[i][j]<<" ";
        cout<<endl;}

}