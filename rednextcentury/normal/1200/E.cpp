#include <bits/stdc++.h>
using namespace std;
#define ll long long
int MX = 1000005;
ll ha[2000000][2];
ll power[2000000][2];
struct Hash {
	ll SEED;
	ll MOD;
	int len=0;
	int num;
	Hash(ll seed,ll mod,int NUM) {
	    len=0;
	    num=NUM;
	    SEED = seed, MOD=mod;
        power[0][num]=1;
        for (int i=1;i<=MX;i++)
            power[i][num] = (power[i-1][num] * SEED)%MOD;

	}
    void Add(char x)
    {
        if (len==0)
            ha[0][num]=x;
        else
            ha[len][num] = (ha[len-1][num] * SEED + x)%MOD;
        len++;
    }
	//i,j inclusive
	ll get(int i, int j) {
		ll ret = ha[j][num];
		if (i) ret -= ha[i-1][num] * power[j - i + 1][num];
		ret = (ret % MOD + MOD) % MOD;
		return ret;
	}
	ll getLast(int x) {
        int l = len - x;
        int r = len - 1;
        return get(l,r);
	}
};
long long mod1=1000000007;
long long mod2=1000000009;
long long seed1=1337;
long long seed2=1007;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    Hash h1(1337,1000000007,0);
    Hash h2(1007,1000000009,1);
    string cur="";
    for (int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        long long H1=s[0],H2=s[0];
        int mx=0;
        if (h1.getLast(1)==H1 && h2.getLast(1)==H2)
            mx=1;
        for (int j=1;j<s.size();j++)
        {
            if (j >= h1.len)break;
            H1=(H1*seed1 +s[j])%mod1;
            H2=(H2*seed2 +s[j])%mod2;
            if (h1.getLast(j+1)==H1 && h2.getLast(j+1)==H2)
                mx=j+1;
        }
        for (int j=mx;j<s.size();j++)
            h1.Add(s[j]),h2.Add(s[j]),cur+=s[j];
    }
    cout<<cur<<endl;

}