#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<math.h>
#include<string>
#include<string.h>
#include<math.h>
#include<queue>
//#include<unordered_map>
using namespace std;

#define li long long
#define db double
#define mp make_pair
#define all(a) a.begin(),a.end()
#define pii pair<int,int>
#define vi vector<int>
db INF =1000000007;
db e = 0.00000000001;
const int mod =31;

int timer=1;
void solve();

int main ()
{
#ifdef _DEBUG
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
#else
    //freopen("necklace.in","r",stdin);
    //freopen("necklace.out","w",stdout);
#endif
    int t=1;
//  cin>>t;
    for(int i=0;i<t;i++)
    {
    //  printf("Case #%d:",i+1);
        solve();
    //  printf("\n");
    }
    return 0;
}
#define int li
char a[200500],b[200500];
int aa[30][200005],bb[30][200005];
int asum[30],bsum[30];
void solve()
{
    int n;
    cin>>n;
    li sum=0;
    for(li i=1;i<=n;i++)
        sum+=(n-i+1)*(n-i+1);
    gets(a);
    gets(a);
    gets(b);
    for(int i=0;i<n;i++)
    {
        a[i]-='A';
        asum[a[i]]++;
        b[i]-='A';
        bsum[b[i]]++;
    }
    for(int i=n-1;i>=0;i--)
    {
        for(int q=0;q<30;q++)
            aa[q][i]=aa[q][i+1];
        aa[a[i]][i]+=n-i;
        for(int q=0;q<30;q++)
            bb[q][i]=bb[q][i+1];
        bb[b[i]][i]+=n-i;
    }
    db ans=0;
    for(int i=0;i<n;i++)
        ans+=(i+1)*(bb[a[i]][i+1]);
    for(int i=0;i<n;i++)
        ans+=(i+1)*(aa[b[i]][i+1]);
    for(int i=0;i<n;i++)
    {
        if(a[i]==b[i])
            ans+=(i+1)*(n-i);
    }
    printf("%.8lf",(db)ans/(db)sum);
}