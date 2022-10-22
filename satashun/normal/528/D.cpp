#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()
 
typedef double Num;
const Num PI = acos(-1.0);
typedef complex<Num> Complex;

void fft_main(int n, Num theta, Complex a[])
{
    for (int m = n; m >= 2; m >>= 1) {
        int mh = m >> 1;
        Complex thetaI = Complex(0, theta);
        rep(i, mh) {
            Complex w = exp((Num)i * thetaI);
            for (int j = i; j < n; j += m) {
                int k = j + mh;
                Complex x = a[j] - a[k];
                a[j] += a[k];
                a[k] = w * x;
            }
        }
        theta *= 2;
    }

    int i = 0;
    for (int j = 1; j < n - 1; ++j) {
        for (int k = n >> 1; k > (i ^= k); k >>= 1) ;
        if (j < i) swap(a[i], a[j]);
    }
}
 
void fft(int n, Complex a[]) { fft_main(n, 2 * PI / n, a); }
void inverse_fft(int n, Complex a[]) { fft_main(n, -2 * PI / n, a); }
 
void convolution(vector<Complex> &v, vector<Complex> &w)
{
    int n = 1, vwn = v.size() + w.size() - 1;
    while (n < vwn) n <<= 1;
    v.resize(n), w.resize(n);
    fft(n, &v[0]);
    fft(n, &w[0]);
    rep(i, n) v[i] *= w[i];
    inverse_fft(n, &v[0]);
    rep(i, n) v[i] /= n;
}
 
string S, T;
int w;
int l1, l2;
int imos[200010];
int ok[200010];

const string gen = "AGCT";

int main() {
    cin >> l1 >> l2 >> w;
    cin >> S >> T;
    reverse(ALL(T));

    for (char c : gen) {
	memset(imos, 0, sizeof(imos));

	rep(i, l1) {
	    if (S[i] == c) {
		int l = max(i - w, 0);
		int r = min(i + w + 1, l1);
		++imos[l];
		--imos[r];
	    }
	}

	vector<Complex> v1, v2;

	rep(i, l1) {
	    imos[i + 1] += imos[i];
	    int f = !!imos[i];
	    v1.pb(f);
	}

	int num = 0;

	rep(i, l2) {
	    int f = T[i] == c;
	    v2.pb(f);
	    num += f;
	}
	convolution(v1, v2);

	for (int i = 0; i <= l1 - l2; ++i) {
	    ok[i] += (int)(v1[i + l2 - 1].real() + 0.5) == num;
	}
    }

    int ret = 0;

    for (int i = 0; i <= l1 - l2; ++i) {
	ret += (ok[i] == 4);
    }

    cout << ret << endl;

    return 0;
}