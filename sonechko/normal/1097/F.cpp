#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

const int N = 1e5 + 11;

bitset<7002> b[N],v1,v2,e1[7002],e2[7002];
bool p[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,q;
    cin>>n>>q;
    for (int i=1; i<=7000; i++)
    {
        int c=0;
        int d=2;
        int nn=i;
        while (d*d<=nn)
        {
            if (nn%(d*d)==0) c=-1;
            if (nn%d==0) nn/=d;
            d++;
        }
        if (c==0) p[i]=1;
        for (int c=1; c<=(int)sqrt(i); c++)
            if (i%c==0)
        {
            e1[i][c]=1;
            if (c!=i/c) e1[i][i/c]=1;
        }
    }
    for (int i=1; i<=7000; i++)
    {
        for (int j=i; j<=7000; j+=i)
            if (p[j/i]) e2[i][j]=1;
    }
    for (int i=1; i<=q; i++)
    {
        int t;
        cin>>t;
        if (t==1)
        {
            int l,r;
            cin>>l>>r;
            b[l]=e1[r];
        } else
        if (t==2)
        {
            int l,r,k;
            cin>>l>>r>>k;
            b[l]=(b[r]^b[k]);
        } else
        if (t==3)
        {
            int l,r,k;
            cin>>l>>r>>k;
            b[l]=(b[r]&b[k]);
        } else
        if (t==4)
        {
            int l,r;
            cin>>l>>r;
            int c=((b[l]&e2[r]).count())%2;
            ///cout<<"? "<<l<<" "<<r<<endl;
            cout<<c;
        }

        /**
        cout<<endl;
        cout<<i<<"!! "<<endl;
        for (int i=1; i<=n; i++)
        {
            for (int p=1; p<=6; p++)
                cout<<b[i][p];
            cout<<endl;
        }
        cout<<endl;
        **/

    }
}
/**

1 7
4 6


k[1]-k[2]-k[3]-k[5]+k[6]-k[7]

**/