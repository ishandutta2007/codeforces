#include<bits/stdc++.h>
using namespace std;
#define ll long long

int prefixFunc(string s) {
    int m = (int)s.size();

    vector<int> ret = vector<int>(m);
    for (int i=1, k=0; i<m; i++) {
        while (k > 0 && s[k] != s[i])
            k = ret[k-1];

        if (s[k] == s[i])
            ret[i] = ++k;
        else
            ret[i] = k;
    }

    return ret.back();

}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string s,t;
    cin>>s>>t;
    string ret="";
    int zero=0,one=0;
    for (auto x:s){
        if (x=='0')zero++;
        else one++;
    }
    int len = prefixFunc(t);
    int suf = t.size() - len;
    for (int i=0;i<len;i++){
        if (t[i]=='1' && one)one--,ret+="1";
        else if (t[i]=='0' && zero)zero--,ret+="0";
        else break;
    }
    while(1){
        bool can=1;
        for (int i=len;i<t.size();i++){
            if (t[i]=='1' && one)one--,ret+="1";
            else if (t[i]=='0' && zero)zero--,ret+="0";
            else {
                can=0;
                break;
            }
        }
        if (!can)break;
    }
    while(one--)ret+='1';
    while(zero--)ret+='0';
    cout<<ret<<endl;
}