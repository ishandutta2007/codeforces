#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define ss second
#define ff first
#define endl "\n"
#define ld long double
#define ll long long
#define pb push_back
const int MOD = 1e9 + 7;

const int N = 1e5 + 11;

bool use[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    char mini='z';
    for (int i=0; i<s.size(); i++)
    {
        use[s[i]-'a']=1;
        mini=min(mini,s[i]);
    }
    if (k>s.size())
    {
        cout<<s;
        for (int d=1; d<=k-(int)s.size(); d++)
            cout<<mini;
        return 0;
    }
    for (int i=k-1; i>=0; i--)
    {
        for (int j=s[i]-'a'+1; j<=26; j++)
            if (use[j]==1)
        {
            for (int j=0; j<i; j++)
                cout<<s[j];
            cout<<char(j+'a');
            int kol=k-i-1;
            for (int j=1; j<=kol; j++)
                cout<<mini;
            cout<<endl;
            return 0;
        }
    }
}