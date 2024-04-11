#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 11;
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
#define ld long double
#define sqr(a) ((a)*(a))
string s[N];
int main()
{
    sync;
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>s[i];
    for (int j=n-1; j>=1; j--)
    {
        string s1=s[j+1],s2=s[j];
        int k=s2.size()-1;
        for (int i=0; i<=k; i++)
            if (s1.size()==i) {k=i-1; break;} else
            if (s2[i]<s1[i]) break; else
            if (s1[i]<s2[i]) {k=i-1; break;}
        s[j]="";
        for (int i=0; i<=k; i++)
            s[j]+=s2[i];
    }
    for (int i=1; i<=n; i++)
        cout<<s[i]<<endl;
}