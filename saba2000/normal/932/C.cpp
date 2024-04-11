#include<bits/stdc++.h>
using namespace std;
int g[1000009];
int f[1000009][10];
main()
{int n,a,b;
cin >> n >> a >> b;
int J = -1;
for (int i = 0; i*a <= n; i++)
{
    if((n-a*i)%b==0) J=i;
}
if(J==-1) {cout<<-1<<endl; return 0;}
int K = (n-a*J)/b;
for (int i = 0; i < J; i++)
{
    for (int  k = a*i+2; k <=a*i+a; k++)
        cout<<k<<" ";
    cout<<a*i+1<<" ";
}
for (int i = 0; i < K; i++)
{
    for (int  k =a*J+ b*i+2; k <=a*J+b*i+b; k++)
        cout<<k<<" ";
    cout<<a*J+ b*i+1<<" ";
}
}