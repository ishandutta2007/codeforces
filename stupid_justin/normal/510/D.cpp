#include<bits/stdc++.h>
using namespace std;
int a[400],c[400];
map <int,int> Map;
map <int,int>::iterator iter;
int gcd(int a,int b)
{
    return b==0 ? a : gcd(b,a%b);
}
int main()
{
    int i,n,m,k;
    Map.clear();
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];
    for(i=0;i<n;i++)
        cin>>c[i];
    for(i=0;i<n;i++)
    {
        k=Map[a[i]];
        if(k)
            Map[a[i]]=min(k,c[i]);
        else
            Map[a[i]]=c[i];
        for(iter=Map.begin();iter!=Map.end();iter++)
        {
            m=gcd(a[i],iter->first);
            k=Map[m];
            if(k)
                Map[m]=min(k,iter->second+c[i]);
            else
                Map[m]=iter->second+c[i];
        }
    }
    k=Map[1];
    if(k)
        cout<<k<<endl;
    else
        cout<<"-1"<<endl;
    return 0;
}