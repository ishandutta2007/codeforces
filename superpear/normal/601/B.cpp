#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> PII;
typedef pair<int,PII> PIII;

#define LL long long
#define ULL unsigned long long
#define w1 first
#define w2 second
#define p_b push_back
#define l_b lower_bound
#define m_p make_pair

const int maxlongint=2147483647;
const int biglongint=2139062143;

const int maxn=100005;
int st[100005][20],sg[100005][20];
int N,M,l,r,a[100005],b[100005],pow2[100005];

int getmax(int l,int r)
{
    int lc=pow2[r-l+1];
    if (st[l][lc]>st[r-(1<<lc)+1][lc]) return sg[l][lc]; else
    return sg[r-(1<<lc)+1][lc];
}

LL getans(int l,int r)
{
    if (l>r) return 0;
    if (l==r) return b[l];
    int cc=getmax(l,r);
    //cout<<l<<" "<<r<<" "<<cc<<endl;
    return getans(l,cc-1)+getans(cc+1,r)+(LL)b[cc]*(cc-l+1)*(r-cc+1);
}

int main()
{
    scanf("%d %d",&N,&M);
    for (int i=1;i<=N;i++)
    {
        scanf("%d",&a[i]);
        b[i-1]=abs(a[i]-a[i-1]);
    }
    pow2[1]=0;
    for (int i=2;i<maxn;i++) pow2[i]=pow2[i/2]+1;

    for (int i=N;i>=1;i--)
    {
        st[i][0]=b[i];
        sg[i][0]=i;
        for (int j=1;j<=17;j++)
            if (i+(1<<j)-1<=N)
            {
                if (st[i][j-1]>st[i+(1<<(j-1))][j-1])
                    st[i][j]=st[i][j-1],
                    sg[i][j]=sg[i][j-1];
                else
                    st[i][j]=st[i+(1<<(j-1))][j-1],
                    sg[i][j]=sg[i+(1<<(j-1))][j-1];
            }
    }
    for (int i=1;i<=M;i++)
    {
        scanf("%d %d",&l,&r);
        if (l==r) cout<<0<<endl; else
        {
            --r;
            cout<<getans(l,r)<<endl;
        }
    }
    return 0;
}