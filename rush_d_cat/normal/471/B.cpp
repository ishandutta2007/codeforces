#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef __int64 ll;
const ll mod = 1000000007;
ll cnt[2010],a[2010];
struct task{
    int d,num;
}t[2010];
bool cmp(task a,task b)
{
    if(a.d==b.d) return a.num<b.num;
    return a.d<b.d;
}
int main()
{
    int n;cin>>n;
    ll res=1;
    for(int i=1;i<=2000;i++)
    {
        cnt[i]=0;
    }
    for(int i=1;i<=n;i++)
    {
        cin>>t[i].d;
        t[i].num=i;
        cnt[t[i].d]++;
    }
    for(int i=1;i<=2000;i++)
    {
        if(cnt[i]!=0)
        {
            res*=cnt[i];
            if(res>3) break;
        }
    }

    if(res<3) cout<<"NO"<<endl;
    else{
        cout<<"YES"<<endl;
        sort(t+1,t+1+n,cmp);
        for(int i=1;i<=n;i++){
            cout<<t[i].num;
            if(i==n) cout<<endl;
            else cout<<" ";
        }
        int flag=0;
        for(int i=1;i<=n;i++)
        {
            if(t[i].d!=t[i+1].d||(t[i].d==t[i+1].d&&flag!=0)) cout<<t[i].num;
            else{
                flag=i;
                cout<<t[i+1].num;
                int tmp = t[i+1].num;
                t[i+1].num=t[i].num;
                t[i].num=tmp;
            }
            if(i==n) cout<<endl;
            else cout<<" ";
        }
        int flag1=0;
        for(int i=1;i<=n;i++)
        {
            if(i==flag) cout<<t[i].num;
            else if(t[i].d!=t[i+1].d||(t[i].d==t[i+1].d&&flag1!=0)) cout<<t[i].num;
            else{
                flag1=i;
                cout<<t[i+1].num;
                int tmp = t[i+1].num;
                t[i+1].num=t[i].num;
                t[i].num=tmp;
            }
            if(i==n) cout<<endl;
            else cout<<" ";
        }
    }
    return 0;
}