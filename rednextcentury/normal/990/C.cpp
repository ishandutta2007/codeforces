#include<bits/stdc++.h>
using namespace std;
#define ll long long
map<int,ll> neg;
map<int,ll> pos;
ll balanced;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for (int i=0;i<n;i++) {
        string s;
        cin>>s;
        int sum=0,mn=0;
        int s2=0,mn2=0;
        for (auto x:s) {
            if (x=='(')sum++;
            else sum--;
            mn=min(mn,sum);
        }
        for (int j=s.size()-1;j>=0;j--){
            if (s[j]=='(')s2--;
            else s2++;
            mn2=min(mn2,s2);
        }
        if (mn<0 && mn2<0)continue;
        if (mn<0)neg[-mn]++;
        else if (mn2<0)pos[-mn2]++;
        else balanced++;
    }
    ll ret = balanced*balanced;
    for (auto x:neg) {
        ret+=x.second*pos[x.first];
    }
    cout<<ret<<endl;
}