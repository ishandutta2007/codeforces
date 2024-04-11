#include<set>
#include<cstdio>
#include<algorithm>

using namespace std;

multiset<int>a;
multiset<int>::iterator it,ita,itb,itc;
int A,B,C,x,now,ans,bcsize,absize,acsize;

int main()
{
    int n;
    scanf("%d",&n);
    scanf("%d%d%d",&A,&B,&C);
    if(A>B)swap(A,B);
    if(A>C)swap(A,C);
    if(B>C)swap(B,C);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&x);
        if(x-C>A+B)return puts("-1"),0;
        if(B+C<x)ans++;
        if(A+C<x&&B+C>=x)bcsize++;
        if(A+B<x&&C<x&&A+C>=x)acsize++;
        if(C<x&&A+B>=x)absize++;
        if(x<=C)a.insert(x);
    }
    while(bcsize)
    {
        it=a.upper_bound(A);
        if(it!=a.begin())
        {
            it--;
            a.erase(it);
        }
        bcsize--;
        ans++;
    }
    while(acsize)
    {
        it=a.upper_bound(B);
        if(it!=a.begin())
        {
            it--;
            a.erase(it);
        }
        acsize--;
        ans++;
    }
    while(absize)
    {
        it=a.upper_bound(C);
        if(it!=a.begin())
        {
            it--;
            a.erase(it);
        }
        absize--;
        ans++;
    }
    //printf("%d\n",ans);
    //printf("%d\n",a.size());
    //for(it=a.begin();it!=a.end();it++)printf("%d\n",*it);
    while(a.size())
    {
        it=a.upper_bound(C);
        if(it!=a.begin())
        {
            it--;
            a.erase(it);
        }
        it=a.upper_bound(B);
        if(it!=a.begin())
        {
            it--;
            a.erase(it);
        }
        else
        {
            it=a.upper_bound(A+B);
            if(it!=a.begin())
            {
                it--;
                a.erase(it);
            }
        }
        it=a.upper_bound(A);
        if(it!=a.begin())
        {
            it--;
            a.erase(it);
        }
        ans++;
    }
    printf("%d\n",ans+a.size());
}