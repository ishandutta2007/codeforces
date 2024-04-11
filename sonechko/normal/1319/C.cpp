#include<bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define ll long long

const int N = 2e5 + 11;



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    string s;
    cin>>s;
    int ans=0;
    for (int p=25; p>=0; p--)
    {
        while (1)
        {
            int t=-1;
            for (int i=0; i<s.size(); i++)
                if (s[i]-'a'==p&&((i>0&&s[i-1]==s[i]-1)||(i<s.size()-1&&s[i+1]==s[i]-1)))
            {
                t=i; break;
            }
            if (t==-1) break;
            ans++;
            string p="";
            for (int i=0; i<s.size(); i++)
                if (i!=t) p+=s[i];
            s=p;
        }
    }
    cout<<ans;
}