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
void g(string s)




{
    sort(s.begin(),s.end());
    for (int i=1; i<s.size(); i++)
    if (s[i]==s[i-1]) {cout<<"NO"<<endl; exit(0);}
}
int nex[N],use[N],pre[N];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        string s;
        cin>>s;
        g(s);
        for (int j=1; j<s.size(); j++)
        {
            int p1=s[j-1]-'a'+1,p2=s[j]-'a'+1;
            if (nex[p1]!=0&&nex[p1]!=p2) {cout<<"NO"<<endl; exit(0);}
            if (pre[p2]!=0&&pre[p2]!=p1) {cout<<"NO"<<endl; exit(0);}
            nex[p1]=p2;
            pre[p2]=p1;
        }
        for (int j=0; j<s.size(); j++)
            use[s[j]-'a'+1]=1;
    }
    int kol=0;
    for (int i=1; i<=26; i++)
        if (use[i]==1) kol++;
    string ans="";
    int ks=-1;
    for (int i=1; i<=kol; i++)
    {
        int p=0;
        if (ks==-1)
        {
        for (int j=1; j<=26; j++)
            if (use[j]==1&&pre[j]==0) {p=j; break;}
        if (p==0) {cout<<"NO"<<endl; return 0;}
        } else p=ks;
        use[p]=0;
        ans+=char(p+'a'-1);
        pre[nex[p]]=0;
        if (nex[p]==0) ks=-1; else ks=nex[p];
    }
    cout<<ans<<endl;
}