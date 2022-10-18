#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define mp make_pair
#define ss second
#define ff first
#define ll long long
#define pb push_back
const int MOD = 1e9 + 7;
#define mod %MOD


const int N = 1000 + 11;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    cin>>s;
    int b0=s[0]-'0';
    int b1=s[1]-'0';
    int b2=s[2]-'0';
    int b3=s[3]-'0';
    int b4=s[4]-'0';
    int b5=s[5]-'0';
    int ans=6;
    for (int a0=0; a0<=9; a0++)
    for (int a1=0; a1<=9; a1++)
    for (int a2=0; a2<=9; a2++)
    for (int a3=0; a3<=9; a3++)
    for (int a4=0; a4<=9; a4++)
    for (int a5=0; a5<=9; a5++)
        if (a0+a1+a2==a3+a4+a5)
    {
        ans=min(ans,(b0!=a0)+(b1!=a1)+(b2!=a2)+(b3!=a3)+(b4!=a4)+(b5!=a5));
    }
    cout<<ans<<endl;
}