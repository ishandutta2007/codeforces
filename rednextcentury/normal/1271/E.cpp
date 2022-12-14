#include<bits/stdc++.h>
using namespace std;
#define ll long long
string s;
string k;
pair<ll,ll> dp[101][200][2];
ll K;
void toBin(ll x) {
    k="";
    while(x){
        k+=char('0'+(x%2));
        x/=2;
    }
    reverse(k.begin(),k.end());
}
pair<ll,ll> operator+(pair<ll,ll> A, pair<ll,ll> B){
    return {A.first+B.first, A.second+B.second};
}
int T;
int vis[201][201][2];
pair<ll,ll> DP(int i,int j,int eq){
    if (vis[i][j+1][eq]==T)
        return dp[i][j+1][eq];
    if (j==(int)k.size())
        return dp[i][j+1][eq] = {DP(i,-1,eq).first,DP(i,-1,eq).first+DP(i,-1,eq).second};
    if (i==s.size())
        return {1,0};
    vis[i][j+1][eq]=T;
    char lim = '1';
    if (eq && s[i]=='0'){
        lim='0';
    }
    pair<ll,ll> ret = {0,0};
    for (char x='0';x<=lim;x++) {
        int newEq = eq && (x==s[i]);
        if (j!=-1 && x==k[j]) ret=ret+DP(i+1,j+1,newEq);
        else {
            if (x=='0') {
                if (j==0)
                    ret = ret + DP(i + 1, min(0, j), newEq);
                else
                    ret = ret + DP(i + 1, -1, newEq);
 
            }
            else {
                ret = ret + DP(i + 1, -1, newEq);
            }
        }
    }
    return dp[i][j+1][eq] = ret;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll ret=0;
    ll n;
    cin>>n>>K;
    toBin(n);s=k;
    ll l=0,r=n;
    while(l<=r){
        ll sum=0;
        ll mid = (l+r)/2;
        ll cm = mid*2+1;
        T++;
        toBin(cm);
        sum = DP(0,0,1).second;
        if (sum>=K)ret=mid,l=mid+1;
        else r=mid-1;
    }
    ll ans = ret*2+1;
    l=1,r=n;
    while(l<=r){
        ll sum=0;
        ll mid = (l+r)/2;
        ll cm = mid*2;
        toBin(cm);
        T++;
        sum = DP(0,0,1).second;
        if (k.back()=='0'){
            k[k.size()-1]='1';
            T++;
            sum += DP(0,0,1).second;
        }
        if (sum>=K)ret=mid,l=mid+1;
        else r=mid-1;
    }
    ans = max(ans,ret*2);
    cout<<ans<<endl;
}