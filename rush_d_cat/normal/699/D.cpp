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
int used[200000],pre[200000],root=0,res=0;
int main()
{
    int n;cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>pre[i];
        if(pre[i]==i&&!root)
        {
            used[i]=i;
            root=i;
        }
    }

    for(int i=1;i<=n;i++)
    {
        if(used[i]) continue;
        for(int j=i;j!=root&&!used[j];j=pre[j])
        {
            used[j]=i;
            if(used[pre[j]]==i)
            {
                if(!root)
                {
                    root=j;
                }
                res++;
                pre[j]=root;
                break;
            }
        }
    }

    cout<<res<<endl;
    for(int i=1;i<=n;i++)
    {
        cout<<pre[i];
        if(i!=n)  cout<<" ";
    }
    return 0;
}