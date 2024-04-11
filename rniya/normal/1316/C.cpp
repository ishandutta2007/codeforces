#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m,p; cin >> n >> m >> p;
    vector<int> a(n),b(m);
    for (int i=0;i<n;++i) cin >> a[i];
    for (int i=0;i<m;++i) cin >> b[i];
    int A,B;
    for (int i=n-1;i>=0;--i) if (a[i]%p!=0) A=i;
    for (int i=m-1;i>=0;--i) if (b[i]%p!=0) B=i;
    cout << A+B << '\n';
}