#include <bits/stdc++.h>
using namespace std;
int n;
vector<bitset<501> > operator*(vector<bitset<501> > &A,vector<bitset<501> > &B)
{
    vector<bitset<501> > flip = B , ret = A;
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
            flip[i][j]=B[j][i];
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
            ret[i][j]=(A[i]&flip[j]).any();
    return ret;
}
vector<bitset<501> > P[62];
vector<bitset<501> > B[62];
int main()
{
    int m;
    scanf("%d%d",&n,&m);
    P[0].resize(n);
    B[0].resize(n);
    for (int i=0;i<m;i++)
    {
        int u,v,x;
        scanf("%d%d%d",&u,&v,&x);
        u--,v--;
        if (x==0)
            P[0][u][v]=1;
        else
            B[0][u][v]=1;
    }
    for (int i=1;i<=60;i++)
    {
        P[i]=P[i-1]*B[i-1];
        B[i]=B[i-1]*P[i-1];
    }
    vector<int> cur;
    cur.push_back(0);
    long long ret=0;
    int num=0;
    for (int i=60;i>=0;i--)
    {
        vector<int> newCur;
        for (int x=0;x<n;x++)
        {
            for (int j=0;j<cur.size();j++)
            {
                if ((num==0 && P[i][cur[j]][x]) || (num==1 && B[i][cur[j]][x]))
                {
                    newCur.push_back(x);
                    break;
                }
            }
        }
        if (newCur.size())
        {

            num=1-num;
            cur=newCur;
            ret+=((1LL)<<i);
            if (ret>1000000000000000000LL)
            {
                cout<<-1<<endl;
                return 0;
            }
        }
    }
    cout<<ret<<endl;
}