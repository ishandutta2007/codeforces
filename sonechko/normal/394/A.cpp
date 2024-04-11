#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 11;


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    cin>>s;
    int a=0,b=0,c=0,t=0;
    for (int j=0; j<s.size(); j++)
        if (s[j]=='|') a++; else {t=j; break;}
    t++;
    for (int j=t; j<s.size(); j++)
        if (s[j]=='|') b++; else {t=j; break;}
    t++;
    for (int j=t; j<s.size(); j++)
        c++;
    if (a+b==c) {} else
    if (a+1+b==c-1) {a++; c--;} else
    if (a>1&&a-1+b==c+1) {a--; c++;} else
    if (b>1&&b-1+a==c+1) {b--; c++;} else
        {
            cout<<"Impossible\n";
            return 0;
        }
    for (int j=0; j<a; j++)
        cout<<'|';
    cout<<'+';
    for (int j=0; j<b; j++)
        cout<<'|';
    cout<<'=';
    for (int j=0; j<c; j++)
        cout<<'|';

}