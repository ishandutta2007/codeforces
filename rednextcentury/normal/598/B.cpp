#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long
#define F first
#define S second
#define PB push_back
#define MP make_pair
using namespace std ;
string s;
void Shift(int l,int r,int k)
{
    string ret = s;
    for (int i=0;i<=(r-l);i++)
    {
        int pos = l+i;
        int newPos = (i+k)%(r-l+1)+l;
        ret[newPos]=s[pos];
    }
    s=ret;
}
int main ()
{
    cin>>s;
    int m;
    cin>>m;
    for (int i=0;i<m;i++)
    {
        int l,r,k;
        cin>>l>>r>>k;
        l--,r--;
        k=k%(r-l+1);
        Shift(l,r,k);
    }
    cout<<s<<endl;
}