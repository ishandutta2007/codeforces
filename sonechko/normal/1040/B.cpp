#include<bits/stdc++.h>
using namespace std;

#define pb push_back

const int N = 1e5 + 11;


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,k;
    cin>>n>>k;
    int ans=(n+2*k)/(2*k+1);
    cout<<ans<<endl;
    for (int pos=1; pos<=k+1; pos++)
    {
        int kk=1;
        int last=pos+k;
        vector<int> vv;
        vv.pb(pos);
        while (last<n)
        {
            int c=last+k+1;
            if (c>n) {kk=-1; break;}
            kk++;
            vv.pb(c);
            last=c+k;
        }
        if (kk==ans)
        {
            for (int j=0; j<vv.size(); j++)
                cout<<vv[j]<<" ";
            cout<<endl;
            return 0;
        }
    }
}