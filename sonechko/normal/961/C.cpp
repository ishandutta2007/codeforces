#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define ll long long
const int MOD = 1e9 + 7;
#define mod %MOD

const int N = 200 + 11;

int if0[N],if1[N];
int up(int l1, int r1, int l2, int r2)
{
    return if0[l1]+if0[r1]+if1[l2]+if1[r2];
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
    for (int j=1; j<=n; j++)
    {
        char p;
        cin>>p;
        if ((i+j)%2==0&&p=='1') if0[1]++;
        if ((i+j)%2==1&&p=='0') if0[1]++;
        if ((i+j)%2==0&&p=='0') if1[1]++;
        if ((i+j)%2==1&&p=='1') if1[1]++;
    }
    for (int i=1; i<=n; i++)
    for (int j=1; j<=n; j++)
    {
        char p;
        cin>>p;
        if ((i+j)%2==0&&p=='1') if0[2]++;
        if ((i+j)%2==1&&p=='0') if0[2]++;
        if ((i+j)%2==0&&p=='0') if1[2]++;
        if ((i+j)%2==1&&p=='1') if1[2]++;
    }
    for (int i=1; i<=n; i++)
    for (int j=1; j<=n; j++)
    {
        char p;
        cin>>p;
        if ((i+j)%2==0&&p=='1') if0[3]++;
        if ((i+j)%2==1&&p=='0') if0[3]++;
        if ((i+j)%2==0&&p=='0') if1[3]++;
        if ((i+j)%2==1&&p=='1') if1[3]++;
    }
    for (int i=1; i<=n; i++)
    for (int j=1; j<=n; j++)
    {
        char p;
        cin>>p;
        if ((i+j)%2==0&&p=='1') if0[4]++;
        if ((i+j)%2==1&&p=='0') if0[4]++;
        if ((i+j)%2==0&&p=='0') if1[4]++;
        if ((i+j)%2==1&&p=='1') if1[4]++;
    }
    int res=n*n*5;
    res=min(res,up(1,2,3,4));
    res=min(res,up(1,3,2,4));
    res=min(res,up(1,4,2,3));
    res=min(res,up(2,3,1,4));
    res=min(res,up(2,4,1,3));
    res=min(res,up(3,4,1,2));
    cout<<res<<endl;
}