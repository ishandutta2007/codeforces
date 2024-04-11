#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int N = 9e5 + 11;
const int MOD = 1e9 + 7;

int gl(char ch)
{
    if (ch=='o'||ch=='a'||ch=='u'||ch=='i'||ch=='e') return 0;
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    cin>>s;
    for (int j=0; j<s.size()-1; j++)
    {
        int t1=gl(s[j]),t2=gl(s[j+1]);
        if (t1==1&&t2==1&&s[j]!='n') {cout<<"NO"<<endl; return 0;}
    }
    int t=gl(s[s.size()-1]);
    if (t==1&&s[s.size()-1]!='n') cout<<"NO"<<endl; else
    cout<<"YES"<<endl;
}