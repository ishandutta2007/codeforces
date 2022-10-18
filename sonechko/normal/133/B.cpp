#include<bits/stdc++.h>
using namespace std;
#define pb push_back

const int N = 1e5 + 11;
const int MOD = 1e6 + 3;
#define mod %MOD

int main()
{
    #ifndef LOCAL
    //freopen("cards.in", "r", stdin);
    //freopen("cards.out", "w", stdout);
    #endif // LOCAL
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    cin>>s;
    int d=1,g=0;
    for (int i=s.size()-1; i>=0; i--)
    {
        if (s[i]=='<'||s[i]=='-'||s[i]==','||s[i]==']')
            g=(g+d)mod;
        d=(d*2)mod;
        if (s[i]=='+'||s[i]=='-'||s[i]=='['||s[i]==']')
            g=(g+d)mod;
        d=(d*2)mod;
        if (s[i]==','||s[i]=='.'||s[i]=='['||s[i]==']')
            g=(g+d)mod;
        d=(d*2)mod;
        g=(g+d)mod;
        d=(d*2)mod;
    }
    cout<<g<<endl;
}