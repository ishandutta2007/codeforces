#pr\
agma GCC optimize(2)
#include <cstdio>
#include <algorithm>
using namespace std;

#define gcc getchar
template <typename T> inline void read(T&x)
{
    x=0; bool f=true; char ck=gcc();
    for( ; ck<'0'||ck>'9'; ck=gcc()) if(ck == '-') f=false;
    for( ; ck>='0'&&ck<='9'; ck=gcc()) x=(x<<1)+(x<<3)+(ck^48);
    x=f?x:-x; return ;
}

#define N 200003
int n, a[N], res;

int main(void)
{
    read(n);
    for(int i=1; i<=n; ++i) read(a[i]);
    sort(a+1, a+n+1);
    int j=1; 
    for(int i=1; i<=n; ++i)
        while(j <= n && a[j] <= a[i]+5)
        {
            res=max(res, j-i+1);
            ++j;
        }
    printf("%d", res);
    return 0;
}