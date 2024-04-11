#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        string s;
        int x;
        cin>>x>>s;
        vector<int> vec;
        vec.push_back(0);
        int j=0;
        ll len=s.size();
        ll mod = 1000000007;
        for (int l=0;l<x;l++) {
            ll oldLen = len;
            int old = s.size();
            int j = l;
            for (int i=1;i<s[j]-'0';i++) {
                for (int p=j+1;p<old;p++){
                    if (s.size()>x)break;
                    s.push_back(s[p]);
                }
                len+=(oldLen-j-1 + mod)%mod;
                len%=mod;
            }
        }
        printf("%lld\n",len);
    }
}