#include <bits/stdc++.h>
using namespace std;

namespace io{
	const int L=1000000;
	char ibuf[L],obuf[L],*iS,*iT,*oS=obuf,*oT=obuf+L;
	#define gc() (iS==iT?iT=(iS=ibuf)+fread(ibuf,1,L,stdin):0,iS==iT?EOF:*iS++)
	template<class T>void gi(T &x){
		int f=1,c;while((c=gc())<'0'||c>'9')if(c=='-')f=-f;
		for(x=0;c>='0'&&c<='9';c=gc())x=x*10+c-'0';x*=f;
	}
	void flush(){fwrite(obuf,oS-obuf,1,stdout);}
	void pc(char c){*oS++=c;if(oS==oT)flush(),oS=obuf;}
	template<class T>void pi(T &x){if(x<0)pc('-'),x=-x;if(x>9)pi(x/10);pc(x%10+'0');}
	struct F{~F(){flush();}}f;
};
using io::gi;
using io::pc;
using io::pi;

typedef long long ll;
const int N = 2005;
int n, k, w[N][N], d[N];

int main() {
	gi(n), gi(k);
	ll sum = 0;
	if (k == 1 || k == n - 1) {
		for (int i = 1, x; i <= n * (n - 1) / 2; i++) {
			gi(x);
			if (x != -1) sum += x;
		}
		cout << sum * 2 / n << endl;
	} else {
		for (int i = 1; i < n; i++)
			for (int j = i + 1; j <= n; j++) {
				gi(w[i][j]);
				if (w[i][j] != -1) d[i]++, d[j]++;
			}
		for (int i = 1; i < n; i++)
			for (int j = i + 1; j <= n; j++)
				if (w[i][j] != -1)
					sum += (d[i] + d[j] - 2ll) * w[i][j];
		sum /= n * (n - 1) / 2;
		cout << sum << endl;
	}
	return 0;
}