#pragma G++ optimize("Ofast")
#pragma G++ optimize("unroll-loops")
#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<functional>
#include<queue>
#include<unordered_map>
#include<map>
#include<set>
#include<stack>
#include<cmath>
#include<bitset>
#include<iomanip>
#include<numeric>
#define rep(i,l,r) for(int i=l;i<=r;++i)
using namespace std;
#define ll long long 
const int N = 50007, P = 998244353;
int n, m;
//ll primes[N], cnt_primes;
//int cnt;
//bool vis[N];
const int maxn =2e6+1;
char ss[maxn];
ll f[maxn],qq[maxn],val[maxn];

void add(int &x, int y) {
    (x += y) >= P && (x -= P);
}
void sub(int &x, int y) {
    (x -= y) < 0 && (x += P);
}
struct FWT {
    int extend(int n) {
        int N = 1;
        for (; N < n; N <<= 1);
        return N;
    }
    void FWTor( vector<int> &a, bool rev) {
        int n = a.size();
        for (int l = 2, m = 1; l <= n; l <<= 1, m <<= 1) {
            for (int j = 0; j < n; j += l) for (int i = 0; i < m; i++) {
                if (!rev) add(a[i + j + m], a[i + j]);
                else sub(a[i + j + m], a[i + j]);
            }
        }
    }
    void FWTand( vector<int> &a, bool rev) {
        int n = a.size();
        for (int l = 2, m = 1; l <= n; l <<= 1, m <<= 1) {
            for (int j = 0; j < n; j += l) for (int i = 0; i < m; i++) {
                if (!rev) add(a[i + j], a[i + j + m]);
                else sub(a[i + j], a[i + j + m]);
            }
        }
    }
    void FWTxor( vector<int> &a, bool rev) {
        int n = a.size(), inv2 = (P + 1) >> 1;
        for (int l = 2, m = 1; l <= n; l <<= 1, m <<= 1) {
            for (int j = 0; j < n; j += l) for (int i = 0; i < m; i++) {
                int x = a[i + j], y = a[i + j + m];
                if (!rev) {
                    a[i + j] = (x + y) % P;
                    a[i + j + m] = (x - y + P) % P;
                } else {
                    a[i + j] = 1LL * (x + y) * inv2 % P;
                    a[i + j + m] = 1LL * (x - y + P) * inv2 % P;
                }
            }
        }
    }
    vector<int> Or(vector<int> a1, vector<int> a2) {
        int n = max(a1.size(), a2.size()), N = extend(n);
        a1.resize(N), FWTor(a1, false);
        a2.resize(N), FWTor(a2, false);
        vector<int> A(N);
        for (int i = 0; i < N; i++) A[i] = 1LL * a1[i] * a2[i] % P;
        FWTor(A, true);
        return A;
    }
    vector<int> And(vector<int> a1, vector<int> a2) {
        int n =  max(a1.size(), a2.size()), N = extend(n);
        a1.resize(N), FWTand(a1, false);
        a2.resize(N), FWTand(a2, false);
        vector<int> A(N);
        for (int i = 0; i < N; i++) A[i] = 1LL * a1[i] * a2[i] % P;
        FWTand(A, true);
        return A;
    }
     vector<int> Xor(vector<int> a1, vector<int> a2) {
        int n = max(a1.size(), a2.size()), N = extend(n);
        a1.resize(N), FWTxor(a1, false);
        a2.resize(N), FWTxor(a2, false);
        vector<int> A(N);
        for (int i = 0; i < N; i++) A[i] = 1LL * a1[i] * a2[i] % P;
        FWTxor(A, true);
        return A;
    }
} fwt;
//    scanf("%d", &m);
//    n = 1 << m;
//    vector<int> a1(n), a2(n);
//    for (int i = 0; i < n; i++) scanf("%d", &a1[i]);
//    for (int i = 0; i < n; i++) scanf("%d", &a2[i]);
//    vector<int> A;
//    A = fwt.Or(a1, a2);
//    for (int i = 0; i < n; i++) {
//        printf("%d%c", A[i], " \n"[i == n - 1]);
//    }
//    A = fwt.And(a1, a2);
//    for (int i = 0; i < n; i++) {
//        printf("%d%c", A[i], " \n"[i == n - 1]);
//    }
//   A = fwt.Xor(a1, a2);
//    for (int i = 0; i < n; i++) {
//        printf("%d%c", A[i], " \n"[i == n - 1]);
//    }

solve()
{
	cin>>n>>m;	
	vector<int> a(maxn),b(maxn) ;
	for(int i = 1; i <= n; ++ i) {
        cin>>ss+1;
        for(int j = 1; j <= m; ++ j) {
            if(ss[j] == '1')
                qq[j] |= 1 << i - 1;
        }//S 
    }
	rep(i,1,m) a[qq[i]]++;
	for(int i=0;i<(1<<20);++i)
		val[i]=val[i>>1] + (i & 1);
	for(int i=0;i<(1<<20);++i)
		b[i]=min(val[i], n-val[i]);
	vector<int> A;
 	A = fwt.Xor(a, b);
	int ans=2e6;
	for(int i=0;i<(1<<n);++i)	
		ans=min(ans,A[i]);
	cout<<ans<<"\n";


}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t=1;
	//cin>>t;
	while(t--)solve();
	return 0;
}