#include<bits/stdc++.h>
using namespace std;
#define ll long long
int ret[30];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--) {
        memset(ret,0,sizeof(ret));
        string s;
        cin>>s;
        int num=1;
        for (int i=1;i<s.size();i++) {
            if (s[i]==s[i-1])num++;
            else {
                if (num%2) {
                    ret[s[i-1]-'a']++;
                }
                num=1;
            }
        }
        if (num%2)ret[s.back()-'a']++;
        for (int i=0;i<26;i++)if (ret[i])cout<<char('a'+i);
        cout<<endl;
    }
}