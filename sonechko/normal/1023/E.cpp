#include<bits/stdc++.h>
using namespace std;

#define y1 ojf
#define ld long double
#define ull unsigned long long
#define ll long long
#define ff first
#define ss second
#define pb push_back
#define mp make_pair


const int N = 1e5 + 11;

bool get(int l1, int r1, int l2, int r2)
{
    cout<<"? "<<l1<<" "<<r1<<" "<<l2<<" "<<r2<<endl;
    string s;
    cin>>s;
    if (s=="YES") return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    int l=1,r=1;
    string ans="";
    for (int i=1; i<=n-1; i++)
    if (get(l,r+1,n,n)) {r++; ans+="R";} else
    {l++; ans+="D";}
    string res="";
    l=n;
    r=n;
    for (int i=1; i<=n-1; i++)
    if (get(1,1,l-1,r)) {l--; res+="D";} else
    {r--; res+="R";}
    reverse(res.begin(),res.end());
    cout<<"! "<<ans<<res<<endl;
}