#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int N = 5e5 + 11;
const int MOD = 1e9 + 7;



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    cin>>s;
    int ans=0;
    int x1=-1,x2=-1;
    for (int j=0; j<s.size(); j++)
    {
        int t=(s[j]-'0')%3;
        if (t==0) {ans++; x1=-1; x2=-1;} else
        if (t==1&&x1==1&&x2==1) {ans++; x1=-1; x2=-1;} else
        if (t==1&&x2==2) {ans++; x1=-1; x2=-1;} else
        if (t==2&&x1==2&&x2==2) {ans++; x1=-1; x2=-1;} else
        if (t==2&&x2==1) {ans++; x1=-1; x2=-1;} else
        {
            x1=x2;
            x2=t;
        }
    }
    cout<<ans<<endl;
}
/**
0
12
21
111
222
**/