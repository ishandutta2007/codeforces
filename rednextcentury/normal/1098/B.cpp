#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
string S = "ACGT";
string a[1000000];
string b[1000000];
string c[1000000];
bool vis[1001][1001];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i=0;i<n;i++)
        cin>>a[i],b[i]=a[i];

    int ret=n*m+1;
    S="ACGT";
    do
    {
        if (vis[S[0]][S[1]] || vis[S[1]][S[0]])continue;
        vis[S[0]][S[1]]=1;
        int cur=0;
        for (int i=0;i<m;i++)
        {
            int cur1=0;
            for (int j=0;j<n;j++)
            {
                if (i%2==0)
                {
                    if (j%2==0)b[j][i]=S[0];
                    else b[j][i]=S[1];
                }
                else
                {
                    if (j%2==0)b[j][i]=S[2];
                    else b[j][i]=S[3];
                }
                cur1+=(b[j][i]!=a[j][i]);
            }

            int cur2=0;
            for (int j=0;j<n;j++)
            {
                if (i%2==0)
                {
                    if (j%2==0)b[j][i]=S[1];
                    else b[j][i]=S[0];
                }
                else
                {
                    if (j%2==0)b[j][i]=S[3];
                    else b[j][i]=S[2];
                }
                cur2+=(b[j][i]!=a[j][i]);
            }
            if (cur1<cur2)
            {
                for (int j=0;j<n;j++)
                {
                    if (i%2==0)
                    {
                        if (j%2==0)b[j][i]=S[0];
                        else b[j][i]=S[1];
                    }
                    else
                    {
                        if (j%2==0)b[j][i]=S[2];
                        else b[j][i]=S[3];
                    }
                }
            }
            cur+=min(cur1,cur2);
        }
        int best=cur;
        if (best<ret)
        {
            ret=best;
            for (int i=0;i<n;i++)
                c[i]=b[i];
        }
        cur=0;
        for (int i=0;i<n;i++)
        {
            int cur1=0;
            for (int j=0;j<m;j++)
            {
                if (i%2==0)
                {
                    if (j%2==0)b[i][j]=S[0];
                    else b[i][j]=S[1];
                }
                else
                {
                    if (j%2==0)b[i][j]=S[2];
                    else b[i][j]=S[3];
                }
                cur1+=(b[i][j]!=a[i][j]);
            }
            int cur2=0;
            for (int j=0;j<m;j++)
            {
                if (i%2==0)
                {
                    if (j%2==0)b[i][j]=S[1];
                    else b[i][j]=S[0];
                }
                else
                {
                    if (j%2==0)b[i][j]=S[3];
                    else b[i][j]=S[2];
                }
                cur2+=(b[i][j]!=a[i][j]);
            }
            if (cur1<cur2)
            {
                for (int j=0;j<m;j++)
                {
                    if (i%2==0)
                    {
                        if (j%2==0)b[i][j]=S[0];
                        else b[i][j]=S[1];
                    }
                    else
                    {
                        if (j%2==0)b[i][j]=S[2];
                        else b[i][j]=S[3];
                    }
                }
            }
            cur+=min(cur1,cur2);
        }
        if (cur<ret)
        {
            ret= cur;
            for (int i=0;i<n;i++)
                c[i]=b[i];
        }
    }while(next_permutation(S.begin(),S.end()));
    for (int i=0;i<n;i++)
        cout<<c[i]<<endl;
    return 0;


}