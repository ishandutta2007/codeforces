#include<bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define ll long long

const int N = 3e6 + 11;

bool use[N];
int mindel[N];
int num[N];
int a[N];
int mt[N],mtt[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    use[1]=1;
    int kol=0;
    for (int j=2; j<=2800000; j++)
        if (use[j]==0)
    {
        kol++;
        num[j]=kol;
        if (j*1ll*j>2800000) continue;
        for (int p=j*j; p<=2800000; p+=j)
            if (use[p]==0)
        {
            use[p]=1;
            mindel[p]=j;
        }
    }
    for (int i=1; i<=n*2; i++)
        cin>>a[i];
    sort(a+1,a+n*2+1);
    for (int i=n*2; i>=1; i--)
    if (mt[a[i]]>0) {mt[a[i]]--; cout<<a[i]<<" ";} else
    if (mtt[a[i]]>0) {mtt[a[i]]--;} else
    if (use[a[i]]==0) mt[num[a[i]]]++; else
    {
        int t=mindel[a[i]];
        int dd=a[i]/t;
        cout<<a[i]<<" ";
        mtt[dd]++;
    }
    cout<<endl;

}
/**
**/