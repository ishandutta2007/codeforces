#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool check(int len, ll k){
    int num = len / 10;
    int extra = len%10;
    ll ret=1;
    for (int i=0;i<10;i++){
        ll mult = num;
        if (i<extra) mult++;
        if (k/mult < ret) return 1;
        ret = ret*mult;
    }
    return ret>=k;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll k;
    cin>>k;
    int ret=-1;
    int l=10,r=400;
    while(l<=r){
        int mid = (l+r)/2;
        if (check(mid, k)) ret=mid, r=mid-1;
        else l=mid+1;
    }
    int num=ret/10;
    int extra = ret%10;
    string ans="";
    string s="codeforces";
    for (int i=0;i<10;i++){
        int mult = num;
        if (extra){
            extra--;
            mult++;
        }
        while(mult--)cout<<s[i];
    }
    cout<<endl;
}