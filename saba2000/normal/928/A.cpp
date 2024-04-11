#include<bits/stdc++.h>
using namespace std;
string t(string s)
{
    for (int i=0; i<s.size(); i++)
    {
        if(s[i] == '1') s[i]='l';
        if(s[i] == '0') s[i]='o';
        if(s[i] >= 'a' && s[i]<= 'z') s[i]=s[i]-'a'+'A';
        if(s[i] == 'I') s[i] ='L';
    }
    return s;
}
main()
{
    string s;
    cin >> s;
    s=t(s);
    int n;
    cin >> n;
    for (int i=0; i<n; i++)
    {
        string K; cin >>K;
        K=t(K);
        if(K==s) {cout<<"No"<<endl; return 0;}
    }
    cout<<"Yes"<<endl;
}