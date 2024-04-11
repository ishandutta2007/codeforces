#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ss second
#define ff first
#define mp make_pair
#define pb push_back


const int N = 1e5 + 11;

int uses[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=26; i++)
        uses[i]=1;
    int kol=-1,ks=0;
    for (int i=1; i<=n; i++)
    {
        char ch;
        cin>>ch;
        if (ch=='.')
        {
            string s;
            cin>>s;
            for (int j=0; j<s.size(); j++)
                uses[s[j]-'a'+1]=0;
        } else
        if (ch=='!')
        {
            string s;
            cin>>s;
            ks++;
            int use[200];
            for (int p=1; p<=26; p++)
                use[p]=0;
            for (int p=0; p<s.size(); p++)
                use[s[p]-'a'+1]=1;
            for (int p=1; p<=26; p++)
                if (use[p]==0) uses[p]=0;
        } else
        {
            char ch;
            cin>>ch;
            uses[ch-'a'+1]=0;
            ks++;
        }
        if (kol==-1)
            {
                int pp=0;
                int kk=0;
                for (int j=1; j<=26; j++)
                if (uses[j]==1) {pp=j; kk++;}
                if (kk==1) {kol=ks;}
            }
    }ks--;
    if (kol==-1) cout<<0<<endl;
    else cout<<ks-kol<<endl;
}

/**
5
! abc
. ad
. b
! cd
? c
**/