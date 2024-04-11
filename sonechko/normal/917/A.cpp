#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define mp make_pair
#define ff first
#define ss second

const ll N = 5000 + 11;
const ll mod = 1e9 + 7;

bool u[N][N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    cin>>s;
    int ans=0;
    for (int i=0; i<s.size(); i++)
    {
        int kol1=0,kol2=0,kol3=0;
        for (int j=i; j<s.size(); j++)
        {
           if (s[j]=='(') kol1++; else
           if (s[j]==')') kol2++; else kol3++;
           if (kol1+kol3<kol2) break;
           int d=j-i+1;
           if (d%2==0&&kol1<=d/2&&kol2<=d/2)
        {
            u[i][j]=1;
        }
        }
    }
    reverse(s.begin(),s.end());
    for (int i=0; i<s.size(); i++)
    {
        if (s[i]=='(') s[i]=')'; else
        if (s[i]==')') s[i]='(';
    }
    for (int i=0; i<s.size(); i++)
    {
        int kol1=0,kol2=0,kol3=0;
        for (int j=i; j<s.size(); j++)
        {
           if (s[j]=='(') kol1++; else
           if (s[j]==')') kol2++; else kol3++;
           int d=j-i+1;
           //cout<<i<<" "<<j<<" "<<" "<<kol1<<" "<<kol2<<" "<<kol3<<endl;
           if (kol1+kol3<kol2) break;
           if (d%2==0&&kol1<=d/2&&kol2<=d/2)
           {
               if (u[s.size()-j-1][s.size()-i-1]) ans++;
               //cout<<s.size()-j-1<<" "<<s.size()-i-1<<endl;
           }
        }
    }
    cout<<ans<<endl;
}