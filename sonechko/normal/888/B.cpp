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
    int n;
    cin>>n;
    string s;
    cin>>s;
    int kol1=0,kol2=0,kol3=0,kol4=0;
    for (int i=0; i<s.size(); i++)
    {
        if (s[i]=='L') kol1++;
        if (s[i]=='R') kol2++;
        if (s[i]=='U') kol3++;
        if (s[i]=='D') kol4++;
    }
    cout<<min(kol1,kol2)*2+min(kol3,kol4)*2<<endl;
}