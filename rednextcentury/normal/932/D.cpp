#include<bits/stdc++.h>
using namespace std;
long long nxt[500000][20];
long long sum[500000][20];
long long   w[500000];
long long  mx = 1000000000000001LL;
int main()
{
    ios_base::sync_with_stdio(0);
    int q;
    cin>>q;
    long long last=0;
    memset(nxt,-1,sizeof(nxt));
    long long cnt=2;
    while(q--)
    {
        long long t,p,q;
        cin>>t>>p>>q;
        if (t==1)
        {
            long long R=p^last;
            long long W=q^last;
            long long V=cnt++;
            w[V]=W;

            if (w[V]>w[R])
            {
                for (int i=19;i>=0;i--)
                {
                    if (nxt[R][i]!=-1)
                    {
                        int U=nxt[R][i];
                        if (w[U]<w[V])
                            R=U;
                    }
                }
                R=nxt[R][0];
            }
            if (R==-1){
                nxt[V][0]=-1;
                continue;
            }
            nxt[V][0]=R;
            sum[V][0]=w[R];
            for (int i=1;i<=19;i++)
            {
                if (nxt[V][i-1]==-1)
                    break;
                nxt[V][i]=nxt[nxt[V][i-1]][i-1];
                sum[V][i]=sum[V][i-1]+sum[nxt[V][i-1]][i-1];
                if (sum[V][i]>mx)
                    sum[V][i]=mx;
            }
        }
        else
        {
            long long R=p^last;
            long long X=q^last;
            long long ret=0;
            if (X<w[R])
            {
                last=0;
                cout<<0<<endl;
                continue;
            }
            X-=w[R];
            ret=1;
            for (int i=19;i>=0;i--)
            {
                if (nxt[R][i]!=-1)
                {
                    if (sum[R][i]<=X)
                    {
                        ret+=(1<<i);
                        X-=sum[R][i];
                        R=nxt[R][i];
                    }
                }
            }
            last=ret;
            cout<<ret<<endl;
        }
    }
}