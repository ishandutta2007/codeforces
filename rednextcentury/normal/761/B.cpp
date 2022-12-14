#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int is1[10000],is2[100000],a[100000],b[100000],is[100000];
int main()
{
    fast
    int n,L;
    cin>>n>>L;
    for (int i=0;i<n;i++)
        cin>>a[i],is1[a[i]]=1;
    for (int i=0;i<n;i++)
        cin>>b[i],is2[b[i]]=1;
    bool sol=0;
    for (int i=0;i<L;i++)
    {
        int cur=i;
        int num=0;
        for (int j=0;j<L;j++)is[j]=0;
        while(1)
        {
          if (num==L)break;
            if (is1[num])is[cur]=1;
            cur++;
            if (cur==L)cur=0;
            num++;
        }
        for (int j=0;j<L;j++)
        {
            bool no=0;
            int c=j;
            int nn=0;
            while(1)
            {
              if (nn==L)break;
                if (is2[nn])
                {
                    if (!is[c])no=1;
                }
                c++;
                if (c==L)c=0;
                nn++;
            }
            if (!no)sol=1;
        }
        if (sol)break;
    }
    if (sol)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}