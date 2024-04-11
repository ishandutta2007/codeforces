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

using namespace std;

typedef pair<int,int> PII;
typedef pair<pair<int,int>,int> PIII;

int f[1000005],a,x,y;

int main()
{
    cin>>a>>x>>y;
    f[1]=1;
    for (int i=2;i<=1000000;i++) f[i]=i%2+1;
    if (y%a==0) cout<<-1<<endl; else
    {
        int s=0;
        for (int i=1;i<=y/a;i++) s+=f[i];
        if (f[y/a+1]==2)
        {
            if ((x>0)&&(x<a)) cout<<s+2<<endl; else
            if ((x<0)&&(x>-a)) cout<<s+1<<endl; else cout<<-1<<endl;
        }
        else
        {
            if ((x>-double(a)/2)&&(x<double(a)/2)) cout<<s+1<<endl; else cout<<-1<<endl;
        }
    }
    return 0;
}