#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define ld long double
#define mp make_pair
#define ff first
#define ss second
const ll N = 1e6 + 11;
int k;
void rec(int sz, int l, int r, string s)
{
    if (sz==l)
    {
        if (r!=10) return;
        k--;
        if (k==0) {cout<<s<<endl; exit(0);}
        return;
    }
    int dd=0;
    if (l==0) dd=1;
    for (int i=dd; i<=9; i++)
        if (r+i<=10) rec(sz,l+1,r+i,s+char((i+'0')));
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>k;
    for (int p=2; p<=10000; p++)
        rec(p,0,0,"");
}