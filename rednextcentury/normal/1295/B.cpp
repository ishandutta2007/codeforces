#include<bits/stdc++.h>
using namespace std;
#define ll long long
//#define mid (l+r)/2
//#define L (x<<1)
//#define R (L+1)

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        ll n,x;
        cin>>n>>x;
        string s;
        cin>>s;
        ll change=0;
        for (int i=0;i<s.size();i++) {
            if (s[i]=='1')change--;
            else change++;
        }
        ll balance=0;
        bool inf=0;
        ll ret=0;
        for (int i=0;i<s.size();i++) {
            if (s[i]=='1')balance--;
            else balance++;
            if (balance==x && change==0){
                inf = 1;
            } else if (change!=0){
                ll need = (x-balance)/change;
                if (need<0)continue;
                if (balance+need*change == x)ret++;
            } else if (balance==x)ret++;
        }
        if (x==0)ret++;
        if (inf)ret=-1;
        cout<<ret<<endl;
    }
}