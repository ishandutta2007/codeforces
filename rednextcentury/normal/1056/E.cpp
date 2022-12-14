#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct Hash {
	ll SEED = 1331;
	ll MOD = 1000000007;
	vector<ll> ha;
	vector<ll> power;
	Hash(string x) {
		ha = vector<ll>(x.size());
		power = vector<ll>(x.size());
		build(x);
	}
	void build(string x) {
		power[0] = 1;
		for(int i=1; i<(int)power.size(); i++) power[i] = (power[i-1] * SEED)%MOD;
		ha[0] = x[0];
		for(int i=1; i<(int)ha.size(); i++) ha[i] = (ha[i-1] * SEED + x[i])%MOD;
	}
	//i,j inclusive
	ll get(int i, int j) {
		ll ret = ha[j];
		if (i) ret -= ha[i-1] * power[j - i + 1];
		ret = (ret % MOD + MOD) % MOD;
		return ret;
	}
};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s,t;
    cin>>s>>t;
    Hash H(t);
    int zero=0,one=0;
    for (int i=0;i<s.size();i++)
    {
        if (s[i]=='0')zero++;
        else one++;
    }
    if (zero>one)
    {
        swap(one,zero);
        for (int i=0;i<s.size();i++)
            s[i]='1'-s[i]+'0';
    }
    int ret=0;
    for (int i=0;i<t.size();i++)
    {
        int L1=-1,R1=-1;
        int L2=-1,R2=-1;
        int left = t.size();
        left -= (i+1)*one;
        if (left<0)break;
        if (left%zero!=0)continue;
        int l1 = (i+1);
        int l2 = left/zero;
        if (l2==0)break;
        bool ok=1;
        int cur=0;
        for (int j=0;j<s.size();j++)
        {
            if (s[j]=='0')
            {
                int L = cur, R = cur+l2-1;
                cur=cur+l2;
                if (L1==-1)L1=L,R1=R;
                else if (H.get(L1,R1)!=H.get(L,R))
                {
                    ok=0;
                    break;
                }
            }
            else
            {
                int L = cur, R = cur+l1-1;
                cur+=l1;
                if (L2==-1)L2=L,R2=R;
                else if (H.get(L2,R2)!=H.get(L,R))
                {
                    ok=0;
                    break;
                }
            }
        }
        if (L1!=-1 && L2!=-1)
            if (H.get(L2,R2)==H.get(L1,R1))
                ok=0;
        if (ok)ret++;
    }
    cout<<ret<<endl;
}