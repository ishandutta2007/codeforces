#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define ss second
#define ff first
const int N = 2e5 + 11;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    cin>>s;
    int k1=0,k2=0;
    for (int i=0; i<s.size(); i++)
        {
            if (s[i]=='(') k1++; else
        if (s[i]==')') k1--; else k2++;
        if (k1-k2<0) {cout<<-1<<endl; return 0;}
        }
    string t="";
    int kk=k2;
    int ps=k1-k2;
    for (int i=0; i<s.size(); i++)
    if (s[i]=='#')
    {
        t+=")";
        kk--;
        if (kk==0)
        {
            for (int j=1; j<=ps; j++)
                t+=")";
        }
    } else t+=s[i];
    k1=0;
    for (int i=0; i<t.size(); i++)
        {
            if (t[i]=='(') k1++; else k1--;
            if (k1<0) {cout<<-1<<endl; return 0;}
        }
    if (k1!=0) {cout<<-1<<endl; return 0;}
    for (int i=1; i<k2; i++)
        cout<<1<<"\n";
    cout<<1+ps<<endl;
}