#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define ld long double

const int N = 1e5 + 11;

void up()
{
    int n;
    cin>>n;
    int p1=0;
    string s;
    cin>>s;
    string t1="",t2="";
    for (int j=0; j<s.size(); j++)
    {
        if (s[j]=='0') {t1+="0"; t2+="0";} else
        if (s[j]=='1')
        {
            if (p1==0) {t1+="1"; t2+="0"; p1=1;} else
                {
                    t1+="0";
                    t2+="1";
                }
        } else
        if (s[j]=='2')
        {
            if (p1==0) {t1+="1"; t2+="1";} else
                {
                    t1+="0";
                    t2+="2";
                }
        }
    }
    cout<<t1<<"\n"<<t2<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while (t--) up();
}