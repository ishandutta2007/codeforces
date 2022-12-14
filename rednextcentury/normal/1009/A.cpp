#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long
#define F first
#define S second
#define PB push_back
#define MP make_pair
using namespace std ;
int a[10000];
int b[10000];
int main ()
{
    int n,m;
    cin>>n>>m;
    for (int i=0;i<n;i++)
        cin>>a[i];
    for (int i=0;i<m;i++)
        cin>>b[i];
    int i=0,j=0;
    int ret=0;
    while(i<n && j<m)
    {
        if (a[i]>b[j])
        {
            i++;
        }
        else
        {
            ret++;
            i++;
            j++;
        }
    }
    cout<<ret<<endl;
}