#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
const long long MOD = 1e9 + 7;
#define mod %MOD
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ss second
#define ff first
#define ll long long
#define mp make_pair
#define endl "\n"
#define pb push_back
#define y1 ijdj
#define next lzk
#define tab difjke
vector<string> v[N];
int de[N];
int get(string s)
{
    int ans=0;
    for (int i=0; i<s.size(); i++)
    {
        ans=ans*10+(s[i]-'0');
    }
    return ans;
}
int main()
{
    sync;
    string s;
    getline(cin,s);
    int p=0,ans=0;
    string f="";
    int k=0;
    s+=",";
    for (int i=0; i<s.size(); i++)
        if (s[i]==',')
    {
        if (s[i-1]>='0'&&s[i-1]<='9')
        {
            p++;
            v[p].pb(f);
            ans=max(ans,p);
            de[p-1]--;
            de[p]=k;
            while (de[p]==0)
            {
                p--;
                if (p==0) break;
            }
            f="";
            k=0;
        }
    } else
    if (s[i]>='0'&&s[i]<='9') k=k*10+(s[i]-'0'); else f+=s[i];
    cout<<ans<<endl;
    for (int i=1; i<=ans; i++)
    {
        for (int j=0; j<v[i].size(); j++)
            cout<<v[i][j]<<" ";
        cout<<endl;
    }
}