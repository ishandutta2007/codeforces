#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long LL;
const LL N = 4000000 + 10;
LL n;     LL ans = 0;
LL x[N]; char s[2];
LL mx_[N];
vector<LL> R,B,P;
LL max(LL x, LL y) {return x > y ? x : y;}
void cac(vector<LL> A, vector<LL> B) {
    LL ret = 0;
    if (B.size()) {
    if (A[0] > B[0]) ans += A[0]-B[0]; 
    if (B[B.size()-1]>A[A.size()-1]) ans += B[B.size()-1]-A[A.size()-1];
}
    for (LL i = 0; i < A.size()-1; i ++) {
        // solve [ A[i], A[i+1] ]

        vector<LL> tmp; 
        
        tmp.push_back(A[i]); 
        LL p1 = lower_bound(B.begin(), B.end(), A[i]) - B.begin();
        LL p2 = lower_bound(B.begin(), B.end(), A[i+1]) - B.begin() - 1;
        for (LL j = p1; j <= p2; j ++) 
            if (A[i]<= B[j] && B[j]<=A[i+1])
                tmp.push_back(B[j]);
        
        tmp.push_back(A[i+1]);

        LL mx=0;
        for (LL j=0;j<tmp.size()-1;j++) {
            mx = max(mx, tmp[j+1]-tmp[j]);
        }
        //printf("%lld\n", mx);
        mx_[i] += mx;
    }
}
int main() {
    scanf("%lld", &n);
    for (LL i = 1; i <= n; i ++) {
        scanf("%lld %s", &x[i], s);
        if (s[0]=='P') P.push_back(x[i]);
        if (s[0]=='R') R.push_back(x[i]);
        if (s[0]=='B') B.push_back(x[i]);
    }
    
    if (P.size() <= 1) {
        if (P.size() == 1) {
            R.push_back(P[0]); sort(R.begin(), R.end());
            B.push_back(P[0]); sort(B.begin(), B.end());
        }
        if (R.size()) ans += R[R.size()-1]-R[0];
        if (B.size()) ans += B[B.size()-1]-B[0];
        return !printf("%lld\n", ans);
    }
    cac(P, R); cac(P, B);
    for (int i = 0; i < P.size()-1; i ++) {
        LL D = P[i+1]-P[i];
        ans += min(3*D-mx_[i], 2*D);
    }
    cout << ans << endl;
}