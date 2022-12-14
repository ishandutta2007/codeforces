#include<bits/stdc++.h>
using namespace std;
#define ll long long
int pre[1000000];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    int sum=0;
    pre[0]=0;
    int ret=1e9;
    s='.'+s;
    for (int i=1;i<s.size();i++) {
        if (s[i]=='0')sum++;
        pre[i]=sum;
    }
    int l=1,r=n;
    while(l<=r){
        int mid=(l+r)/2;
        bool ok=0;
        for (int i=1;i<s.size();i++) {
            if (s[i]!='0')continue;
            int L = i - mid - 1;
            L=max(L,0);
            int R = i + mid;
            R=min(R,(int)s.size()-1);
            if (pre[R]-pre[L]>=k+1)ok=1;
        }
        if (ok)ret=mid,r=mid-1;
        else l=mid+1;
    }
    cout<<ret<<endl;
}