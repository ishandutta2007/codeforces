#include<bits/stdc++.h>
using namespace std;


#define ll long long
#define ull unsigned long long
#define mp make_pair
#define ss second
#define ff first
const int MOD = 1000000007;
#define mod %MOD
#define pb push_back
#define ld long double
const int N = 1e6 + 11;
const int MAX = 1e8;



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    cin>>s;
    int kol=0,p=0;
    for (int i=0; i<s.size(); i++)
    {
        if (s[i]=='1') p=1;
        if (p==1&&s[i]=='0') kol++;
    }
    if (kol>=6) cout<<"yes"<<endl;
    else cout<<"no"<<endl;
}