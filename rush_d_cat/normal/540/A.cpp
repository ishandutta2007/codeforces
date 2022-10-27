#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef __int64 ll;
const int INF=100000000;
char a[1002],b[1002];
int main()
{
    int n;cin>>n;cin>>a>>b;
    int res=0;
    for(int i=0;i<n;i++){
        int x = a[i]-'0';
        int y = b[i]-'0';
        int m1 = max(x,y);
        int m2 = min(x,y);
        res += min(m1-m2,m2+10-m1);
    }
    cout<<res<<endl;
    return 0;
}