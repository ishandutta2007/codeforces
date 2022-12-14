#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n,r,p,s;
        string S;
        cin>>n>>r>>p>>s>>S;
        string ret = S;
        for (int i=0;i<n;i++)ret[i]='-';
        int num = 0;
        int need = n/2+n%2;
        for (int i=0;i<n;i++) {
            if (S[i]=='R' && p>0) {
                ret[i]='P',p--;
                num++;
            } else if (S[i]=='P' && s>0) {
                ret[i]='S',s--;num++;
            } else if (S[i]=='S' && r>0){
                ret[i]='R',r--;num++;
            }
        }
        for (int i=0;i<n;i++) {
            if (ret[i]=='-') {
                if (r>0)ret[i]='R',r--;
                else if (p>0)ret[i]='P',p--;
                else ret[i]='S',s--;
            }
        }
        if (num>=need) {
            cout<<"YES\n"<<ret<<"\n";
        } else {
            cout<<"NO\n";
        }

    }
}