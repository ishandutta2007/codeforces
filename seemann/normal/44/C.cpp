#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

int x[1000];

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int n,m,a,b;
    cin>>n>>m;
    for (int i=1;i<=n;i++) x[i]=0;
    for (int i=1;i<=m;i++) {
        cin>>a>>b;
        for (int j=a;j<=b;j++) x[j]++;
    }
    for (int i=1;i<=n;i++)
        if (x[i]!=1) {
            cout<<i<<' '<<x[i];
            return 0;
        }
    cout<<"OK";
    return 0;
}