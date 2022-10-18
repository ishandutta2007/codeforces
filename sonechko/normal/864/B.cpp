#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ss second
#define ff first
#define mp make_pair
#define pb push_back

const int N = 1e6 + 11;
int use[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    string s;
    cin>>s;
    int ans=0;
    for (int ii=0; ii<s.size(); ii++)
    {
        for (int i=0; i<=26; i++)
            use[i]=0;
        int kol=0;
        int p=ii;
        for (int j=ii; j<s.size(); j++)
        if (s[j]>='A'&&s[j]<='Z') break; else
        if (use[s[j]-'a']==0) {use[s[j]-'a']=1; kol++;}
        ans=max(ans,kol);
    }
    cout<<ans<<endl;
}