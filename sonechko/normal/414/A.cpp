#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
const int N = 1e5;


int main()
{
    int n,m;
    cin>>n>>m;
    if (m<n/2) {cout<<-1<<endl; return 0;}
    if (n==1&&m!=0) {cout<<-1<<endl; return 0;}
    if (n==1) {cout<<1<<endl; return 0;}
    cout<<m-n/2+1<<" "<<(m-n/2+1)*2<<" ";
    int k=(m-n/2+1)*2;
    for (int i=1; i<=n-2; i++)
        cout<<k+i<<" ";
    cout<<endl;
}