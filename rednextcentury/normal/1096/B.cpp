#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    string s;
    cin>>s;
    if (s[0]!=s[s.size()-1]) {
        long long l=0,r=0;
        for (int i=0;i<s.size();i++){
            if (s[i]==s[0])l++;else break;
        }
        for (int i=s.size()-1;i>=0;i--)
        {
            if (s[i]==s[s.size()-1])r++;
            else break;
        }
        cout<<((l)+(r)+1)%998244353<<endl;
    } else {
        long long l=0,r=0;
        for (int i=0;i<s.size();i++){
            if (s[i]==s[0])l++;else break;
        }
        for (int i=s.size()-1;i>=0;i--)
        {
            if (s[i]==s[s.size()-1])r++;
            else break;
        }
        cout<<((l+1)*(r+1))%998244353<<endl;
    }
}