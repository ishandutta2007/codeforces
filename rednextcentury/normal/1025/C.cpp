#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string s;
    cin>>s;
    int cur = 1;
    char x = s[0];
    int ret=1;
    for (int i=1;i<s.size();i++){
        if (s[i]!=x)cur++,x=s[i];
        else {
            ret=max(ret,cur);
            cur=1;
            x=s[i];
        }
    }
    if (cur>ret)ret=cur;
    if (s[0]!=s[s.size()-1]){
        int l=0;
        while(l+1<s.size() && s[l]!=s[l+1])l++;
        cur=l+1;
        reverse(s.begin(),s.end());
        l=0;
        while(l+1<s.size() && s[l]!=s[l+1])l++;
        cur+=l+1;
        cur=min(cur,(int)s.size());
        ret=max(ret,cur);
    }
    cout<<ret<<endl;
}