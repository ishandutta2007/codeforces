#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<math.h>
#include<string.h>
#include<vector>
#include<set>
using namespace std;
typedef __int64 ll;
const int inf=1000000000;
int map[1002][1002];
int row[1002],col[1002];
int main()
{
    int m,n,cnt=0;cin>>m>>n;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            char c;cin>>c;
            if(c=='*'){
                map[i][j]=1;
                row[i]++;
                col[j]++;
                cnt++;
            }
        }
    }
    for(int i=1;i<=m;i++){ for(int j=1;j<=n;j++){
        if((row[i]+col[j]-(map[i][j]==1))==cnt){cout<<"YES\n"<<i<<" "<<j;return 0;}
    }}
    cout<<"NO";
    return 0;
}