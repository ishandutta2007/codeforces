#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mid ((l+r)/2)
#define L (x<<1)
#define R (L+1)
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n,r;
        cin>>n>>r;
        vector<long long> x(n);
        for (int i=0;i<n;i++) {
            cin>>x[i];
        }
        sort(x.begin(),x.end());
        int sz = unique(x.begin(),x.end())-x.begin();
        int ret=0;
        long long S=0;
        for (int i=sz-1;i>=0;i--) {
            x[i]-=S;
            if (x[i]<=0)break;
            ret++;
            S+=r;
        }
        cout<<ret<<endl;
    }


    //system("pause");
}