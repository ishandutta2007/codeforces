#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
#include <set>
#include <cmath>
#include <queue>
#include <utility>
using namespace std;
typedef pair<int,int> pii;
const int NICO = 100005;
const int MAKI = 100005;
const int INF = 100007;
int l[NICO], r[NICO], L = 0, R = 0;
int main()
{
    int n,i,j;cin>>n;
    for(i=1;i<=n;i++)
    {
        scanf("%d %d", &l[i], &r[i]);
        L += l[i];
        R += r[i];
    }
    int res = abs(R-L);
    int tmp = 0;
    for(i=1;i<=n;i++)
    {
        if(abs( R+l[i]-r[i] - (L+r[i]-l[i]) ) > res)
        {
            res = abs( R+l[i]-r[i] - (L+r[i]-l[i]) );
            tmp = i;
        }
    }
    cout << tmp << endl;
}