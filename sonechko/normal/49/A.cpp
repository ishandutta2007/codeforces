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
    string ss;
    getline(cin,ss);
    for (int i=ss.size()-1; i>=0; i--)
        if (ss[i]=='A'||ss[i]=='O'||ss[i]=='I'||ss[i]=='U'||ss[i]=='Y'||ss[i]=='E'||
            ss[i]=='a'||ss[i]=='o'||ss[i]=='i'||ss[i]=='u'||ss[i]=='y'||ss[i]=='e')
    {
        cout<<"YES"<<endl;
        return 0;
    } else
    if (ss[i]>='a'&&ss[i]<='z')
    {
        cout<<"NO"<<endl;
        return 0;
    } else
    if (ss[i]>='A'&&ss[i]<='Z')
    {
        cout<<"NO"<<endl;
        return 0;
    }
}