#include <bits/stdc++.h>
using namespace std;
#define ll long long
int num[100];
string Try(string s,int id) {
    if (id==s.size())return s;
    string cur = s.substr(0,id);
    int cnt[10]={0};
    for (int i=0;i<10;i++)cnt[i]=num[i];
    for (int i=s[id]-'0'-1;i>=0;i--) {
        if (cnt[i]>0) {
            cnt[i]--;
            cur+=char(i+'0');
            break;
        }
    }
    if (cur.size()==id)return "0";
    for (int i=id+1;i<s.size();i++) {
        for (int j=9;j>=0;j--) {
            if (cnt[j]) {
                cnt[j]--;
                cur+=char(j+'0');
                break;
            }
        }
    }
    return cur;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string a,b;
    cin>>a>>b;
    if (a.size()<b.size()) {
        sort(a.begin(),a.end());
        reverse(a.begin(),a.end());
        cout<<a<<endl;
        return 0;
    }
    for (auto x:a)num[x-'0']++;
    string ret="0";
    ret=max(ret,Try(b,0));
    for (int i=0;i<b.size();i++)
    {
        if (num[b[i]-'0']) {
            num[b[i]-'0']--;
        } else {
            break;
        }
        ret=max(ret,Try(b,i+1));
    }
    cout<<ret<<endl;
}