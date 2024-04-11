#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <set>
#include <algorithm>
#include <map>
#include <bitset>
#include <vector>
#include <queue>
#include <stack>
#include <utility>
#include <functional>
#include <sstream>
#include <list>
#include <complex>

#define maxlongint 2147483647
#define biglongint 2139062143
#define LL long long
#define ULL unsigned long long
#define p_b push_back
#define m_p make_pair
#define l_b lower_bound

using namespace std;

typedef pair<int,int> PII;
typedef pair<pair<int,int>,int> PIII;

int n,top,top1,hash[100],a[1000],b[1000];
int main()
{
    scanf("%d",&n);
    scanf("%d",&top);
    for (int i=1;i<=n;i++)
        scanf("%d %d",&a[i],&b[i]);
    top1=7-top;
    for (int i=2;i<=n;i++)
    {
        memset(hash,0,sizeof(hash));
        hash[a[i]]=1;hash[b[i]]=1;
        hash[7-a[i]]=1;hash[7-b[i]]=1;
        if (hash[top1]==1)
        {
            cout<<"NO"<<endl;
            return 0;
        }
        hash[top1]=1;
        for (int j=1;j<=6;j++) if (hash[j]==0) top=j;
    }
    cout<<"YES"<<endl;
    return 0;
}