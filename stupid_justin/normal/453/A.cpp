#include<bits/stdc++.h>
using namespace std;
double n,m,ans;
int main()
{
    cin>>m>>n;
    for(double i=1;i<=m;i++) ans+=i*(pow(i/m,n)-pow((i-1)/m,n));
    printf("%.12lf\n",ans);
}