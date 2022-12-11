#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <set>
//#include <>
#include <map>

#define ll long long int
#define FOR(a, b) for (int a = 0; a < b; a++)
#define clr(a) memset(a, 0, sizeof(a))

using namespace std;
const int inf = 1000000000;
const double eps = 0.000000001;

int a[300][300];

int main()
{
    int n,m;
    cin>>n>>m;
    int k=((n*m)/2)+((n*m)%2);
    for (int i=1;i<=n;i++)
        for (int j=((i+1)%2)+1;j<=m;j+=2) a[i][j]=k--;
    k=n*m;
    for (int i=1;i<=n;i++)
        for (int j=(i%2)+1;j<=m;j+=2) a[i][j]=k--;
    k=((n*m)/2)+((n*m)%2)+1;
    if ((a[2][1]==k)||(a[1][2]==k)) {
        cout<<-1;
        return 0;
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++) cout<<a[i][j]<<' ';
        cout<<'\n';
    }
    return 0;
}