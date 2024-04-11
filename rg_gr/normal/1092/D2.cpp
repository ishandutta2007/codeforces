#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stack>
#include <unordered_map>
#include <map>
#include <algorithm>
#define int long long
inline int read()
{
    int num=0,f=1;char c=getchar();
    while(c<48||c>57){if(c=='-')f=-1;c=getchar();}
    while(c>47&&c<58)num=(num<<3)+(num<<1)+(c^48),c=getchar();
    return num*f;
}
inline int max(int a,int b)
{
    return a>b?a:b;
}
std::stack<int> s;
int a[200005];
signed main()
{
    int n=read(),maxn=0,q=0;
    for(int i=0;i<n;i++)a[i]=read(),maxn=max(maxn,a[i]);
    for(int i=0;i<n;i++)
    {
        int x=a[i];
        //maxn=max(maxn,x);
        if(s.empty()){s.push(x);continue;}
        if(x==s.top())s.pop();
        else if(x>s.top())
        {
            //if(maxn!=x)
            {
                puts("NO");return 0;
            }
            //else s.push(x);
        }
        else s.push(x);
    }
    if(s.empty()||(q==0&&s.size()==1&&s.top()==maxn))puts("YES");
    else puts("NO");
}