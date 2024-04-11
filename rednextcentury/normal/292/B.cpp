#include<iostream>
# include <algorithm>
#include <vector>
using namespace std;
int adj[100000];
int main()
{
    int n,m;
    cin>>n>>m;
    for (int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        adj[a-1]++,adj[b-1]++;
    }
    sort(adj,adj+n);
    bool star=1,bus=1,ring=1;
    if (adj[0]!=1 || adj[1]!=1 || adj[2]!=2 || adj[n-1]!=2)
        bus=0;
    if (adj[n-1]!=n-1 || adj[n-2]!=1 || adj[0]!=1)
        star=0;
    if (adj[0]!=2 || adj[n-1]!=2)
        ring=0;
    if (ring)
        cout<<"ring topology\n";
   else if (star)
        cout<<"star topology\n";
    else if (bus)
        cout<<"bus topology\n";
        else
            cout<<"unknown topology\n";
}