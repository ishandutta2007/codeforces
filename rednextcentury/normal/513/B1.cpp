# include <iostream>
# include <algorithm>
# include <vector>
# include <cstring>
using namespace std;
int a[100000];
int b[100000];
string ret[1000000];
int tot;
int main()
{
    int n,m;
    cin>>n>>m;
    for (int i=0;i<n;i++)
    {
        a[i]=i+1;
    }
    do
    {
        int now=0;
        int mn;
        for (int i=0;i<n;i++)
        {
            mn=a[i];
            for (int x=i;x<n;x++)
            {
                mn=min(mn,a[x]);
                now+=mn;
            }
        }
        b[tot++]=now;
    }while(next_permutation(a,a+n));
    sort(b,b+tot);
    sort(a,a+n);
    int t=0;
    do
    {
        int now=0;
        int mn;
        for (int i=0;i<n;i++)
        {
            mn=a[i];
            for (int x=i;x<n;x++)
            {
                mn=min(mn,a[x]);
                now+=mn;
            }
        }
        if (now==b[tot-1])
        {
            string s="";
            for (int i=0;i<n;i++)
            {
                s+=char(a[i]+'0');
            }
            ret[t++]=s;
        }
    }while(next_permutation(a,a+n));
    sort(ret,ret+t);
    for (int i=0;i<n;i++)
    {
        cout<<ret[m-1][i]<<" ";
    }
    cout<<endl;
}