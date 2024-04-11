#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6 + 11;
const int MOD = 1e9 + 7;

int k1[N],k2[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        string s;
        cin>>s;
        int k=0,t=0;
        for (int j=0; j<s.size(); j++)
        {
            if (s[j]=='(') k++; else k--;
            t=min(t,k);
        }
        if (k>=0&&t==0) k1[k]++;
        if (k<0&&t==k) k2[-k]++;
    }
    int ans=0;
    for (int i=1; i<=500000; i++)
        ans+=min(k1[i],k2[i]);
    ans+=k1[0]/2;
    cout<<ans<<endl;
}
/**
4 6 5 1 3 2


**/