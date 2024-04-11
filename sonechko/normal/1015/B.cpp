#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6 + 11;
const int MOD = 1e9 + 7;



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    string s;
    cin>>s;
    string t;
    cin>>t;
    s="."+s;
    t="."+t;
    vector<int> ans;
    for (int j=1; j<=n; j++)
    {
        int pos=-1;
        for (int i=j; i<=n; i++)
            if (s[i]==t[j]) {pos=i; break;}
        if (pos==-1) {cout<<-1; return 0;}
        while (pos!=j)
        {
            pos--;
            ans.pb(pos);
            swap(s[pos],s[pos+1]);
        }
    }
    cout<<ans.size()<<endl;
    for (int j=0; j<ans.size(); j++)
        cout<<ans[j]<<" ";
    cout<<endl;
}