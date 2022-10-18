#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define ss second
#define ff first
const int N = 2e5 + 11;
string a[N];
int main()
{
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    string s=a[1];
    int ans=INT_MAX;
    for (int ii=1; ii<=s.size(); ii++)
    {
        char ch=s[0];
        for (int j=0; j<s.size()-1; j++)
            s[j]=s[j+1];
        s[s.size()-1]=ch;
        int res=0;
        for (int i=1; i<=n; i++)
        {
            string t=a[i];
            int kol=0;
            while (t!=s)
            {
                kol++;
                if (kol>s.size()) break;
                char ch=t[0];
                for (int j=0; j<t.size()-1; j++)
                t[j]=t[j+1];
                t[t.size()-1]=ch;
            }
            if (kol>s.size()) {res=INT_MAX; break;} else res+=kol;
        }
        if (res<ans) ans=res;
    }
    if (ans==INT_MAX) cout<<-1<<endl; else cout<<ans<<endl;
}