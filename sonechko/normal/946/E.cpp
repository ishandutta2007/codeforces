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
const int N = 2e5 + 11;

int k[N][10];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    for (int ii=1; ii<=t; ii++)
    {
        string s;
        cin>>s;
        s="."+s;
        for (int d=1; d<s.size(); d++)
        {
            for (int p=0; p<=9; p++)
                k[d][p]=k[d-1][p];
            k[d][s[d]-'0']++;
        }
        string res="";
        for (int i=s.size()-1; i>0; i--)
        {
            if (res!="") break;
            int c=0;
            if (i==1) c=1;
            k[i][s[i]-'0']--;
            for (int j=s[i]-'0'-1; j>=c; j--)
            {
                k[i][j]++;
                int kol=0;
                for (int p=0; p<10; p++)
                    kol+=k[i][p]%2;
                if (kol<=s.size()-i-1)
                {
                    for (int p=1; p<i; p++)
                        res+=s[p];
                    res+=char(j+'0');
                    int g=s.size()-1-i-kol;
                    for (int d=1; d<=g; d++)
                        res+="9";
                    for (int p=9; p>=0; p--)
                        if (k[i][p]%2==1) res+=char(p+'0');
                    break;
                }
                k[i][j]--;
            }
        }
        if (res=="")
        {
            for (int d=1; d<=s.size()-3; d++)
                res+="9";
        }
        cout<<res<<"\n";
    }
}