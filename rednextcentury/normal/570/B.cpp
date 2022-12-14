 #include <bits/stdc++.h>
using namespace std;
int a[101][101];
int c[1001];
int main()
{
    int n,m;
    cin>>n>>m;
    if (n==1)
        cout<<1<<endl;
    else if (n-m > m - 1)
        cout<<m+1<<endl;
    else
        cout<<m-1<<endl;
}