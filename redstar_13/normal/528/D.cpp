#include <bits/stdc++.h>

using namespace std;
typedef long long INT;
typedef double DO;
typedef pair<int, int> pii;
typedef vector<int> VI;

#define NN 202020

char S[NN], T[NN];

namespace fft {
	const int mod=998244353;
	const int root=31;
	const int root_1=128805723;
	const int root_pw=1<<23;
	int mPow(int a, int x) {
		int ret=1;
		while (x>0) {
			if (x & 1) ret=1LL*ret*a%mod;
			a=1LL*a*a%mod;
			x>>=1;
		}
		return ret;
	}
	void fft(vector<int>& a, bool invert) {
		int n=a.size();
		int PW=invert?root_1:root;
		for (int i=n; i<root_pw; i<<=1) PW=1LL*PW*PW%mod;
	    for (int m=n, h; h=m/2, m>=2; PW=1LL*PW*PW%mod, m=h) {
            for (int i=0, w=1; i<h; ++i, w=1LL*w*PW%mod)
            for (int j=i; j<n; j+=m) {
                int k=j+h, x=(a[j]-a[k]+mod)%mod;
                a[j]+=a[k]; a[j] %= mod;
                a[k]=1LL*w*x%mod;
            }
        }
        for (int i=0, j=1; j<n-1; ++j) {
            for (int k=n/2; k>(i^=k); k /= 2);
            if (j<i) swap(a[i], a[j]);
        }
		if (invert) {
			int rev=mPow(n, mod-2);
			for (int i=0; i<n; ++i)
				a[i]=1LL*a[i]*rev%mod;
		}
	}
	vector<int> multiply(const vector<int>& a, const vector<int>& b) {
		int N=1, n=a.size()+b.size()-1;
		while (N<n) N<<=1;
		vector<int> na=a, nb=b;
		na.resize(N); nb.resize(N);
		fft(na, false); fft(nb, false);
		for (int i=0; i<N; ++i) na[i]=1LL*na[i]*nb[i]%mod;
		fft(na, true);
		na.resize(n);
		return na;
	}
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif

    int n, m, k;
    cin>>n>>m>>k>>S>>T;

    char s[]="ACGT";
    VI ans(n-m+1, 0);
    for (int i=0; i<4; i++) {
        VI a(m);
        int cnt=0;
        for (int j=0; j<m; j++) cnt+=(a[m-1-j]=s[i]==T[j]);
        VI b(n), c(n);
        for (int j=0; j<n; j++) c[j]=s[i]==S[j];
        int pre=-1;
        for (int j=0; j<n; j++) {
            if (c[j]) pre=j;
            if (pre!=-1 && j-pre<=k) b[j]=1;
        }
        pre=-1;
        for (int j=n-1; j>=0; j--) {
            if (c[j]) pre=j;
            if (pre!=-1 && pre-j<=k) b[j]=1;
        }
        a=fft::multiply(a, b);
        for (int j=m-1; j<n; j++) if (cnt==a[j]) ans[j-m+1]++;
    }
    cout << count(ans.begin(), ans.end(), 4) << endl;

    return 0;
}