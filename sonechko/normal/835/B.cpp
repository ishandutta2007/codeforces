#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ss second
#define ff first
#define mp make_pair
#define pb push_back
#define ld long double
const int N = 1e6 + 11;


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int k;
    string s;
    cin>>k>>s;
    int sum=0;
    sort(s.begin(),s.end());
    for (int i=0; i<s.size(); i++)
    {
        sum+=s[i]-'0';
    }
    if (sum<k)
    {
        for (int i=0; i<s.size(); i++)
        {
            sum-=s[i]-'0';
            sum+=9;
            if (sum>=k) {cout<<i+1<<endl; return 0;}
        }
    } else cout<<0<<endl;
}