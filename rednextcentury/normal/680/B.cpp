#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define ll long long
#define F first
#define S second
#define PB push_back
#define MP make_pair
    int a[1000];
int main ()
{
    int n,k;
    cin>>n>>k;
    for (int i=0;i<5*n;i++)
        a[i]=1;
    for (int i=n;i<2*n;i++)
        cin>>a[i];
    k--;
    k+=n;
    int ret=0;
    if (a[k])ret++;
    int l=k-1,r=k+1;
    while(l>=n || r<2*n){
        if (a[l]&a[r])ret+=(r<2*n)+(l>=n);
        l--,r++;
    }
    cout<<ret<<endl;
}