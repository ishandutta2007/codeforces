#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long n1,n2,n3;
    long long n,k;
    cin>>n>>k;
    n1 = n*2;
    n2 = n*5;
    n3=n*8;
    long long ret = (n1/k)+(n1%k>0)+(n2/k)+(n2%k>0)+(n3/k)+(n3%k>0);
    cout<<ret<<endl;
}