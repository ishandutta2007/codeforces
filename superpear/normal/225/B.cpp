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

int s,k,o,e,ans[1000];
int main()
{
    LL a[1000];
    cin>>s>>k;
    a[1]=1;
    for (int i=2;i<1000;i++)
    {
        a[i]=0;
        for (int j=i-1;j>=max(i-k,1);j--) a[i]+=(LL)a[j];
        if (a[i]>s) {e=i-1;break;}
    }
    o=0;
    while (s>0)
    {
        while (s<a[e]) --e;
        s-=a[e];
        ++o;ans[o]=a[e];
        --e;
    }
    ++o;ans[o]=0;
    cout<<o<<endl;
    for (int i=1;i<=o;i++) cout<<ans[i]<<" ";
    cout<<endl;

    return 0;
}