#include <bits/stdc++.h>
using namespace std;
int x[1000000];
long long ret[1000000];
long long ll[1000000];
long long rr[1000000];
long long all=0;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i=0;i<m;i++) {
        cin>>x[i];
        if (i>=1) {
            int L = x[i];
            int R = x[i-1];
            if (L==R)continue;
            if (L>R)swap(L,R);
            long long norm = abs(R-L);
            ll[L-1]+=norm;
            rr[R+1]+=norm;
            if (L==1) {
                ret[L]+=R-1;
                ret[R]+=1;
            } else {
                ret[L]+=R-1;
                ret[R]+=L;
            }
            rr[L+1]+=norm-1;
            rr[R]-=norm-1;
        }
    }
    long long cur=0;
    long long num=0;
    for (int i=1;i<=n;i++) {
        rr[i]+=rr[i-1];
        ret[i]+=rr[i];
    }
    cur=0,num=0;
    for (int i=n;i>=1;i--) {
        ll[i]+=ll[i+1];
        ret[i]+=ll[i];
    }
    for (int i=1;i<=n;i++)
        cout<<ret[i]<<' ';
}